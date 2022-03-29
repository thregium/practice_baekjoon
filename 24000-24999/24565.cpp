#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : H * W(H, W <= 100) 크기의 격자에 조각들이 있다. 모든 맨 위 조각을 남기고 바닥이 아닌 모든 조각들은
아래에 받쳐주는 조각이 필요하다 할 때, 필요한 조각의 최소 개수를 구한다.
맨 위 조각은 많아야 2개뿐이다.

해결 방법 : 각 조각들을 정점으로 보고 위아래로 인접한 경우 위에서 아래로 향하는 간선을 그어준다.
바닥에 있는 조각들은 임의의 바닥 정점을 추가해 그 정점으로 간선을 이어주면 답은 맨 위에 있는 정점들에서
바닥 정점으로 향하는 최단 경로와 같다.

이는 맨 위 정점이 1개인 경우 단순 BFS로 풀 수 있으며,
2개인 경우에는 모든 경유점에 대해 두 맨 위 정점에서 경유점까지의 거리와 경유점에서 바닥 정점까지의
거리 가운데 최솟값을 구하면 된다. 경유점에서 바닥 정점까지의 거리를 구하기 어려우므로
간선을 뒤집고 바닥 정점에서 모든 점까지의 거리를 구하고 그 값을 사용하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : ECNA 2021 K번
*/

int piece[128][128], dist[3][10240], vis[10240], stt[8];
vector<int> ed[10240];
queue<int> q;

void bfs(int x, int dn) {
    for (int i = 0; i < 10240; i++) vis[i] = 0;
    q.push(x);
    vis[x] = 1;
    dist[dn][x] = 0;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                q.push(i);
                dist[dn][i] = dist[dn][x] + 1;
                vis[i] = 1;
            }
        }
    }
}

int main(void) {
    int h, w, ssz = 0, exi, res = 103000;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &piece[i][j]);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (piece[i][j] != piece[i + 1][j]) {
                ed[piece[i][j]].push_back(piece[i + 1][j]);
                //ed[piece[i + 1][j]].push_back(piece[i][j]);
            }
        }
    }
    for (int i = 0; i < w; i++) {
        exi = 0;
        for (int j = 0; j < ssz; j++) {
            if (piece[0][i] == stt[j]) exi = 1;
        }
        if (!exi) stt[ssz++] = piece[0][i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10240; j++) dist[i][j] = 103000;
    }
    for (int i = 1; i <= ssz; i++) {
        bfs(stt[i - 1], i);
    }
    for (int i = 0; i < 10240; i++) ed[i].clear();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (piece[i][j] != piece[i + 1][j]) {
                //ed[piece[i][j]].push_back(piece[i + 1][j]);
                ed[piece[i + 1][j]].push_back(piece[i][j]);
            }
        }
    }

    bfs(0, 0);
    if (ssz == 1) printf("%d", dist[1][0]);
    else {
        for (int i = 0; i < 10240; i++) {
            if (dist[0][i] + dist[1][i] + dist[2][i] < res) {
                res = dist[0][i] + dist[1][i] + dist[2][i];
            }
        }
        printf("%d", res);
    }
    return 0;
}