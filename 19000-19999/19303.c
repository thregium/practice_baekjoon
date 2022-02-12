#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^15)의 약수의 산술평균이 A, 조화평균이 H일 때 A와 H가 주어지면, N을 구한다.
A와 H는 자연수이다.

해결 방법 : 모든 N에 대해 약수의 산술평균과 조화평균을 곱하면 N이 되는 것을 알 수 있다.
따라서, A * H를 구하면 된다.

주요 알고리즘 : 수학

출처 : Petro 2018W6 A번
*/

int main(void) {
    long long a, h;
    scanf("%lld %lld", &a, &h);
    printf("%lld", a * h);
    return 0;
}