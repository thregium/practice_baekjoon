#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 3 * 3 크기의 칸들에 0부터 3까지의 수가 쓰여 있다. 각 칸을 누르면 같은 행과 열의 수들이
1씩 증가(3인 경우엔 0으로 변화)한다고 할 때, 모든 칸의 값을 0으로 바꿀 수 있는 지 구하고,
가능한 경우 누르는 최소 횟수를 구한다.

해결 방법 : 각 칸들의 모든 상태는 많아야 4^9 = 262144가지이므로 BFS를 쓸 수 있다.
특히 4는 2의 거듭제곱 꼴이므로 비트마스킹을 이용할 수 있다.

주요 알고리즘 : 그래프 이론, BFS

출처 : VTH 2015 D번
*/

int vis[262144], dist[262144];
queue<int> q;
int panelmv[9][5] = { {0, 1, 2, 3, 6}, {0, 1, 2, 4, 7}, {0, 1, 2, 5, 8}, {0, 3, 4, 5, 6},
    {1, 3, 4, 5, 7}, {2, 3, 4, 5, 8}, {0, 3, 6, 7, 8}, {1, 4, 6, 7, 8}, {2, 5, 6, 7, 8} };

void bfs(int p) {
    int t;
    q.push(p);
    vis[p] = 1;
    while (q.size()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 9; i++) {
            t = p;
            for (int j = 0; j < 5; j++) {
                t -= ((p >> (panelmv[i][j] * 2)) & 3) << (panelmv[i][j] * 2);
                t += ((((p >> (panelmv[i][j] * 2)) & 3) + 1) & 3) << (panelmv[i][j] * 2);
            }
            if (vis[t]) continue;
            vis[t] = 1;
            dist[t] = dist[p] + 1;
            q.push(t);
        }
    }
}

int main(void) {
    int x, p = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &x);
        p += x << (i << 1);
    }
    bfs(p);
    if (vis[0] == 0) printf("-1");
    else printf("%d", dist[0]);
    return 0;
}