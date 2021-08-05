#include <stdio.h>

/*
문제 : 주어진 세 수의 합이 180인지 구한다.

해결 방법 : 세 수의 합이 180인지 확인해보면 된다.

주요 알고리즘 : 구현?

출처 : NZPC 2017 A번
*/

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a + b + c == 180) printf("%d %d %d Seems OK\n", a, b, c);
        else printf("%d %d %d Check\n", a, b, c);
    }
    return 0;
}