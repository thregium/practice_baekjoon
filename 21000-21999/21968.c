#include <stdio.h>

/*
문제 : 서로 다른 3의 거듭제곱의 합으로 나타낼 수 있는 수들 가운데 N(N <= 1.24 * 10 ^ 11)번째 값을 찾는다.

해결 방법 : 3의 거듭제곱을 2의 거듭제곱으로 바꾸면 모든 수를 나타낼 수 있다. 따라서, 3의 0제곱부터 64제곱까지를 미리 계산한 후
N의 비트에 대응하는 3의 거듭제곱을 각각 더하면 결괏값이 된다.

주요 알고리즘 : 수학, 정수론

출처 : 선린 5회예 E번
*/

long long b3[64] = { 1, };

int main(void) {
    int t;
    long long n, r;
    for (int i = 1; i < 64; i++) b3[i] = b3[i - 1] * 3;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld", &n);
        r = 0;
        for (int i = 0; i < 64; i++) {
            if ((n >> i) & 1) r += b3[i];
        }
        printf("%lld\n", r);
    }
    return 0;
}