#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 칸으로 이루어진 게임판이 있다. 1번째 칸에서 1에서 6까지 쓰인 주사위를 굴려서
N번째 칸으로 이동하면 된다. 각 칸에는 이동해야 할 칸 수인 정수가 쓰여 있다.
0인 경우 그대로 있고, 수가 쓰인 경우 그 수만큼 앞으로 간다.(음수인 경우 절댓값만큼 뒤로 이동)
도착해서 나온 칸에 수가 쓰여있다면 이를 반복한다. 이 과정에서 무한 반복이 생기는 경우 실패한 것이다.
이때, N번째 칸에 도착하기 위해 주사위를 굴려야 하는 횟수의 최솟값을 구한다.
각 칸에서 게임판 밖으로 이동하는 경우는 없으며, N번째 칸에 도달할 수 있는 경우만 주어진다.

해결 방법 : 우선 각 칸에서 도달하게 되는 칸들을 모두 구한다. 이는 DFS를 통해 구할 수 있다.
각 방문하지 않은 칸마다 DFS를 통해 이미 방문한 칸이 나올 때 까지 반복한다.
이미 방문한 칸의 도달하는 칸을 아는 경우 그 칸으로 DFS 과정에 있는 칸들의 목적지를 설정하고,
모른다면 무한 반복이 생긴 것이므로 해당 과정의 칸들에 대해 체크해둔다. 자기 자신으로 돌아온다면
해당 칸이 목적지가 된다.

그 다음으로는 BFS를 통해 1번 칸에서 N번 칸까지 이동하는 최소 횟수를 구하면 된다.

주요 알고리즘 : 그래프 이론, DFS, BFS

출처 : JAG 2010S2 C번
*/

int mv[103000], dest[103000], vis[103000], dist[103000];
queue<int> q;

int dfs(int x) {
    vis[x] = 1;
    if (!vis[x + mv[x]]) dest[x] = dfs(x + mv[x]);
    else {
        if (mv[x] == 0) dest[x] = x;
        else if (dest[x + mv[x]]) dest[x] = dest[x + mv[x]];
        else dest[x] = -1;
    }
    return dest[x];
}

int bfs(int x, int n) {
    for (int i = 1; i <= n; i++) vis[i] = 0;
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        if (x == n) return dist[x];
        for (int i = 1; i <= 6; i++) {
            if (dest[x + i] >= 1 && !vis[dest[x + i]]) {
                q.push(dest[x + i]);
                vis[dest[x + i]] = 1;
                dist[dest[x + i]] = dist[x] + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mv[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    r = bfs(1, n);
    while (r < 0);
    printf("%d\n", r);
    return 0;
}