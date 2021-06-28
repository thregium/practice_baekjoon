#include <stdio.h>

/*
문제 : 현재 현금과 인출/저금 여부, 인출/저금액이 주어질 때, 인출/저금한 결과를 구한다.
단, 잔액이 -200 아래로 내려갈 수는 없다.

해결 방법 : 경우를 나누어 잔액을 구한 다음, -200 아래로 내려가는지 다시 확인하면 된다.

주요 알고리즘 : 구현

출처 : NZPC 2004 X번
*/

int main(void) {
    int a, b;
    char c;
    while (1) {
        scanf("%d %c %d", &a, &c, &b);
        if (a == 0 && b == 0 && c == 'W') break;
        if (c == 'W') {
            if (a - b < -200) printf("Not allowed\n");
            else printf("%d\n", a - b);
        }
        else printf("%d\n", a + b);
    }
    return 0;
}