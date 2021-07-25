#include <stdio.h>

/*
문제 : 별을 N * N 크기의 삼각형 형태로 출력한다.

해결 방법 : 출력한다.

주요 알고리즘 : 구현

출처 : NZPC 2008 A번
*/

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) printf("*");
            printf("\n");
        }
    }
    return 0;
}