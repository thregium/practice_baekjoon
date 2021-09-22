#include <stdio.h>
#define INF 1012345678

/*
문제 : R * C(R, C <= 100) 크기의 격자에 수들이 쓰여있다. 왼쪽 위 칸에서 오른쪽 아래 칸으로 이동하며
얻을 수 있는 수 합 중 최댓값을 구한다. 단, 같은 열은 2회 이상 머무를 수 없고, 대각선 또는 수평으로 인접한 경우만 이동 가능하다.

해결 방법 : 다이나믹 프로그래밍을 통해 해당 열의 각 줄마다 얻을 수 있는 최댓값을 구해가며 풀면 된다.

주요 알고리즘 : DP

출처 : USACO 2006X G4번
*/

int coins[128][128], mem[128][128];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &coins[i][j]);
        }
    }
    for (int i = 1; i <= r + 1; i++) mem[i][0] = -INF;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            mem[j][i] = coins[j][i] + big(mem[j][i - 1], big(mem[j - 1][i - 1], mem[j + 1][i - 1]));
        }
        mem[r + 1][i] = -INF;
    }
    printf("%d", mem[r][c]);
    return 0;
}