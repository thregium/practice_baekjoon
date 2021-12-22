#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^6)이 주어질 때, 1부터 N까지의 각 수의 약수의 합의 합을 구한다.

해결 방법 : 1부터 N까지 각 수를 약수로 하는 수들에 대해 해당 수의 합을 구한다.
이를 N까지 반복하며 합을 구해나가면 된다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) r += i;
    }
    printf("%lld", r);
    return 0;
}