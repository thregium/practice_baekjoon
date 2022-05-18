#include <stdio.h>
#include <string.h>

/*
���� : N * M(N, M <= 100) ũ���� ���� ���� 1�� �������� �׾Ҵ�. ���� �ϳ��� ���� ��
������ ������� �κ��� ���� ��� ���� ���� ���� ���Ѵ�.
���� �ؿ� ������ �ϳ��� �ִ� ��� �� ������ �������� �ʴ´�.

�ذ� ��� : �� �� �ִ� ��� ����� �� ���鼭 �� ������� ���� �������� ����� ũ�� ���� �Ź� Ȯ���ϰ�,
�� ��� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ���Ʈ ����

��ó : Tehran 2008 C��
*/

char brick[128][128], bcpy[128][128];

void cpybrick(int n, int m) {
    for (int i = 0; i < n; i++) {
        strcpy(bcpy[i], brick[i]);
    }
}

int fallbrick(int n, int m, int x, int yl, int yh) {
    int r = 0, fallen = 1, bln, az, y;
    for (int i = yl; i <= yh; i++) {
        bcpy[x][i] = '0';
        r++;
    }
    while (fallen) {
        fallen = 0;
        for (int i = n - 2; i >= 0; i--) {
            y = 0;
            while (y < m) {
                if (bcpy[i][y] == '0') {
                    y++;
                    continue;
                }
                bln = bcpy[i][y] - '0', az = 1;
                for (int j = y; j < y + bln; j++) {
                    if (bcpy[i + 1][j] != '0') az = 0;
                }
                if (az) {
                    for (int j = y; j < y + bln; j++) {
                        bcpy[i][j] = '0';
                    }
                    r += bln;
                    fallen = 1;
                }
                y += bln;
            }
        }
    }

    return r;
}

int main(void) {
    int n, m, x, cnt, res;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", brick[i]);
        }

        res = 0;
        for (int i = 0; i < n; i++) {
            x = 0;
            while (x < m) {
                if (brick[i][x] == '0') {
                    x++;
                    continue;
                }
                cpybrick(n, m);
                cnt = fallbrick(n, m, i, x, x + brick[i][x] - '0' - 1);
                if (cnt > res) res = cnt;
                x = x + brick[i][x] - '0';
            }
        }
        printf("%d\n", res);
    }
    return 0;
}