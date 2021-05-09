#include <stdio.h>

/*
문제 : 10자 미만의 문자열이 주어진다. 이 문자열들을 각 줄에 (각 문자의 아스키 코드 값의 자릿수 합)번씩 반복해서 출력한다.

해결 방법 : 문제에 있는대로 구현한다.

주요 알고리즘 : 구현

출처 : 숙명여대 1회 A번
*/

char s[16];

int main(void) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        for (int j = 0; j < s[i] / 100 + s[i] / 10 % 10 + s[i] % 10; j++) printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}