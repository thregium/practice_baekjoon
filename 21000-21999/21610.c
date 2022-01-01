#include <stdio.h>

/*
���� : N * N(N <= 50) ũ���� ĭ�� ĭ���� ������ ���� �־�����. ó������ ������ ���� �Ʒ��� 2 * 2 ũ��� ���� ��,
M(M <= 100)���� �־��� �̵��� ���� �� ��ü ĭ�� �ִ� ���� �� ���� ���Ѵ�.

�ذ� ��� : ������ �־������ ������ �̵��� ���� ��(���� �̿�), ���� �� ��ȭ�� Ȯ���ϰ�,
�ٽ� ���ο� ������ ����� ���� �ݺ��ϸ� �ùķ��̼��Ѵ�. �̵��� ���� ������ ���� �� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�
*/

int water[64][64], cloud[64][64], ncloud[64][64];
int dxy[9][2] = { {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };

int main(void) {
    int n, m, d, s, c, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &water[i][j]);
        }
    }
    cloud[n][1] = 1, cloud[n][2] = 1, cloud[n - 1][1] = 1, cloud[n - 1][2] = 1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &d, &s);
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ncloud[(j + dxy[d][0] * s + n * 100 - 1) % n + 1][(k + dxy[d][1] * s + n * 100 - 1) % n + 1] = cloud[j][k];
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) water[j][k] += ncloud[j][k];
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (!ncloud[j][k]) continue;
                c = 0;
                for (int l = 2; l <= 8; l += 2) c += !!water[j + dxy[l][0]][k + dxy[l][1]];
                water[j][k] += c;
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (ncloud[j][k] || water[j][k] < 2) cloud[j][k] = 0;
                else {
                    cloud[j][k] = 1;
                    water[j][k] -= 2;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            r += water[i][j];
        }
    }
    printf("%d", r);
    return 0;
}