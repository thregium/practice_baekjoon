#include <stdio.h>

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 트리에서 모든 정점 사이의 경로들에 대해 각 경로들 사이에 지나가는
모든 간선의 수를 각각 셀 때, 가장 많은 경로가 지나가는 간선을 지나가는 경로의 수를 구한다.

해결 방법 : 트리에서 각 간선을 지나가는 경로의 수는 해당 간선을 끊었을 때 생기는 두 트리 크기의 곱이다.
해당 간선을 끊었을 때 생기는 트리의 크기는 간단한 트리DP를 통해 구할 수 있다.
임의의 정점을 루트로 둔 다음, 각 정점에서는 해당 정점 이하의 모든 정점의 값을 더하고 1을 더하면 된다.
모든 크기를 구한 다음에는 트리의 크기 * (N - 트리의 크기)들 가운데 가장 큰 것을 고른다.

주요 알고리즘 : DP, 트리DP, 조합론

출처 : PA 2001 4-1번
*/

int mem[1024], vis[1024], tree[1024][1024];

int dp(int x) {
    int r = 1;
    vis[x] = 1;
    for (int i = 1; i <= tree[x][0]; i++) {
        if (vis[tree[x][i]]) continue;
        if (mem[tree[x][i]] == 0) r += dp(tree[x][i]);
        else r += mem[tree[x][i]];
    }
    return mem[x] = r;
}

int main(void) {
    int n, x, y, best = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        tree[x][++tree[x][0]] = y;
        tree[y][++tree[y][0]] = x;
    }
    dp(1);
    for (int i = 1; i <= n; i++) {
        if (mem[i] * (n - mem[i]) > best) best = mem[i] * (n - mem[i]);
    }
    printf("%d", best);
    return 0;
}