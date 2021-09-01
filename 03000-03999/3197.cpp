#include <stdio.h>
#include <vector>
#include <tuple>
using namespace std;

/*
���� : R * C(R, C <= 1500) ũ���� ���ڿ��� �� L ���̸� X�� ���� ��ġ�� �ʰ� �̵��ϱ� ���� �ʿ��� �ּ� �ð��� ���Ѵ�.
�� �����ð����� .�� ������ X�� .���� �ٲ��.

�ذ� ��� : ��� .���� �����ϴ� BFS�� ���� �� X�� .�� �ٲ�µ� �ɸ��� �ð��� ���Ѵ�.
�� ����, �� �ð����� .�� ���ڵ��� ���Ͽ� ���ε带 ���� �����ش�. �� ����, L�� ���ڵ��� �Ź� ���� �������� Ȯ���Ѵ�.
���� ������ �� ���� �ð��� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���Ͽ� ���ε�

��ó : CHCI 2005N2S 2��
*/

char ice[1536][1536], vis[1536][1536];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c, qf = 0;
pair<int, int> g[1536][1536];
vector<tuple<int, int, int>> seq;

pair<int, int> find(int x, int y) {
    if (g[x][y].first < 0) return pair<int, int>(x, y);
    return g[x][y] = find(g[x][y].first, g[x][y].second);
}

void uni(int x1, int y1, int x2, int y2) {
    if (find(x1, y1) == find(x2, y2)) return;
    g[find(x2, y2).first][find(x2, y2).second] = find(x1, y1);
}

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y] != z) return 0;
    return 1;
}

void bfs(void) {
    int x, y, d;
    while (qf < seq.size()) {
        x = get<0>(seq[qf]);
        y = get<1>(seq[qf]);
        d = get<2>(seq[qf++]);
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x + dxy[i][0], y + dxy[i][1], 0)) continue;
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            seq.push_back(make_tuple(x + dxy[i][0], y + dxy[i][1], d + 1));
        }
    }
}

int main(void) {
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1, x, y;
    //freopen("E:\\PS\\Olympiad\\Croatia\\2005\\test_data_N2S\\labudovi.i14", "r", stdin);
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", ice[i]);
        for (int j = 0; j < c; j++) {
            if (ice[i][j] == 'L') {
                if (x1 < 0) x1 = i, y1 = j;
                else x2 = i, y2 = j;
                seq.push_back(make_tuple(i, j, 0));
                vis[i][j] = 1;
            }
            else if (ice[i][j] == '.') {
                seq.push_back(make_tuple(i, j, 0));
                vis[i][j] = 1;
            }
            g[i][j] = pair<int, int>(-1, -1);
        }
    }
    if (y1 < 0) return 1;
    bfs();
    qf = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) vis[i][j] = 0;
    }
    for (int i = 0;; i++) {
        while (qf < seq.size() && get<2>(seq[qf]) <= i) {
            x = get<0>(seq[qf]);
            y = get<1>(seq[qf]);
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                if (isvalid(x + dxy[i][0], y + dxy[i][1], 1)) uni(x, y, x + dxy[i][0], y + dxy[i][1]);
            }
            qf++;
        }
        //if (qf >= seq.size()) return 2;
        if (find(x1, y1) == find(x2, y2)) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
