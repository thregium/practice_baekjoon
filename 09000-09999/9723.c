#include <stdio.h>

/*
문제 : T(T <= 100000)번 삼각형의 세 변의 길이 A, B, C(A, B, C <= 100)가 주어질 때, 이 삼각형이 직각삼각형인지 구한다.

해결 방법 : 피타고라스의 정리를 통해 두 변의 길이의 제곱이 다른 한 변의 길이의 제곱이 되는 경우가 있는지 확인해보면 된다.

주요 알고리즘 : 기하학, 피타고라스

출처 : Khwarizmi 2010 A번
*/

int main(void) {
    int t, a, b, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", tt);
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}