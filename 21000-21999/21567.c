#include <stdio.h>

/*
문제 : 세 자연수 A, B, C(A, B, C <= 10^6)가 주어질 때, 세 수의 곱에 쓰인 각 숫자의 개수를 출력한다.

해결 방법 : 세 수의 곱을 구한 다음, 자릿수를 하나씩 떼어서 확인하면 된다.

주요 알고리즘 : 구현, 사칙연산
*/

int cnt[10];

int main(void) {
    long long a, b, c, d;
    scanf("%lld %lld %lld", &a, &b, &c);
    d = a * b * c;
    for (long long i = d; i; i /= 10) {
        cnt[i % 10]++;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}