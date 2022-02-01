#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 100)개의 정점으로 이루어진 그래프에 M(M <= 16)개의 어두운 방이 있다.
또한, 각 방에서는 K(K < N)개의 번호가 매겨진 길들이 있고, 각 길들은 다시 방으로 연결된다.
이때, 모든 어두운 방에서 밝은 방으로 이동하기 위해 필요한 최소 이동 횟수를 구한다.
각 이동은 길 번호로 이동하게 되며 밝은 방에서는 더이상 이동하지 않는다. 모든 어두운 방에서는
밝은 방으로 이동하는 방법이 존재한다.

해결 방법 : 모든 어두운 방에서 출발하는 경우를 시작점으로 두고, 각 정점을 각 어두운 방마다
사람의 존재 가능성으로 둔다. 해당 정점에 사람이 존재할 수 있다면 1, 없다면 0으로 하여 비트마스킹한
형태로 저장된다. 방을 이동할 때 마다 사람이 존재할 수 있는 방들을 확인하고 비트마스킹하여
BFS를 한다. 모든 어두운 방에 사람이 없게 되는 지점까지의 최단거리가 답이 된다.

주요 알고리즘 : 그래프 이론, BFS, 비트마스킹

출처 : JAG 2015S2 D번
*/

int v[128][128], dark[128], mem[65536];
queue<int> q;

int small(int a, int b) {
    return a < b ? a : b;
}

int bfs(int x, int n, int m, int k) {
    int r = INF, t, cnt[128] = { 0, };
    q.push(x);
    mem[x] = 0;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                if ((x >> j) & 1) {
                    cnt[v[dark[j]][i]]++;
                }
            }
            t = 0;
            for (int j = 0; j < m; j++) {
                if (cnt[dark[j]]) t += (1 << j);
                cnt[dark[j]] = 0;
            }
            if (mem[t] < 0) {
                q.push(t);
                mem[t] = mem[x] + 1;
            }
        }
    }
    return mem[0];
}

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &dark[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    for (int i = 0; i < (1 << m); i++) mem[i] = -1;
    printf("%d\n", bfs((1 << m) - 1, n, m, k));
    return 0;
}