#include <stdio.h>

/*
문제 : N(N <= 100000)이 주어질 때, N의 우박 수열을 출력한다.
우박 수열은 A_n이 홀수인 경우 A_(n+1)은 A_n * 3 + 1이 되고, 짝수인 경우 A_n / 2가 되는 수열로, 1이 되면 끝난다.

해결 방법 : 문제에 설명한대로 구현한다.

주요 알고리즘 : 구현, 수학, 사칙연산

출처 : AIPO 2016P 3번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    while (n > 1) {
        printf("%d ", n);
        if (n & 1) n = n * 3 + 1;
        else n >>= 1;
    }
    printf("1");
    return 0;
}