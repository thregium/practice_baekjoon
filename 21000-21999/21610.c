#include <stdio.h>

/*
문제 : N * N(N <= 50) 크기의 칸에 칸별로 물들의 양이 주어진다. 처음에는 구름이 왼쪽 아래에 2 * 2 크기로 있을 때,
M(M <= 100)번의 주어진 이동이 끝난 후 전체 칸에 있는 물의 양 합을 구한다.

해결 방법 : 문제에 주어진대로 구름의 이동을 구한 후(모듈로 이용), 물의 양 변화를 확인하고,
다시 새로운 구름을 만드는 것을 반복하며 시뮬레이션한다. 이동이 전부 끝나면 물의 양 합을 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션
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