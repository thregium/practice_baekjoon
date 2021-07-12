#include <stdio.h>

/*
문제 : 주어진 문자열에서 모음의 수를 센다.

해결 방법 : 각 문자들이 모음인지 확인한 후 모음인 문자의 수를 세면 된다.

주요 알고리즘 : 문자열, 구현

출처 : NZPC 2006 A번
*/

char s[512];
char* vowel = "aeiouAEIOU";

int main(void) {
    int cnt;
    while (1) {
        cnt = 0;
        fgets(s, 384, stdin);
        if (s[0] == '#') break;
        for (int i = 0; s[i]; i++) {
            for (int j = 0; vowel[j]; j++) {
                if (s[i] == vowel[j]) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}