#include <stdio.h>

/*
문제 : 길이 N(N <= 1000)의 수열에서 각 위치마다 가능한 자연수(<= 9)의 목록이 주어질 때,
인접한 위치에 같은 수가 오지 않도록 하는 수열을 만들 수 있는 지 구하고, 가능한 경우 그러한 수열을 출력한다.

해결 방법 : 다이나믹 프로그래밍을 통해 각 위치와 마지막 수마다 가능한 지 여부를 기록한다.
마지막 위치까지 가능한 경우 수열을 만들 수 있으며, 마지막 위치부터 역순으로
가능한 수열을 만들어 나가면 된다.

주요 알고리즘 : DP, 역추적

출처 : 경북대 2018 호랑이번
*/

int d[1024][16], mem[1024][16], res[1024];

int main(void) {
    int n, m, x, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            d[i][x] = 1;
        }
    }
    for (int i = 1; i <= 9; i++) mem[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            if (!d[i][j]) continue;
            for (int k = 1; k <= 9; k++) {
                if (j == k) continue;
                mem[i][j] |= mem[i - 1][k];
            }
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (mem[n][i]) r = i;
    }
    if (!r) {
        printf("-1");
        return 0;
    }
    res[n] = r;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= 9; j++) {
            if (r != j && mem[i][j]) {
                r = j;
                break;
            }
        }
        res[i] = r;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}