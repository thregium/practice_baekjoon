#include <stdio.h>

/*
���� : R * C(R, C <= 100) ũ���� �ʿ� 'G', '#', '.', 'S'�� �ִ�. 'G'�� ��ġ�� �����¿�� T(T <= 10)ȸ
������ 'S'�� �ִ��� ���� ������ �� ��, ���� �� �ִ� 'S'�� �ִ� ������ ���Ѵ�.

�ذ� ��� : T�� ������ �۱� ������ ������ �� �ִ� ��츦 ��� �õ��غ��� �ȴ�.
�湮 ó���� �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : ���� 1ȸ 2��
*/

char map[128][128];
const int dxy[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0} };
int r, c, best = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (map[x][y] == '#') return 0;
    return 1;
}

void track(int x, int y, int t, int cnt) {
    char store;
    if (cnt > best) best = cnt;
    if (t == 0) return;
    for (int i = 0; i < 5; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
            store = map[x + dxy[i][0]][y + dxy[i][1]];
            map[x + dxy[i][0]][y + dxy[i][1]] = '.';
            track(x + dxy[i][0], y + dxy[i][1], t - 1, cnt + (store == 'S'));
            map[x + dxy[i][0]][y + dxy[i][1]] = store;
        }
    }
}

int main(void) {
    int t, x = -1, y = -1;
    scanf("%d %d %d", &r, &c, &t);
    for (int i = 0; i < r; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 'G') {
                if (x >= 0) return 1;
                x = i;
                y = j;
                map[i][j] = '.';
            }
        }
    }
    if (x < 0) return 1;

    track(x, y, t, 0);
    printf("%d", best);
    return 0;
}