#include <stdio.h>

/*
문제 : N * N(N <= 20) 크기의 정사각형의 테두리와 양 대각선에 "*"를 표시한 그림을 출력한다.

해결 방법 : 문제에 주어진대로 구현한다. 1일 때의 예외에 주의한다.

주요 알고리즘 : 구현

출처 : 충남대 5회 A번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("*");
        return 0;
    }
    for (int i = 0; i < n; i++) printf("*");
    printf("\n");
    for (int i = 0; i < n - 2; i++) {
        printf("*");
        for (int j = 0; j < n - 2; j++) {
            if (i == j || i + j == n - 3) printf("*");
            else printf(" ");
        }
        printf("*");
        printf("\n");
    }
    for (int i = 0; i < n; i++) printf("*");
    return 0;
}