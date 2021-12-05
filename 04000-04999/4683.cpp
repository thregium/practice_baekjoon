#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#define INF 103000.0
using namespace std;

/*
문제 : 10 * 10 크기의 정사각형 방이 있다. 이 방 안에 벽이 0개 이상 18개 이하로 있다.
각 벽은 Y축에 평행하고, 구멍이 2개 있다. 각 벽의 X좌표와 구멍의 시작과 끝의 Y좌표들이 주어질 때,
(0, 5) 위치에서 (10, 5) 위치로 이동하는데 드는 최단거리를 구한다.

해결 방법 : 각 벽마다 구멍의 맨 위와 맨 밑 위치를 확인한다. 목적지 또는 경유지로 의미 있는 곳은
해당 장소들 뿐임을 알 수 있다. 따라서, 이 점을 이용해 다익스트라를 한다.
시작점, 끝점을 포함해 모든 구멍의 사이에 서로 이동이 가능한지 확인하고, 이동이 가능하다면 해당 점 사이를 간선으로 잇는다.
그 후 해당 간선들을 이용해 시작점부터 끝점까지의 거리를 다익스트라로 구하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, 기하학

출처 : MidC 1996 B번
*/

double wall[32][8], dist[32][8];
vector<pair<double, pair<int, int>>> ed[32][8];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double getdist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double getcross(double x1, double y1, double x2, double y2, double xp) {
    return y1 + (y2 - y1) / (x2 - x1) * (xp - x1);
}

void initdist(int n) {
    //서로 이동 가능한 곳 사이의 거리를 구한다.
    int t;
    double cross;
    for (int i = 1; i <= 4; i++) {
        wall[0][i] = 5.0;
        wall[n + 1][i] = 5.0;
    }
    wall[n + 1][0] = 10.0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 8; j++) {
            ed[i][j].clear();
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int ii = 1; ii <= 4; ii++) {
            for (int j = i + 1; j <= n + 1; j++) {
                for (int jj = 1; jj <= 4; jj++) {
                    //시작점과 끝점을 포함한 모든 구멍의 양 끝 사이를 이어본다.
                    t = 0;
                    for (int k = i + 1; k < j; k++) {
                        cross = getcross(wall[i][0], wall[i][ii], wall[j][0], wall[j][jj], wall[k][0]);
                        if (cross < wall[k][1] || cross > wall[k][4] || (cross > wall[k][2] && cross < wall[k][3])) {
                            t = 1; //중간에 벽에 걸린 경우 이동 불가능하다.
                            break;
                        }
                    }
                    if (t) continue;
                    ed[i][ii].push_back(pair<double, pair<int, int>>(getdist(wall[i][0], wall[i][ii], wall[j][0], wall[j][jj]),
                        pair<int, int>(j, jj))); //이동 가능한 경우 간선을 추가한다.
                }
            }
        }
    }
}

void solve(int n) {
    //다익스트라를 통해 목적지까지의 거리를 구한다.
    int x, y;
    double d;
    dist[0][1] = 0.0;
    pq.push(pair<double, pair<int, int>>(0.0, pair<int, int>(0, 1)));
    while (pq.size()) {
        x = pq.top().second.first;
        y = pq.top().second.second;
        d = pq.top().first;
        pq.pop();
        for (auto i : ed[x][y]) {
            if (dist[i.second.first][i.second.second] > d + i.first) {
                dist[i.second.first][i.second.second] = d + i.first;
                pq.push(pair<double, pair<int, int>>(d + i.first, pair<int, int>(i.second.first, i.second.second)));
            }
        }
    }
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 4; j++) {
                scanf("%lf", &wall[i][j]);
            }
        }
        qsort(wall + 1, n, sizeof(double) * 8, cmp1); //벽의 순서를 정렬해준다.
        initdist(n);
        solve(n);
        printf("%.2f\n", dist[n + 1][1]);
    }
    return 0;
}