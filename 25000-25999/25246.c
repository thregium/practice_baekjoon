#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 50자 이하의 알파벳 문자열이 주어질 때, 이 문자열의 마지막 모음 뒤에 있는 문자들을 지우고
"ntry" 문자열을 추가한 문자열을 출력한다. 문자열에 모음은 적어도 하나 이상 있다.

해결 방법 : 문자열의 뒤에서부터 확인하며 자음인 경우 그 글자를 지우고 모음인 경우 탐색을 종료한다.
그리고 그 문자열에 "ntry"를 붙여 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : GCPC 2021 B번
*/

char s[64];

int isvowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}

int main(void) {
    scanf("%s", s);
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (!isvowel(tolower(s[i]))) s[i] = '\0';
        else break;
    }
    printf("%sntry", s);
    return 0;
}