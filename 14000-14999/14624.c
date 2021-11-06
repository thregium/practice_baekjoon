#include <stdio.h>

/*
문제 : N이 홀수면 문제에 N 크기의 주어진 형태로 별을 출력하고, 짝수면 I LOVE CBNU를 출력한다.

해결 방법 : N이 짝수인지 먼저 확인하고 홀수인 경우 별을 N개 출력한 다음, (N + 1) / 2줄 동안
대칭적으로 별들을 출력하면 된다.

주요 알고리즘 : 구현

출처 : 전북대 2017 A번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if (n & 1) {
        for (int i = 0; i < n; i++) printf("*");
        printf("\n");
        for (int i = (n >> 1); i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == i || j == (n - i - 1)) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
    else printf("I LOVE CBNU");
    return 0;
}