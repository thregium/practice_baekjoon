#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 1000)개의 서로 다른 길이 K(K <= 30)의 비트 집합이 있다. 이 집합에서 비트가 1개만 차이 나는 비트 집합끼리는
서로 이동이 가능하다면, 주어진 두 비트 사이의 최단거리를 구하고, 그 경로를 출력한다.

해결 방법 : 모든 비트 쌍에 대해 각각 비트의 차이를 확인하고 1인 경우 두 비트 집합 사이에 간선을 추가한다.
간선을 추가한 다음에는 출발 비트 집합에서 BFS를 한다. 도착점에 방문하지 못했다면 이동에 실패한 것이다.
도착점에 방문한 다음에는 도착점에서부터 거리가 1씩 줄어드는 경로를 찾아 출발점까지 돌아온 다음 경로를 역순으로 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS, 역추적, 구현

출처 : 정올 2010지 초5번
*/

int nxt[1024][1024], vis[1024], dist[1024], path[1024];
char s[1024][32];
queue<int> q;

int diff(char* a, char* b, int k) {
    int r = 0;
    for (int i = 0; i < k; i++) {
        r += (a[i] != b[i]);
    }
    return r;
}

void bfs(int a, int b) {
    q.push(a);
    vis[a] = 1;
    while (q.size()) {
        a = q.front();
        q.pop();
        for (int i = 1; i <= nxt[a][0]; i++) {
            if (vis[nxt[a][i]]) continue;
            q.push(nxt[a][i]);
            vis[nxt[a][i]] = 1;
            dist[nxt[a][i]] = dist[a] + 1;
        }
    }
}

int main(void) {
    int n, k, a, b;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (diff(s[i], s[j], k) == 1) {
                nxt[i][++nxt[i][0]] = j;
                nxt[j][++nxt[j][0]] = i;
            }
        }
    }
    scanf("%d %d", &a, &b);
    bfs(a, b);
    if (!vis[b]) {
        printf("-1");
        return 0;
    }
    path[dist[b]] = b;
    while (dist[b]) {
        for (int i = 1; i <= nxt[b][0]; i++) {
            if (dist[nxt[b][i]] == dist[b] - 1) {
                path[dist[b] - 1] = nxt[b][i];
                b = nxt[b][i];
                break;
            }
        }
    }
    for (int i = 0; path[i]; i++) {
        printf("%d ", path[i]);
    }
    return 0;
}