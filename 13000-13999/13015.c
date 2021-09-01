#include <stdio.h>

/*
문제 : N(N <= 100) 크기의 속이 빈 X형태로 별을 출력한다.

해결 방법 : 별을 해당 형태로 출력하면 된다. 공백에 유의한다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) printf("*");
    for (int i = 3; i < n * 2; i++) printf(" ");
    for (int i = 0; i < n; i++) printf("*");
    printf("\n");
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < i; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        for (int j = 2 * i + 3; j < n * 2; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        printf("\n");
    }
    for (int i = 1; i < n; i++) printf(" ");
    printf("*");
    for (int i = 2; i < n; i++) printf(" ");
    printf("*");
    for (int i = 2; i < n; i++) printf(" ");
    printf("*\n");
    for (int i = n - 2; i > 0; i--) {
        for (int j = 0; j < i; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        for (int j = 2 * i + 3; j < n * 2; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        printf("\n");
    }
    for (int i = 0; i < n; i++) printf("*");
    for (int i = 3; i < n * 2; i++) printf(" ");
    for (int i = 0; i < n; i++) printf("*");
    return 0;
}