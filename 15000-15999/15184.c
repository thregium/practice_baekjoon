#include <stdio.h>
#include <ctype.h>

/*
문제 : 250자 이하의 문자열이 주어질 때, 각 알파벳의 등장 횟수를 구한다. 대소문자는 구분하지 않는다.

해결 방법 : 알파벳이 나오면 알파벳을 소문자로 바꾸어 각각의 등장 횟수를 구한다. 그 다음, 등장 횟수를 형식에 맞게 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : NZPC 2017 G번
*/

char s[256];
int cnt[26];

int main(void) {
    fgets(s, 253, stdin);
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            cnt[tolower(s[i]) - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%c | ", 'A' + i);
        for (int j = 0; j < cnt[i]; j++) printf("*");
        printf("\n");
    }
    return 0;
}