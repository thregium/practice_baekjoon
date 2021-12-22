#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 정사각형의 테두리를 @로 출력한다.

해결 방법 : (N + 2) * (N + 2) 크기의 정사각형을 출력하되 테두리만 @로 출력하면 된다.

주요 알고리즘 : 구현
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = -1; i <= n; i++) {
        for (int j = -1; j <= n; j++) {
            printf("%c", (i < 0 || j < 0 || i == n || j == n) ? '@' : ' ');
        }
        printf("\n");
    }
    return 0;
}