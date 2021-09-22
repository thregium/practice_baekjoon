#include <stdio.h>

/*
문제 : 카드 번호가 주어질 때, 주어진 카드 번호가 유효한지 구한다.

해결 방법 : 체크섬을 구한 후, 이 값이 맞는지 확인해보면 된다.

주요 알고리즘 : 구현, 수학

출처 : 중앙대 2017C A번
*/

char s[32];

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        r = 0;
        for (int i = 0; i < 16; i++) {
            if (i & 1) r += s[i] - '0';
            else r += ((s[i] - '0') * 2) % 10 + ((s[i] - '0') * 2) / 10;
        }
        if (r % 10) printf("F\n");
        else printf("T\n");
    }
    return 0;
}