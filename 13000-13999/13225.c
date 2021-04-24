#include <stdio.h>

/*
문제 : N(N <= 10000)이 주어질 때, N의 약수의 갯수를 출력한다.

해결 방법 : N의 약수는 최대 N인 자연수이므로, 1부터 N까지 반복하며 N을 나눈 나머지가 0일 때마다 갯수를 센다.

주요 알고리즘 : 수학, 사칙연산

출처 : AIPO 2015P 5번
*/

int main(void) {
    int c, n, r;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &n);
        r = 0;
        for (int j = 1; j <= n; j++) {
            if (n % j == 0) r++;
        }
        printf("%d %d\n", n, r);
    }
    return 0;
}