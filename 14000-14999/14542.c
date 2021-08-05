#include <stdio.h>

/*
문제 : 높이/너비가 N(N <= 10)인 직각이등변삼각형 형태로 수들이 주어질 때, 테두리에 있는 수들의 합을 구한다.

해결 방법 : 2중 for문 형태로 수들을 입력받는다. 이때 j가 맨 왼쪽 또는 오른쪽에 있거나 i가 맨 위 또는 맨 아래 부분이면 테두리이다.
이러한 경우의 수들을 합한 결과를 출력하면 된다.

주요 알고리즘 : 구현

출처 : Khawarizmi 2016 J번
*/

int main(void) {
    int n, x, s;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        s = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                scanf("%d", &x);
                if (j == 1 || j == i || i == n) s += x;
            }
        }
        printf("Case #%d:%d \n", tt, s);
    }
    return 0;
}
