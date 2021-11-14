#include <stdio.h>

/*
문제 : 문제에 주어진 형태의 크기가 N(N <= 10^9)인 판이 1초에 1씩 크기가 커진다고 하고, K(K <= 10^9)초동안은 1초에 2씩,
그 외에는 1초에 1씩 움직일 수 있다면 판의 끝에 도달 가능한 칸의 개수를 구한다.

해결 방법 : 크기가 N - K - 1일 때 갈 수 있는 칸의 수를 구해서 N일 때의 갈 수 있는 칸의 수에서 빼면 된다.
단, N - K - 1이 음수인 경우 0으로 생각해야 한다.

주요 알고리즘 : 수학

출처 : SUAPC 2021S F번
*/

int main(void) {
    long long t, n, k, r;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld", &n, &k);
        if (n <= k) r = 0;
        else r = n - k - 1;
        printf("%lld\n", (n * (n + 1) * 2) - (r * (r + 1) * 2));
    }
    return 0;
}