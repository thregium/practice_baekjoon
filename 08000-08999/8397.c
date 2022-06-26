#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 음이 아닌 정수(<= 10^8)가 주어진다. 1개 이상의 수를 골라서 나오는
선택한 수의 곱의 모든 경우의 수에 대한 합을 x라 할 때, F(x)의 값을 구한다.
F(x)는 x가 9 이하인 경우 x를, 10 이상인 경우 자릿수의 합을 d라고 할 때 F(d)를 반환하는 함수이다.

해결 방법 : F(n)을 하기 전 나오는 값은 식을 정리해보면 (a_1 + 1)(a_2 + 1)...(a_n + 1) - 1임을 알 수 있다.
F(n)은 n이 0인 경우 0, 그 외에 9로 나눈 나머지가 0이라면 9, 그 외 경우에는 9로 나눈 나머지이다.
그 값을 계산하면 된다.

주요 알고리즘 : 수학, 조합론, 정수론

출처 : PA 2006 3-1번
*/

int main(void) {
    int n, x, nz = 0;
    long long res = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > 0) nz = 1;
        res *= x + 1;
        res %= 9;
    }
    if (!nz) {
        printf("0");
        return 0;
    }
    res += 8;
    res %= 9;
    if (res == 0) printf("9");
    else if (res > 0 && res < 9) printf("%lld", res);
    else return 1;
    return 0;
}