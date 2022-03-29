#include <stdio.h>

/*
문제 : 고장난 계산기가 있다. 각 연산에 따라 결괏값이 다르게 정의되었을 때, 연산자와 연산할
두 수(<= 100000, 음이 아닌 정수)가 주어지면 매번 결괏값을 구한다.

해결 방법 : 연산자에 따라 경우를 나누어 답을 구하고 출력하면 된다.

주요 알고리즘 : 수학, 구현, 케이스 워크

출처 : VTTH 2019 M번
*/

int main(void) {
    int n;
    long long a, b, l = 1, r;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %c %lld", &a, &c, &b);
        if (c == '*') r = (a * b) * (a * b);
        else if (c == '+') r = a + b - l;
        else if (c == '-') r = (a - b) * l;
        else if (c == '/') r = ((a + 1) >> 1);
        else return 1;
        l = r;
        printf("%lld\n", r);
    }
    return 0;
}