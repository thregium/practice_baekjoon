#include <stdio.h>

/*
문제 : 크기 2^N(0 <= N <= 10)인 시어핀스키 삼각형을 출력한다.

해결 방법 : 비트 연산자를 이용해 행의 줄 수 & 열 번호가 열 번호와 같은지 확인하면 된다.

주요 알고리즘 : 수학, 구현

출처 : 충남대 2회 C번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = (1 << n) - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            printf("%c", (i & j) == j ? '*' : ' ');
        }
        printf("\n");
    }
    return 0;
}