#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 300)개의 정점과 M(M <= 5000)개의 간선으로 이루어진 그래프에서 1번 정점부터 N번 정점까지 이동하며
그래프의 값 가운데 1을 지운다. 그래프의 값이 1 이상인 간선만 이동 가능하다. 이때, 이동 가능한 최대 횟수를 구한다.

해결 방법 : 1번 정점에서 N번 정점까지의 최대 유량을 구하면 된다.

주요 알고리즘 : 그래프 이론, 플로우

출처 : UCPC 2018예 PC번
*/

int cap[512][512], usg[512][512], prv[512];
vector<int> ed[512];
queue<int> q;

int main(void) {
    //Edmonds-Karp 알고리즘을 이용한 최대 유량
    int n, p, w, l, r = 0;
    int x, s, e;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < p; i++) {
        scanf("%d %d %d", &s, &e, &w);
        ed[s].push_back(e);
        ed[e].push_back(s); //역방향 간선도 추가할 것
        cap[s][e] += w;
        cap[e][s] += w;
    }

    while (1) {
        //n에 도달 가능할 때 까지 유량 추가
        while (q.size()) q.pop();
        q.push(1);
        for (int i = 0; i < 512; i++) prv[i] = -1; //경로 복원을 위한 배열
        while (q.size() && prv[n] < 0) {
            x = q.front();
            q.pop();
            for (int i : ed[x]) {
                if (cap[x][i] > usg[x][i] && prv[i] < 0) {
                    //해당 간선으로 유량 추가가 가능한 경우
                    q.push(i);
                    prv[i] = x;
                    if (i == n) break; //n에 도달시 종료
                }
            }
        }
        if (prv[n] < 0) break;
        l = INF;
        for (int now = n; now != 1; now = prv[now]) {
            if (cap[prv[now]][now] - usg[prv[now]][now] < l) l = cap[prv[now]][now] - usg[prv[now]][now];
            //경로 역추적을 통한 경로의 유량 최솟값 찾기
        }
        for (int now = n; now != 1; now = prv[now]) {
            usg[prv[now]][now] += l;
            usg[now][prv[now]] -= l; //역방향으로는 유량을 역으로 추가
        }
        r += l;
    }
    printf("%d", r);
    return 0;
}