#include <stdio.h>

/*
���� : H * W(H, W�� 4�� ��� - 1, H, W <= 39) ũ���� ������ Ȧ�� ���� '@'�� '*'�� �ְ�,
������ ������ '.'���� �Ǿ� �ִ�. �̶�, @���� ����Ͽ� ��� *�� ��ġ�� ��θ� ����Ѵ�.
��, ��δ� �ܱ��̾�� �Ѵ�.(�����¿�� ������ �ٸ� ���ΰ� �־�� �� �ȴ�.)

�ذ� ��� : ������ �� �̿��ϸ� ��� ũ���� ���ڿ��� ��� Ȧ�� ���� ���� ���ƿ���
'��'�� ����� ��ȯ ��θ� ���� �� �ִ�. �̸� ���� ����, @���� ������ *���� ������ ��θ� �����ָ�
���ϰ��� �ϴ� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, �׷��� Ž��

��ó : JAG 2017P F��
*/

char s[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (s[x][y] == '.') return 0;
    return 1;
}

void dfs(int x, int y, int l) {
    if (s[x][y] == '*') return;
    for (int i = 0; i < 4; i++) {
        if (i == l) continue;
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
            dfs(x + dxy[i][0], y + dxy[i][1], i ^ 2);
            break;
        }
    }
    if (s[x][y] == '#') s[x][y] = '.';
}

int main(void) {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                if (((~i & 1) && (~j & 1)) || j == 0 || ((i & 2) && j == 2) || ((~i & 2) && j == w - 1)
                    || (j > 2 && (~i & 1)) || ((i == 0 || i == h - 1) && j == 1)) {
                    s[i][j] = '#';
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '@') {
                for (int d = 0; d < 4; d++) {
                    if (isvalid(i + dxy[d][0], j + dxy[d][1])) {
                        dfs(i, j, d);
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}
