#include <stdio.h>
#include <ctype.h>

/*
문제 : 카멜 표기법, 스네이크 표기법, 파스칼 표기법 중 하나로 표기된 변수명을 카멜, 스네이크, 파스칼 표기법으로 각각 변환한다.
변수명은 최대 100자이고, 알파벳과 언더바(스네이크 표기법인 경우)로만 이루어져 있다.

해결 방법 : 카멜 표기법으로 입력된 경우, 파스칼 표기법으로는 첫 글자만 대문자로 바꾸면 된다. 스네이크 표기법으로는
대문자가 나올 때 마다 언더바를 앞에 입력하면 된다.
스네이크 표기법으로 입력된 경우 카멜 표기법으로는 첫 자가 아니며 앞 문자가 언더바인 경우 대문자,
그 외에는 소문자로 표기하면 되고, 파스칼 표기법으로는 카멜 표기법에 첫 자를 대문자로 바꾸면 된다.
파스칼 표기법으로 입력된 경우에는 카멜 표기법으로는 첫 글자를 소문자로 바꾸면 되고, 스네이크 표기법으로는
첫 자를 제외하고 대문자가 나올 때 마다 언더바를 앞에 입력하면 된다.

주요 알고리즘 : 문자열, 구현
*/

char s[128];

int main(void) {
    int n;
    scanf("%d %s", &n, s);
    switch (n) {
    case 1:
        printf("%s\n", s);
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) printf("_");
            printf("%c", tolower(s[i]));
        }
        printf("\n%c%s", toupper(s[0]), s + 1);
        break;
    case 2:
        for (int i = 0; s[i]; i++) {
            if (!isalpha(s[i])) continue;
            if (i > 0 && s[i - 1] == '_') printf("%c", toupper(s[i]));
            else printf("%c", s[i]);
        }
        printf("\n%s\n", s);
        for (int i = 0; s[i]; i++) {
            if (!isalpha(s[i])) continue;
            if (i == 0 || s[i - 1] == '_') printf("%c", toupper(s[i]));
            else printf("%c", s[i]);
        }
        break;
    case 3:
        printf("%c%s\n", tolower(s[0]), s + 1);
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i]) && i > 0) printf("_");
            printf("%c", tolower(s[i]));
        }
        printf("\n%s", s);
        break;
        break;
    default:
        break;
    }
    return 0;
}