#include <stdio.h>

/*
���� : N * N(N <= 500, N�� Ȧ��) ũ���� ���ڿ��� �� ĭ�� �ִ� ���� ��(<= 1000)�� �־�����.
�� ĭ�� �ҿ뵹�� ������� ���� ������ ���� �� �𷡰� �ֺ� �������� �̵��ϴ� ����� ������ �־�����,
������ ������ �Ǵ� ���� ���� ���Ѵ�.

�ذ� ��� : �𷡰� �̵��ϴ� ���� �ϵ��ڵ��� �� �̵� ���⿡ ���� ���� ���� ����� ������ �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�
*/

int sand[512][512];
int mv[4][5] = { {0, 1, 0, 1, 0}, {2, 7, 0, 7, 2}, {0, 10, 0, 10, 0}, {0, 0, 5, 0, 0} };
int dxy[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int isvalid(int n, int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    return 1;
}

int main(void) {
    int n, x, y, d = 0, dc = 1;
    long long sum = 0, rem = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &sand[i][j]);
        }
    }
    x = n >> 1;
    y = n >> 1;

    while (x + y > 0) {
        for (int di = 0; di < 2; di++) {
            for (int dj = 0; dj < dc; dj++) {
                if (x + y == 0) break;
                if (!isvalid(n, x + dxy[d][0], y + dxy[d][1])) return 1;
                sum = sand[x + dxy[d][0]][y + dxy[d][1]];
                rem = sum;
                sand[x + dxy[d][0]][y + dxy[d][1]] = 0;
                for (int i = 0; i < 4; i++) {
                    for (int j = -2; j <= 2; j++) {
                        if (!isvalid(n, x + dxy[d][0] * i + dxy[(d + 3) & 3][0] * j,
                            y + dxy[d][1] * i + dxy[(d + 3) & 3][1] * j)) res += sum * mv[i][j + 2] / 100;
                        else sand[x + dxy[d][0] * i + dxy[(d + 3) & 3][0] * j][y + dxy[d][1] * i + dxy[(d + 3) & 3][1] * j]
                            += sum * mv[i][j + 2] / 100;
                        rem -= sum * mv[i][j + 2] / 100;
                    }
                }
                if (!isvalid(n, x + dxy[d][0] * 2, y + dxy[d][1] * 2)) res += rem;
                else sand[x + dxy[d][0] * 2][y + dxy[d][1] * 2] += rem;
                x += dxy[d][0];
                y += dxy[d][1];
            }
            d = ((d + 1) & 3);
        }
        dc++;
    }
    printf("%lld", res);
    return 0;
}