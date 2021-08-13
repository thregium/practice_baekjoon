#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 주어진 문자열이 팰린드롬인지 확인한다. 대소문자가 다르더라도 같은 글자로 생각한다.

해결 방법 : 주어진 문자열에 대해 맨 앞과 맨 뒤부터 글자를 읽어가며 소문자로 바꾼 두 문자가 같은지 확인한다.
만약 다른 문자가 하나라도 있다면 팰린드롬이 아니고 없다면 팰린드롬이다.

주요 알고리즘 : 문자열

출처 : PLU 2014N 5번
*/

char s[1024];

int main(void) {
    int n, r;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 1000, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (strlen(s) > 500) return 1;
        r = 1;
        for (int x = 0, y = strlen(s) - 1; x < y; x++, y--) {
            if (tolower(s[x]) != tolower(s[y])) r = 0;
        }
        printf("%s\n", r ? "Yes" : "No");
    }
    return 0;
}