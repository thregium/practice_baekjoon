#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^6)이 주어질 때, o * 2^p = N이 되는 홀수 o와 음이 아닌 정수 p를 구한다.

해결 방법 : N을 홀수가 될 때 까지 2로 계속 나눈다. 2로 나눈 횟수가 P이고, 남은 N이 O가 된다.

주요 알고리즘 : 수학, 정수론

출처 : CERC 2002 PA번
*/

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    while (~n & 1) {
        n >>= 1;
        r++;
    }
    printf("%d %d", n, r);
    return 0;
}