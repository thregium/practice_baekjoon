#include <stdio.h>

/*
문제 : 4가지 과일과 까마귀 말을 이용해 하는 게임이 있다. 주사위를 던져서 1 ~ 4의 눈이 나오면
4가지 과일 각각에 대응하여 남은 과일이 있는 경우만 과일을 1개 제거한다. 5의 눈이 나오면
가장 많은 과일을 1개 제거한다. 6의 눈이 나오면 까마귀를 1칸 앞으로 옮긴다. 까마귀가 0의 칸에 도달하면
지게 되고, 그 전에 과일을 전부 제거하면 이기게 된다.
각 과일의 개수는 4개 이하고, 까마귀의 거리는 8 이하일 때, 이길 확률을 구한다.

해결 방법 : 각 남은 과일의 개수와 까마귀의 거리마다 확률을 다이나믹 프로그래밍을 이용해 구한다.
확률은 주사위를 던지는 각 경우의 상태의 확률을 전부 더하고 상태가 변하는 경우의 수로 나누면 답이 된다.
상태가 변하지 않는 경우는 논외로 해야 함에 주의한다.

주요 알고리즘 : 수학, 확률론, DP

출처 : VTH 2015 G번
*/

double mem[5][5][5][5][9];

double dp(int r, int g, int b, int y, int s) {
    if (s == 0) return mem[r][g][b][y][s] = 0.0;
    else if (r + g + b + y == 0) return mem[r][g][b][y][s] = 1.0;
    else if (mem[r][g][b][y][s] >= -0.5) return mem[r][g][b][y][s];
    double res = 0.0;
    int count = 2;
    if (r > 0) {
        res += dp(r - 1, g, b, y, s);
        count++;
    }
    if (g > 0) {
        res += dp(r, g - 1, b, y, s);
        count++;
    }
    if (b > 0) {
        res += dp(r, g, b - 1, y, s);
        count++;
    }
    if (y > 0) {
        res += dp(r, g, b, y - 1, s);
        count++;
    }
    if (r >= g && r >= b && r >= y) res += dp(r - 1, g, b, y, s);
    else if (g >= r && g >= b && g >= y) res += dp(r, g - 1, b, y, s);
    else if (b >= r && b >= g && b >= y) res += dp(r, g, b - 1, y, s);
    else if (y >= r && y >= g && y >= b) res += dp(r, g, b, y - 1, s);
    res += dp(r, g, b, y, s - 1);
    return mem[r][g][b][y][s] = res / count;
}

int main(void) {
    int r, g, b, y, s;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            for (int k = 0; k <= 4; k++) {
                for (int l = 0; l <= 4; l++) {
                    for (int m = 0; m <= 8; m++) mem[i][j][k][l][m] = -1.0;
                }
            }
        }
    }
    scanf("%d %d %d %d %d", &r, &g, &b, &y, &s);
    printf("%.9f", dp(r, g, b, y, s));
    return 0;
}