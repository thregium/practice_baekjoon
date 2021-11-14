#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : 정점 N(N <= 3000)개의 사이클이 1개 있는 그래프가 주어진다. 각 정점에서 사이클까지의 거리를 구한다.

해결 방법 : DFS를 통해 사이클에 속하는 정점들을 찾아낸 다음, 그 정점들로 BFS를 하여 사이클까지의 거리를 구하면 된다.

주요 알고리즘 : 그래프 이론, DFS, BFS, 트리
*/

int cy = 0, chk[3200], vis[3200], dist[3200];
vector<int> ed[3200];
queue<int> q;

void track(int x, int l) {
    chk[x] = 1;
    for (int i : ed[x]) {
        if (i == l) continue; //직전 정점인 경우 무시
        if (chk[i]) {
            cy = i; //사이클의 시점 확인, 0으로 처리하지 않는 구간
            return;
        }
        track(i, x);
        if (cy) {
            if (x == cy) cy = 0; //사이클의 종점 확인, 이후로는 0으로 처리
            return;
        }
    }
    chk[x] = 0;
}

void bfs(void) {
    int x;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            dist[i] = dist[x] + 1;
            q.push(i);
        }
    }
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    track(1, -1);
    for (int i = 1; i <= n; i++) {
        if (chk[i]) {
            q.push(i);
            vis[i] = 1;
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    return 0;
}