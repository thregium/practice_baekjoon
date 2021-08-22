#include <stdio.h>

/*
문제 : 합이 S(S <= 100)인 K(K <= 20)개의 자연수에 대해 곱을 최대로 할 때의 곱을 구한다.

해결 방법 : 가장 큰 수와 가장 작은 수의 차이가 적을 수록 곱이 커진다. 따라서, 모든 수가 S / K 또는 S / K + 1인 경우
곱이 최대가 되고, 이때의 값을 구하면 된다.

주요 알고리즘 : 수학
*/

int main(void) {
    int s, k;
    long long r = 1;
    scanf("%d %d", &s, &k);
    for (int i = 0; i < s % k; i++) {
        r *= s / k + 1;
    }
    for (int i = s % k; i < k; i++) {
        r *= s / k;
    }
    printf("%lld", r);
    return 0;
}