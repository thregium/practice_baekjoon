#include <stdio.h>
#include <unordered_set>
#include <queue>
using namespace std;

/*
���� : 5 * 5 ũ�� ���忡 ������ 1 ~ 5�� �ִ�. �� �������� ������ ��� ������ ����ǵ��� �� ��, �ּ� �� ȸ �������� �ϴ��� ���Ѵ�.

�ذ� ��� : ������ ���¸� �ؽøʿ� �ְ� BFS�� �Ѵ�. �̶�, �Ź� �������� ���� �� ���� �÷������� �̿��� ��� ������ ����Ǵ���
Ȯ���Ѵ�. ����Ǿ��ٸ� �� ������ BFS�� �����ϰ� �׶������� �ִܰŸ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �ؽø�
*/

char s[8][8], viss[8][8];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

queue<pair<int, int>> q;
unordered_set<int> vis;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x > 4 || y > 4) return 0;
    if (s[x][y]) return 0;
    return 1;
}

void dfs(int x, int y) {
    viss[x][y] = 1;
    if (y < 4 && s[x][y + 1] && !viss[x][y + 1]) dfs(x, y + 1);
    if (x < 4 && s[x + 1][y] && !viss[x + 1][y]) dfs(x + 1, y);
    if (y > 0 && s[x][y - 1] && !viss[x][y - 1]) dfs(x, y - 1);
    if (x > 0 && s[x - 1][y] && !viss[x - 1][y]) dfs(x - 1, y);
}

int bfs(int x) {
    int d = 0, m, y;
    q.push(pair<int, int>(x, d));
    while (q.size()) {
        x = q.front().first;
        d = q.front().second;
        q.pop();
        for (int i = 0; i < 25; i++) {
            if (x & (1 << i)) s[i / 5][i % 5] = 1;
            else s[i / 5][i % 5] = 0;
            viss[i / 5][i % 5] = 0;
        }
        m = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!s[i][j] || viss[i][j]) continue;
                dfs(i, j);
                m++;
            }
        }
        if (m == 1) return d;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!s[i][j]) continue;
                for (int dir = 0; dir < 4; dir++) {
                    if (!isvalid(i + dxy[dir][0], j + dxy[dir][1])) continue;
                    y = (x ^ (1 << (i * 5 + j)));
                    y |= 1 << ((i + dxy[dir][0]) * 5 + j + dxy[dir][1]);
                    if (vis.find(y) == vis.end()) {
                        vis.insert(y);
                        q.push(pair<int, int>(y, d + 1));
                    }
                }
            }
        }
    }
    return -1;
}

int main(void) {
    int st = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < 5; j++) {
            if (s[i][j] == '*') st += 1 << (i * 5 + j);
        }
    }
    printf("%d", bfs(st));
    return 0;
}