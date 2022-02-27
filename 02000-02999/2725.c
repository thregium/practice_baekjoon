#include <stdio.h>

/*
문제 : N * N(N <= 1000) 개의 격자점 가운데 (0, 0)에서 가리지 않고 볼 수 있는 점의 개수를 구한다.
이를 C(C <= 1000)번 반복한다.

해결 방법 : 각 점에 대해 X와 Y좌표가 서로소인 경우 볼 수 있는 점이다. 1000 * 1000개의 점에 대해
N의 범위마다의 볼 수 있는 점 개수를 찾은 다음 누적 합을 통해 답을 저장하고 출력하면 된다.

주요 알고리즘 : 수학, 유클리드 호제법, 누적 합

출처 : GNY 2006 F번
*/

int res[1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int c, n;
    res[0] = 2;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (gcd(i, j) == 1) res[big(i, j)]++;
        }
    }
    for (int i = 1; i <= 1000; i++) res[i] += res[i - 1];
    scanf("%d", &c);
    for (int tt = 0; tt < c; tt++) {
        scanf("%d", &n);
        printf("%d\n", res[n]);
    }
    return 0;
}