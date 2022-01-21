#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : H * W(H, W <= 200) ũ���� ������ ���ֿ� �� ������� �ִ�. ���ڴ� ���� �ƴ� ĭ����
1���� ������������ 1ĭ�� �����̰ų� �������� ���� �� �ִ�. �̶�, ���ְ� �������� ��� �����̴���
������ �ʰ� �����ο� ���� ������ �� ���Ѵ�. ��, ���ÿ� ������ �Ա��� ������ ��� ���ֿ� ������ ���̴�.
'@'�� ����(1��), '$'�� ����, '%'�� ������ �Ա�(1��), '#'�� ��, '.'�� �� ĭ�̴�.

�ذ� ��� : ���ֿ� ������ �� �� �ִ� ���� BFS�� ���� ã�Ƴ�����. ������ ��ġ�� ���� ť�� �ְ�
������ ��ġ�� ���߿� ť�� ���� ���� BFS�� �����Ѵ�. ���ִ� ������ ���� ���ɼ���
���� �����θ� �̵��ؾ� �Ѵ�. ť�� ������ ������ ���� ���ְ� ������ �Ա��� �����Ͽ����� ���ɴ�.
�׷��ϴٸ� �������� ���� �����ߴ��� Ȯ���Ѵ�. �� ���� ��� ���ֿ� ������ ���̰�, �ϳ��� �ƴ� ���
������ ���̴�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : JAG 2016P B��
*/

char pal[256][256], visp[256][256], viss[256][256];
int distp[256][256], dists[256][256];
int h, w;
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
queue<pair<int, int>> q;

int isvalid(int x, int y, int m) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (pal[x][y] == '#' || viss[x][y]) return 0;
    if (!m && visp[x][y]) return 0;
    return 1;
}

void bfs() {
    int x, y, d, m = 0;
    while (q.size()) {
        x = q.front().first, y = q.front().second;
        if (x >= 256) {
            x -= 256, y -= 256, m = 0, d = distp[x][y];
        }
        else {
            m = 1, d = dists[x][y];
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], m)) {
                if (m == 0) {
                    visp[x + dxy[i][0]][y + dxy[i][1]] = 1;
                    distp[x + dxy[i][0]][y + dxy[i][1]] = distp[x][y] + 1;
                    q.push(pair<int, int>(x + dxy[i][0] + 256, y + dxy[i][1] + 256));
                }
                else {
                    viss[x + dxy[i][0]][y + dxy[i][1]] = 1;
                    dists[x + dxy[i][0]][y + dxy[i][1]] = dists[x][y] + 1;
                    q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                }
            }
        }
    }
}

int main(void) {
    int x = -1, y = -1;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", pal[i]);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (pal[i][j] == '@') {
                q.push(pair<int, int>(i + 256, j + 256));
                visp[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (pal[i][j] == '$') {
                q.push(pair<int, int>(i, j));
                viss[i][j] = 1;
            }
            else if (pal[i][j] == '%') {
                x = i;
                y = j;
            }
        }
    }

    bfs();
    if (!visp[x][y] || (viss[x][y] && dists[x][y] <= distp[x][y])) printf("No\n");
    else printf("Yes\n");

    return 0;
}