#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 15)개의 비트로 이루어진 값이 2개 주어진다. 이때, 첫 번째 값에서 두 번째 값
또는 그의 반대 값을 만들기 위해 인접한 비트의 순서를 바꾸는 연산이 최소 몇 회 필요한 지 구한다.
둘 중 한 값을 만들 수 있음이 보장된다.

해결 방법 : 비트마스킹을 통해 값들을 수로 바꾼 후, 인접한 비트의 순서를 각각 바꾸면서
BFS를 진행한다. 비트 연산을 적절히 활용한다. BFS가 끝나면 둘 중 최소 하나는 방문이 되어 있을 것이다.
방문이 된 것 중 더 거리가 작은 것을 고르면 답이 된다.

주요 알고리즘 : 그래프 이론, BFS, 비트마스킹

출처 : Tokyo 2014 A번
*/

int vis[32768], dist[32768], bit[16];
queue<int> q;

int small(int a, int b) {
    return a < b ? a : b;
}

void bfs(int n, int x) {
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 1; i < n; i++) {
            if (((x >> i) & 1) ^ ((x >> (i - 1)) & 1)) {
                if (!vis[x ^ (1 << i) ^ (1 << (i - 1))]) {
                    vis[x ^ (1 << i) ^ (1 << (i - 1))] = 1;
                    dist[x ^ (1 << i) ^ (1 << (i - 1))] = dist[x] + 1;
                    q.push(x ^ (1 << i) ^ (1 << (i - 1)));
                }
            }
        }
    }
}

int main(void) {
    int n, m, x = 0, y, z = 0, p = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bit[i]);
        x += (bit[i] << i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &y);
        for (int j = 0; j < y; j++) z += ((i & 1) << (p++));
    }
    bfs(n, x);
    if (!vis[z] && !vis[(1 << n) - z - 1]) return 1;
    printf("%d\n", small(vis[z] ? dist[z] : INF,
        vis[(1 << n) - z - 1] ? dist[(1 << n) - z - 1] : INF));
    return 0;
}