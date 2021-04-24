#include <stdio.h>

/*
문제 : R * C 크기의 직사각형 형태로 별을 출력한다.

해결 방법 : 문제에 쓰여진대로 구현한다.

주요 알고리즘 : 구현

출처 : AIPO 2017P 1번
*/

int main(void) {
    int r, c;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("*");
        printf("\n");
    }
    return 0;
}