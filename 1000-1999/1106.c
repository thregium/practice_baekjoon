#include <stdio.h>
#define MAXI 1234567890

/*
문제 : Ei의 비용을 들여 손님의 수를 Si명 만큼 늘릴 수 있는 쌍이 N개(N <= 20) 있다고 할 때,
고객의 수를 적어도 C (C <= 1000)명 늘리기 위해 필요한 비용의 최솟값을 출력한다.

해결 방법 : 비용과 쌍의 상한이 높지 않으므로 냅색 DP를 이용하면 쉽게 풀 수 있다.

주요 알고리즘 : 다이나믹 프로그래밍, 냅색 문제
*/

int mem[1280][24];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int e[24], s[24];
    int c, n, l = MAXI;
    scanf("%d %d", &c, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &e[i], &s[i]);
    }
    for (int i = 0; i <= 1279; i++) {
        for (int j = 0; j <= n; j++) mem[i][j] = MAXI;
    }

    mem[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1279; j++) {
            mem[j][i] = small(mem[j][i - 1], s[i] > j ? MAXI : mem[j - s[i]][i] + e[i]);
            if (j >= c && mem[j][i] < l) l = mem[j][i];
        }
    }

    printf("%d\n", l);
    return 0;
}