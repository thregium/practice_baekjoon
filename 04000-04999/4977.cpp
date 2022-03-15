#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#define INF 1012345678
#define INNER pair<pair<pair<int, int>, pair<int, int>>, int>
//(왼발의 X좌표, Y좌표), (오른발의 X좌표, Y좌표), 마지막으로 디딘 발(0이면 왼발, 1이면 오른발)
using namespace std;

/*
문제 : H * W(H <= 60)(W <= 30) 크기의 절벽이 있다. 각 칸마다 발을 디딜 수 있는 지와 디딜 수 있다면
디디기 위해 필요한 소요시간(<= 9)이 있다. 또는 출발점 또는 도착점일 수 있다.
처음에는 출발점에 양 발을 디딘 채로 시작하며 양발을 문제에 주어진 범위에 맞춰 번갈아 움직여 나간다.
이를 반복하다가 도착점에 한 발이라도 디디면 성공이다.
도착점에 도달할 수 있는 지, 있다면 최단 시간은 얼마인 지 구한다.

해결 방법 : 각 발의 좌표와 마지막으로 디딘 발을 상태로 하여 다익스트라를 통해 답을 구해나간다.
구현이 매우 복잡하므로 실수하지 않도록 주의한다.

주요 알고리즘 : 그래프 이론, 다익스트라, 맵, 셋, 구현

출처 : JDC 2007 D번
*/

int cliff[64][32];
set<INNER> st;
map<INNER, int> mp;
priority_queue<pair<int, INNER>, vector<pair<int, INNER>>, greater<>> pq;
int mvl[9][2] = { {-2, -1}, {-1, -2}, {-1, -1}, {0, -3}, {0, -2}, {0, -1}, {1, -2}, {1, -1}, {2, -1} };
int mvr[9][2] = { {-2, 1}, {-1, 2}, {-1, 1}, {0, 3}, {0, 2}, {0, 1}, {1, 2}, {1, 1}, {2, 1} };
int w, h;

int isvalid(int x1, int y1, int x2, int y2, int dir, int tm) {
    if (x1 < 0 || y1 < 0 || x1 >= h || y1 >= w || x2 < 0 || y2 < 0 || x2 >= h || y2 >= w) return 0;
    if (cliff[x1][y1] < 0 || cliff[x2][y2] < 0) return 0;
    if (mp.find({ {{x1, y1}, {x2, y2} }, dir }) == mp.end()) return 1;
    else if (dir == 0 && tm + cliff[x1][y1] < mp[{ { {x1, y1}, { x2, y2 } }, dir }]) return 1;
    else if (dir == 1 && tm + cliff[x2][y2] < mp[{ { {x1, y1}, { x2, y2 } }, dir }]) return 1;
    else return 0;
}

int main(void) {
    int sx = -1, sy = -1, tx = -1, ty = -1, x1, x2, y1, y2, dir, tm, res;
    char c;
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf(" %c", &c);
                if (c == 'S') {
                    cliff[i][j] = 1000;
                    pq.push({ 0, {{{i, j}, {i, j}}, -1} });
                    mp.insert({ {{{i, j}, {i, j}}, -1} , 0 });
                    pq.push({ 1, {{{i, j}, {i, j}}, -1} });
                    mp.insert({ {{{i, j}, {i, j}}, -1} , 1 });
                }
                else if (c == 'T') {
                    tx = i, ty = j - 1, cliff[i][j] = 0;
                }
                else if (c == 'X') cliff[i][j] = -1;
                else cliff[i][j] = c - '0';
            }
        }

        while (pq.size()) {
            x1 = pq.top().second.first.first.first;
            y1 = pq.top().second.first.first.second;
            x2 = pq.top().second.first.second.first;
            y2 = pq.top().second.first.second.second;
            dir = pq.top().second.second;
            tm = pq.top().first;
            pq.pop();
            if (st.find({ {{x1, y1}, {x2, y2}}, dir }) != st.end()) continue;
            else st.insert({ {{x1, y1}, {x2, y2}}, dir });

            if (dir != 0) {
                for (int i = 0; i < 9; i++) {
                    if (isvalid(x2 + mvl[i][0], y2 + mvl[i][1], x2, y2, 0, tm)) {
                        pq.push({ tm + cliff[x2 + mvl[i][0]][y2 + mvl[i][1]],
                            {{{x2 + mvl[i][0], y2 + mvl[i][1]}, {x2, y2}}, 0} });
                        if (mp.find({ {{x2 + mvl[i][0], y2 + mvl[i][1]}, {x2, y2}}, 0 }) != mp.end()) {
                            mp.insert({ {{{x2 + mvl[i][0], y2 + mvl[i][1]}, {x2, y2}}, 0},
                                tm + cliff[x2 + mvl[i][0]][y2 + mvl[i][1]] });
                        }
                        else {
                            mp[{ { {x2 + mvl[i][0], y2 + mvl[i][1]}, { x2, y2 }}, 0}] =
                                tm + cliff[x2 + mvl[i][0]][y2 + mvl[i][1]];
                        }
                    }
                }
            }
            if (dir != 1) {
                for (int i = 0; i < 9; i++) {
                    if (isvalid(x1, y1, x1 + mvr[i][0], y1 + mvr[i][1], 1, tm)) {
                        pq.push({ tm + cliff[x1 + mvr[i][0]][y1 + mvr[i][1]],
                            {{{x1, y1}, {x1 + mvr[i][0], y1 + mvr[i][1]}}, 1}});
                        if (mp.find({ {{x1, y1}, {x1 + mvr[i][0], y1 + mvr[i][1]}}, 1 }) != mp.end()) {
                            mp.insert({ {{{x1, y1}, {x1 + mvr[i][0], y1 + mvr[i][1]}}, 1},
                                tm + cliff[x1 + mvr[i][0]][y1 + mvr[i][1]] });
                        }
                        else {
                            mp[{ { {x1, y1}, { x1 + mvr[i][0], y1 + mvr[i][1] }}, 1}] =
                                tm + cliff[x1 + mvr[i][0]][y1 + mvr[i][1]];
                        }
                    }
                }
            }
        }

        res = INF;
        for (auto& i : mp) {
            if (cliff[i.first.first.first.first][i.first.first.first.second] && 
                cliff[i.first.first.second.first][i.first.first.second.second]) continue;
            if (i.second < res) res = i.second;
        }

        printf("%d\n", res == INF ? -1 : res);
        st.clear();
        mp.clear();
    }
    return 0;
}