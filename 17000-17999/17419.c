#include <stdio.h>

/*
문제 : N(N <= 10^6) 비트 이진수 K가 주어질 때, K가 0이 되기까지 K = K-(K&((~K)+1))를 몇 회 해야 하는지 구한다.

해결 방법 : 이 연산은 K의 LSB를 0으로 바꾸는 연산이다. 따라서, 0이 될 때 까지 1인 비트의 개수만큼 연산이 일어난다.

주요 알고리즘 : 수학, 비트마스킹

출처 : 선린 2019 A번
*/

char s[1048576];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        r += s[i] - '0';
    }
    printf("%d", r);
    return 0;
}