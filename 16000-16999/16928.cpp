#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 뱀과 사다리 게임에서 각 뱀, 사다리의 위치들이 주어질 때, 1에서 출발해 100에 도달하기 위해 필요한 주사위 던짐 횟수를 구한다.

해결 방법 : 주어진 정보로 각 칸에 도착했을 때 이동하는 위치를 미리 저장해둔다. 그 다음으로는 각 주사위 눈마다
이동하는 칸을 간선으로 보고 각 칸을 정점으로 본 다음 BFS를 통해 100에 도달하는 때를 구하면 된다.
100에 도달하면 바로 프로그램을 종료하도록 한다.

주요 알고리즘 : 그래프 이론, BFS
*/

int nxt[128], dist[128], vis[128];
queue<int> q;

int main(void) {
    int n, m, x, y;
    for (int i = 1; i <= 100; i++) nxt[i] = i;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++) {
        scanf("%d %d", &x, &y);
        nxt[x] = y;
    }
    q.push(1);
    vis[1] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            if (x + i == 100) {
                printf("%d", dist[x] + 1);
                return 0;
            }
            if (vis[nxt[x + i]]) continue;
            q.push(nxt[x + i]);
            vis[nxt[x + i]] = 1;
            dist[nxt[x + i]] = dist[x] + 1;
        }
    }
    return 0;
}