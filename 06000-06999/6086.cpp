#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 700)개의 양방향 간선으로 이루어진 그래프가 있다. 이 그래프의 정점은 알파벳 대소문자 한 글자로 주어진다.
이때, 'A'에서 'Z'로 향하는 최대 유량을 구한다. 각 간선의 용량은 1000 이하의 자연수이다.

해결 방법 : 에드몬드-카프 알고리즘을 통해 유량을 구할 수 있다.

주요 알고리즘 : 그래프 이론, 최대 유량

출처 : USACO 2009J S2번
*/

int cap[128][128], usg[128][128], prv[128];
vector<char> ed[128];
queue<int> q;

int main(void) {
    //Edmonds-Karp 알고리즘을 이용한 최대 유량
    int n, w, l, r = 0;
    char x, s, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %c %d", &s, &e, &w);
        ed[s].push_back(e);
        ed[e].push_back(s); //역방향 간선도 추가할 것
        cap[s][e] += w;
        cap[e][s] += w;
    }

    while (1) {
        //Z에 도달 가능할 때 까지 유량 추가
        while (q.size()) q.pop();
        q.push('A');
        for (int i = 0; i < 128; i++) prv[i] = -1; //경로 복원을 위한 배열
        while (q.size() && prv['Z'] < 0) {
            x = q.front();
            q.pop();
            for (char i : ed[x]) {
                if (cap[x][i] > usg[x][i] && prv[i] < 0) {
                    //해당 간선으로 유량 추가가 가능한 경우
                    q.push(i);
                    prv[i] = x;
                    if (i == 'Z') break; //Z에 도달시 종료
                }
            }
        }
        if (prv['Z'] < 0) break;
        l = INF;
        for (char now = 'Z'; now != 'A'; now = prv[now]) {
            if (cap[prv[now]][now] - usg[prv[now]][now] < l) l = cap[prv[now]][now] - usg[prv[now]][now];
            //경로 역추적을 통한 경로의 유량 최솟값 찾기
        }
        for (char now = 'Z'; now != 'A'; now = prv[now]) {
            usg[prv[now]][now] += l;
            usg[now][prv[now]] -= l; //역방향으로는 유량을 역으로 추가
        }
        r += l;
    }
    printf("%d", r);
    return 0;
}