#include <stdio.h>

/*
문제 : 삼각형의 세 변의 길이가 주어질 때, 주어진 삼각형이 직각삼각형인지 구한다.

해결 방법 : 피타고라스의 정리에 따르면 가장 긴 변의 길이의 제곱이 다른 두 변의 제곱의 합과 같다면 직각삼각형이다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : TUD 2008 8번
*/

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int nn = 1; nn <= n; nn++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Scenario #%d:\n", nn);
        if (a > b && a > c) {
            if (a * a == b * b + c * c) printf("yes");
            else printf("no");
        }
        else if (b > a && b > c) {
            if (b * b == a * a + c * c) printf("yes");
            else printf("no");
        }
        else if (c > a && c > b) {
            if (c * c == a * a + b * b) printf("yes");
            else printf("no");
        }
        else printf("no");
        printf("\n\n");
    }
    return 0;
}