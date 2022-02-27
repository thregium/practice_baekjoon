#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 역과 각각 M(M <= 1000)개의 역이 있는 K(K <= 1000)개의 노선이 있다.
이때, 1번 역에서 N번 역으로 갈 수 있는 지 확인하고, 갈 수 있다면 내려야 하는 역의 최소 개수를 구한다.

해결 방법 : 각 노선을 정점으로, 환승 가능한 노선들 사이 관계를 간선으로 만든다.
이는 각 역마다 지나는 노선들을 동적 배열로 관리하면서 만나는 노선들에 간선을 전부 이으면
그래프를 만들어낼 수 있다. 그런 다음, 1번 역을 지나는 모든 노선에서 출발하여
N번 역을 지나는 모든 노선까지의 환승 횟수 가운데 최솟값 + 2를 구하면 된다.
단, N이 1인 경우는 답이 1임에 유의한다.

주요 알고리즘 : 그래프 이론, BFS

출처 : COCI 12/13#5 4번
*/

int vis[1024], dist[1024];
vector<int> sta[103000], ed[1024];
queue<int> q;

int main(void) {
    int n, k, m, x, r = 103000;
    scanf("%d %d %d", &n, &k, &m);
    if (n == 1) {
        printf("1");
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            for (int ii : sta[x]) {
                ed[ii].push_back(i);
                ed[i].push_back(ii);
            }
            sta[x].push_back(i);
        }
    }
    for (int i : sta[1]) {
        q.push(i);
        vis[i] = 1, dist[i] = 2;
    }
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
                dist[i] = dist[x] + 1;
            }
        }
    }
    for (int i : sta[n]) {
        if (vis[i] && dist[i] < r) r = dist[i];
    }
    printf("%d", r == 103000 ? -1 : r);
    return 0;
}