#include <stdio.h>

/*
문제 : 자연수 N(N <= 100)을 21로 나눈 나머지를 구한다.

해결 방법 : N을 입력받고 N % 21을 출력하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : JOI 2022예1 1-1번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", n % 21);
    return 0;
}