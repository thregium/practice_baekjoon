#include <stdio.h>

/*
문제 : @로 이루어진 'ㅂ'자를 N(N <= 100)배한 형태를 출력한다.

해결 방법 : 각 부분을 나누어 출력하면 된다. 세로선 출력 부분은 @   @를 N * N배한 형태이고,
가로선 출력 부분은 @를 N * (N * 5)배 한 형태이다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n; j++) printf("@");
        for (int j = 0; j < n * 3; j++) printf(" ");
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("@");
        for (int j = 0; j < n * 3; j++) printf(" ");
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    return 0;
}