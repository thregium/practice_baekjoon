#include <stdio.h>

/*
문제 : N * M 크기로 수들을 출력한다.

해결 방법 : 2중 for 문을 사용하면 된다. 공백에 주의한다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", i * m + j + 1);
            if (j < m - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}