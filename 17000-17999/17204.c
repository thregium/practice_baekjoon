#include <stdio.h>

/*
문제 : N(N <= 150)명의 사람들이 The game of Death를 할 때, 0번 사람부터 시작해서 K번째 사람이 걸리는
최소의 M을 구한다. 불가능한 경우 -1을 출력한다.

해결 방법 : DFS?를 통해 각 사람이 처음 걸리는 M을 찾는다. 만약 이미 방문한 사람이 나왔지만 K번째 사람이 나오지 않는 경우
불가능한 경우이므로 -1을 출력하고, K번째 사람이 나왔다면 그 사람의 번호를 출력한다.

주요 알고리즘 : 구현, 그래프 이론

출처 : 중앙대 2019N D번
*/

int a[10240], vis[10240], dist[10240];

void dfs(int x) {
    vis[x] = 1;
    if (!vis[a[x]]) {
        dist[a[x]] = dist[x] + 1;
        dfs(a[x]);
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == 1) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    dfs(0);
    printf("%d\n", vis[k] ? dist[k] : -1);
    return 0;
}