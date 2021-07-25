#include <stdio.h>

/*
문제 : 8진법으로 된 최대 8자리 수가 특수문자 형태로 주어질 때, 무슨 수인지 구한다.

해결 방법 : 각 자릿수들을 미리 저장하놓은 후, 각각과 비교하며 각 자릿수의 값들을 찾은 다음,
8씩 차례로 곱해가며 수들을 앞으로 밀고 찾은 값을 더하여 마지막 자리를 추가하는 것을 반복하면 된다.

주요 알고리즘 : 수학, 사칙연산, 문자열

출처 : NZPC 2006 H번
*/

char s[16];
char* digits = "-\\(@?>&%";

int main(void) {
    long long r = 0;
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        r = 0;
        for (int i = 0; s[i]; i++) {
            r *= 8;
            if (s[i] == '/') r--;
            for (int j = 0; j < 8; j++) {
                if (s[i] == digits[j]) r += j;
            }
        }
        printf("%lld\n", r);
    }
    return 0;
}