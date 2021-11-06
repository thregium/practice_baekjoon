#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : 높이 H(1000 < H <= 30000)까지 올라가려고 한다. 중간 지점은 F(F <= 10000)개 있다.
각 지점들 사이는 거리가 1000 이하인 경우 서로 이동이 가능하다. 처음에는 1000 이하의 높이에 있는 지점에서 출발할 수 있고,
높이 H - 1000 이상의 지점에 도달하면 꼭대기에 올라갈 수 있을 때, 꼭대기에 올라가기 위해 지나가야 하는
지점의 최소 개수를 구한다. 단, 항상 꼭대기에 도착 가능한 경우만 주어진다.

해결 방법 : 각 지점의 좌표를 입력받은 후, 출발지로 가능한 지점들을 모두 구하고 피타고라스의 정리를 이용해
모든 지점 쌍에 대해 이동 가능한지 확인한다. 각 이동 가능한 지점 쌍을 간선으로 하여 출발지에서 BFS를 돌린 다음,
도착지가 될 수 있는 지점에 도달했을 때 까지의 거리를 출력하면 답이 된다.

주요 알고리즘 : 그래프 이론, BFS, 피타고라스 정리

출처 : USACO 2006O S3번
*/

int hh[10240][2], dist[10240], vis[10240];
vector<int> ed[10240];
queue<int> q;

int getdist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int bfs(int h) {
    int x, d;
    while (q.size()) {
        x = q.front();
        d = dist[x];
        if (hh[x][1] + 1000 >= h) return d;
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                dist[i] = d + 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int main(void) {
    int h, f, r;
    scanf("%d %d", &h, &f);
    for (int i = 0; i < f; i++) {
        scanf("%d %d", &hh[i][0], &hh[i][1]);
        if (hh[i][1] <= 1000) {
            q.push(i);
            vis[i] = 1;
        }
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < f; j++) {
            if (i == j) continue;
            if (getdist(hh[i][0], hh[i][1], hh[j][0], hh[j][1]) <= 1000000) ed[i].push_back(j);
        }
    }
    r = bfs(h);
    if (r < 0) return 1;
    printf("%d", r + 1);
    return 0;
}