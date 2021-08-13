#include <stdio.h>

/*
문제 : 9자리 이하의 자연수 N이 주어질 때, 이 자연수를 모든 자릿수의 곱으로 바꾸는 작업을 몇 회 반복하면 한 자리 수가 되는지 구한다.

해결 방법 : 값이 빠르게 줄어들기 때문에 직접 모든 자릿수의 곱을 구해가며 몇 번째에 한 자리 수가 되는지 확인하면 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : SEUSA 2015D2 I번
*/

int main(void) {
    long long n, x;
    int r = 0;
    scanf("%lld", &n);
    while (n >= 10) {
        x = 1;
        for (long long i = n; i; i /= 10) x *= i % 10;
        r++;
        n = x;
    }
    printf("%d", r);
    return 0;
}