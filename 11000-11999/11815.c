#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 100)개의 수에 대해 자연수 X(X <= 10^18)가 주어질 때, X의 약수 개수가 짝수인지 홀수인지 구한다.

해결 방법 : X가 제곱수인 경우 약수 개수는 홀수이고, 제곱수가 아니라면 짝수이다. sqrt 함수를 이용하여 제곱근을 구하되
실수 오차를 고려해 주위 수들까지 확인한다. 만약 그들 중 제곱하여 정확히 X가 되는 수가 있다면 이 수는 제곱수이다.

주요 알고리즘 : 수학, 정수론

출처 : IZhO 2009 A번
*/

int main(void) {
    int n, r;
    long long x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        y = sqrt(x);
        r = 0;
        for (long long j = y - 10000; j <= y + 10000; j++) {
            if (j * j == x) r = 1;
        }
        printf("%d ", r);
    }
    return 0;
}