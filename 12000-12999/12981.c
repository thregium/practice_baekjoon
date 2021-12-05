#include <stdio.h>
#define INF 1012345678

/*
문제 : 3가지 색깔의 공이 각각 100개 이하로 주어진다. 이때, 공을 한 번에 1개, 2개, 3개씩 넣을 수 있고,
한번에 넣는 공의 색깔은 모두 같거나 모두 달라야 한다면 넣는 횟수의 최솟값을 구한다.

해결 방법 : 다이나믹 프로그래밍을 이용해 각 공의 개수를 변수로 두고 이때의 답을 계산하면 된다.

주요 알고리즘 : DP

출처 : SRM 609 D2B
*/

int mem[128][128][128];

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int a, int b, int c) {
    if (mem[a][b][c] >= 0) return mem[a][b][c];
    if (a + b + c == 0) return mem[a][b][c] = 0;
    int r = INF;
    if (a >= 1) r = small(r, dp(a - 1, b, c)) + 1;
    if (b >= 1) r = small(r, dp(a, b - 1, c)) + 1;
    if (c >= 1) r = small(r, dp(a, b, c - 1)) + 1;
    if (a >= 2) r = small(r, dp(a - 2, b, c)) + 1;
    if (a >= 1 && b >= 1) r = small(r, dp(a - 1, b - 1, c)) + 1;
    if (a >= 1 && c >= 1) r = small(r, dp(a - 1, b, c - 1)) + 1;
    if (b >= 2) r = small(r, dp(a, b - 2, c)) + 1;
    if (b >= 1 && c >= 1) r = small(r, dp(a, b - 1, c - 1)) + 1;
    if (c >= 2) r = small(r, dp(a, b, c - 2)) + 1;
    if (a >= 3) r = small(r, dp(a - 3, b, c)) + 1;
    if (a >= 1 && b >= 1 && c >= 1) r = small(r, dp(a - 1, b - 1, c - 1)) + 1;
    if (b >= 3) r = small(r, dp(a, b - 3, c)) + 1;
    if (c >= 3) r = small(r, dp(a, b, c - 3)) + 1;
    return mem[a][b][c] = r;
}

int main(void) {
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            for (int k = 0; k < 128; k++) {
                mem[i][j][k] = -1;
            }
        }
    }
    printf("%d", dp(r, g, b));
    return 0;
}