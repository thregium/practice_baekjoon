#include <stdio.h>

/*
문제 : 주어진 덧셈 또는 뺄셈 식이 맞는지 구한다.

해결 방법 : 식이 덧셈인지 뺄셈인지를 확인한 다음 맞는지 확인해보면 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : Tunisia 2013 J번
*/

int main(void) {
    int t, x, y, z;
    char o;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %c %d = %d", &x, &o, &y, &z);
        printf("Case %d: ", tt);
        if (o == '+') {
            if (x + y == z) printf("YES\n");
            else printf("NO\n");
        }
        else {
            if (x - y == z) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}