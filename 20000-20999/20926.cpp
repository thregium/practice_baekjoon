#include <stdio.h>
#include <queue>
#include <vector>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : W * H(W, H <= 500) 크기의 얼음 미로가 있다. 이 얼음 미로에서 상하좌우로 미끄러지며 장애물을 만나기 전까지 이동 가능하다면,
가장 빨리 출구에 도착하는 시간은 얼마인지 구한다. 단, 이동 시간은 경로에 있는 얼음의 값의 합이고,
이동 중간에 구멍이나 미로의 끝을 만난다면 이후로는 움직일 수 없다고 한다.

해결 방법 : 먼저, 상하좌우로 장애물을 만날 때 까지 이동했을 때의 위치와 그곳까지의 거리를 모든 칸에 대해 추가해준다.
그 다음으로는 다익스트라 알고리즘을 통해 출구까지 가장 빠른 시간을 구하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, 구현

출처 : 신촌C 2021WB G번
*/

char maze[512][512];
int mindist[512][512];
vector<tuple<int, int, int>> ed[512][512];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int main(void) {
    int w, h, x = -1, y = -1, last = 0, dist = 0;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'T') {
                x = i;
                y = j;
                maze[i][j] = '0';
            }
            mindist[i][j] = INF;
        }
    }
    if (x < 0) return 1;

    //각 방향에 대한 간선 생성
    for (int i = 0; i < h; i++) {
        last = -1;
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'R') {
                last = j + 1;
                dist = 0;
            }
            else if (maze[i][j] == 'H' || maze[i][j] == 'E') {
                last = j;
                dist = 0;
            }
            else if (last >= 0) {
                if (j > last) ed[i][j].push_back(make_tuple(i, last, dist));
                dist += maze[i][j] - '0';
            }
        }
        last = w;
        for (int j = w - 1; j >= 0; j--) {
            if (maze[i][j] == 'R') {
                last = j - 1;
                dist = 0;
            }
            else if (maze[i][j] == 'H' || maze[i][j] == 'E') {
                last = j;
                dist = 0;
            }
            else if (last < w) {
                if (j < last) ed[i][j].push_back(make_tuple(i, last, dist));
                dist += maze[i][j] - '0';
            }
        }
    }
    for (int i = 0; i < w; i++) {
        last = -1;
        for (int j = 0; j < h; j++) {
            if (maze[j][i] == 'R') {
                last = j + 1;
                dist = 0;
            }
            else if (maze[j][i] == 'H' || maze[j][i] == 'E') {
                last = j;
                dist = 0;
            }
            else if (last >= 0) {
                if (j > last) ed[j][i].push_back(make_tuple(last, i, dist));
                dist += maze[j][i] - '0';
            }
        }
        last = h;
        for (int j = h - 1; j >= 0; j--) {
            if (maze[j][i] == 'R') {
                last = j - 1;
                dist = 0;
            }
            else if (maze[j][i] == 'H' || maze[j][i] == 'E') {
                last = j;
                dist = 0;
            }
            else if (last < h) {
                if (j < last) ed[j][i].push_back(make_tuple(last, i, dist));
                dist += maze[j][i] - '0';
            }
        }
    }

    //다익스트라
    pq.push(pair<int, pair<int, int>>(0, pair<int, int>(x, y)));
    while (pq.size()) {
        x = pq.top().second.first;
        y = pq.top().second.second;
        dist = pq.top().first;
        pq.pop();
        if (dist >= mindist[x][y]) continue;
        mindist[x][y] = dist;
        for (auto t : ed[x][y]) {
            pq.push(pair<int, pair<int, int>>(dist + get<2>(t), pair<int, int>(get<0>(t), get<1>(t))));
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'E') {
                printf("%d", mindist[i][j] == INF ? -1 : mindist[i][j]);
            }
        }
    }
    return 0;
}