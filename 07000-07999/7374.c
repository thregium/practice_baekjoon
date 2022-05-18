#include <stdio.h>

/*
문제 : 

해결 방법 : 미리 계산해둔다.

주요 알고리즘 : 런타임 전의 전처리

출처 : CERC 1995 F번
*/

const int hard[14] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", hard[n]);
    }
    return 0;
}