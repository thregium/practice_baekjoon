#include <stdio.h>

/*
문제 : N(N <= 1000)번 동전던지기를 했을 때, 예상이 맞은 횟수와 틀린 횟수를 구한다.

해결 방법 : 예상과 결과가 같으면 맞은 경우이고 다르면 틀린 경우이다. 이 둘을 각각 세면 된다.

주요 알고리즘 : 구현

출처 : NZPC 2007 A번
*/

char p1[32], p2[32];

int main(void) {
    int n, r1, r2;
    char c1, c2;
    while (1) {
        scanf("%s %s", p1, p2);
        if (p1[0] == '#') break;
        scanf("%d", &n);
        r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %c %c", &c1, &c2);
            if (c1 == c2) r1++;
            else r2++;
        }
        printf("%s %d %s %d\n", p1, r1, p2, r2);
    }
    return 0;
}