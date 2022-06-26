#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <deque>
#include <map>
#include <assert.h>
using namespace std;

char grid[32][32];
pair<int, int> port[32][32][4]; //각 지점에서 각 방향으로 포탈을 쏴서 도착하는 칸
pair<int, int> stt = { 0, 0 }; //시작점 / 도착점
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //각 방향의 배열
deque<vector<int>> dq;
map<vector<int>, int> dist; //거리는 맵으로 관리
//각 상태 : [X좌표, Y좌표, 도착 포탈(벽)의 X좌표, 도착 포탈(벽)의 Y좌표]
int h, w;

int isvalid(vector<int> state, int tdist) {
    //해당 지점이 아직 탐색하지 않은 공간인지, 그렇다면 빈칸 또는 벽인지 여부를 반환
    if (state[0] < 0 || state[0] > h + 1 || state[1] < 0 || state[1] > w + 1) return 0;
    if (dist.find(state) != dist.end() && dist[state] <= tdist) return 0;
    if (grid[state[0]][state[1]] == '#') return -1;
    return 1;
}

int bfs(vector<int> state) {
    //0 - 1 BFS를 통한 최단거리 반환
    while (dq.size()) dq.pop_back();
    dist.clear();
    dist.insert({ state, 0 });
    dq.push_back(state);

    vector<int> tstate;
    int sdist, pt;

    while (dq.size()) {
        state = dq.front();
        dq.pop_front();
        tstate = state;
        sdist = dist[state];
        if (grid[state[0]][state[1]] == 'X') return sdist; //케익에 도착한 경우
        assert(grid[state[0]][state[1]] != '#');
        if (state[0] == 2 && state[1] == 4) {
            state[0] = state[0];
        }

        for (int i = 0; i < 4; i++) {
            //도착하는 포탈을 해당 지점에서 사방으로 발사
            tstate[2] = port[state[0]][state[1]][i].first;
            tstate[3] = port[state[0]][state[1]][i].second;
            if (isvalid(tstate, sdist) > 0) {
                //가능한 경우 덱의 앞쪽에 추가
                dq.push_front(tstate);
                dist.erase(tstate);
                dist.insert({ tstate, sdist });
            }
        }
        tstate = state;

        for (int i = 0; i < 4; i++) {
            //사방으로 이동
            tstate[0] = state[0] + dxy[i][0];
            tstate[1] = state[1] + dxy[i][1];
            pt = isvalid(tstate, sdist + 1);
            if (pt > 0) {
                //빈 칸인 경우 덱의 뒤쪽에 추가
                dq.push_back(tstate);
                dist.erase(tstate);
                dist.insert({ tstate, sdist + 1 });
            }
            else if (pt < 0) {
                //빈 칸이 아니라면 그곳에 출발 포탈을 만들고 도착 포탈로 이동
                tstate[0] = state[2];
                tstate[1] = state[3];
                if (isvalid(tstate, sdist + 1) > 0) {
                    //그곳이 빈 칸인 경우 덱의 뒤쪽에 추가
                    dq.push_back(tstate);
                    dist.erase(tstate);
                    dist.insert({ tstate, sdist + 1 });
                }
            }
        }
    }
    return -1; //케익에 도착하지 못한 경우
}

int main(void) {
    int t, res, x, y;
    /*
    srand(time(NULL));
    printf("200\n");
    for (int tt = 0; tt < 200; tt++) {
        do {
            h = 8;
            w = 8;
        } while (h * w < 2);
        printf("%d %d\n", h, w);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                grid[i][j] = ((rand() & 1) ? '#' : '.');
            }
            grid[i][w + 1] = '\0';
        }
        x = rand() % h + 1;
        y = rand() % w + 1;
        grid[x][y] = 'O';
        do {
            x = rand() % h + 1;
            y = rand() % w + 1;
        } while (grid[x][y] == 'O');
        grid[x][y] = 'X';
        for (int i = 1; i <= h; i++) {
            printf("%s\n", grid[i] + 1);
        }
    }
    return 0;
    */
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        //입력
        scanf("%d %d", &h, &w);
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) grid[i][j] = '#';
        }
        stt.first = -1, stt.second = -1;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == 'O') {
                    stt.first = i;
                    stt.second = j;
                }
            }
        }
        if (stt.first < 0) return 1;

        //각 지점에서 사방으로 포탈건을 쏘아서 도착하는 벽을 구함.
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                for (int d = 0; d < 4; d++) {
                    port[i][j][d].first = i;
                    port[i][j][d].second = j;
                    while (grid[port[i][j][d].first][port[i][j][d].second] != '#') {
                        port[i][j][d].first += dxy[d][0];
                        port[i][j][d].second += dxy[d][1];
                    }
                    port[i][j][d].first -= dxy[d][0];
                    port[i][j][d].second -= dxy[d][1];
                }
            }
        }

        res = bfs(vector<int>{stt.first, stt.second, 0, 0}); //시작점을 기준으로 BFS 시작

        //BFS 결과에 따라 출력
        if (res < 0) printf("Case #%d: THE CAKE IS A LIE\n", tt);
        else printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}