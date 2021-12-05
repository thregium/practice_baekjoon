#include <stdio.h>

/*
문제 : N * N(N <= 500, N은 홀수) 크기의 격자에서 각 칸에 있는 모래의 양(<= 1000)이 주어진다.
각 칸을 소용돌이 모양으로 돌며 밖으로 나갈 때 모래가 주변 지역으로 이동하는 양들이 문제에 주어지면,
밖으로 나가게 되는 모래의 양을 구한다.

해결 방법 : 모래가 이동하는 양을 하드코딩한 후 이동 방향에 맞춰 모래의 양을 계산해 나가면 된다.

주요 알고리즘 : 구현, 시뮬레이션
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