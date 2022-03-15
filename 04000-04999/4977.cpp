#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#define INF 1012345678
#define INNER pair<pair<pair<int, int>, pair<int, int>>, int>
//(�޹��� X��ǥ, Y��ǥ), (�������� X��ǥ, Y��ǥ), ���������� ��� ��(0�̸� �޹�, 1�̸� ������)
using namespace std;

/*
���� : H * W(H <= 60)(W <= 30) ũ���� ������ �ִ�. �� ĭ���� ���� ��� �� �ִ� ���� ��� �� �ִٸ�
���� ���� �ʿ��� �ҿ�ð�(<= 9)�� �ִ�. �Ǵ� ����� �Ǵ� �������� �� �ִ�.
ó������ ������� �� ���� ��� ä�� �����ϸ� ����� ������ �־��� ������ ���� ������ ������ ������.
�̸� �ݺ��ϴٰ� �������� �� ���̶� ���� �����̴�.
�������� ������ �� �ִ� ��, �ִٸ� �ִ� �ð��� ���� �� ���Ѵ�.

�ذ� ��� : �� ���� ��ǥ�� ���������� ��� ���� ���·� �Ͽ� ���ͽ�Ʈ�� ���� ���� ���س�����.
������ �ſ� �����ϹǷ� �Ǽ����� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ��, ��, ����

��ó : JDC 2007 D��
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