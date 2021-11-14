#include <stdio.h>
#include <stdlib.h>

/*
문제 : 7자 이하의 A진법 수를 B진법으로 출력한다. 단, 7자를 넘는 경우 ERROR를 출력한다.

해결 방법 : strtoll 함수를 이용해 정수형으로 바꿔준 다음, 이를 역순으로 구해가며 답을 찾아나간다.
이때 7자를 전부 사용했어도 수가 0이 아니라면 ERROR를 출력해야 한다.

주요 알고리즘 : 구현, 수학, 문자열

출처 : MidC 1995 5번
*/

char s[16], e[16];

int main(void) {
    int a, b, x;
    while (scanf("%s %d %d", s, &a, &b) != EOF) {
        x = strtoll(s, NULL, a);
        for (int i = 0; i < 7; i++) e[i] = ' ';
        for (int i = 6; i >= 0; i--) {
            if (x % b < 10) e[i] = x % b + '0';
            else e[i] = x % b - 10 + 'A';
            x /= b;
            if (x == 0) break;
        }
        if (x) printf("  ERROR\n");
        else printf("%s\n", e);
    }
    return 0;
}