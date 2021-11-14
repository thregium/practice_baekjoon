#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)개의 문자열(3자 이상 30자 이하, 소문자)가 주어지면
문제에 주어진 방식대로 라틴어 형태로 바꾼 문자열을 출력한다.

해결 방법 : 문제에 주어진대로 구현한다. 'ne'로 끝날 때에 주의한다.

주요 알고리즘 : 구현, 케이스 워크

출처 : Seoul 2018 D번
*/

char s[64];

int main(void) {
    int n, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) s[j] = '\0';
        scanf("%s", s);
        l = strlen(s);
        if (l <= 2) return 1;
        if (s[l - 1] == 'a' || s[l - 1] == 'o' || s[l - 1] == 'u') s[l] = 's';
        else if (s[l - 1] == 'i' || s[l - 1] == 'y') {
            s[l - 1] = 'i';
            s[l] = 'o';
            s[l + 1] = 's';
        }
        else if (s[l - 1] == 'l' || s[l - 1] == 'r' || s[l - 1] == 'v') {
            s[l] = 'e';
            s[l + 1] = 's';
        }
        else if (s[l - 1] == 't' || s[l - 1] == 'w') {
            s[l] = 'a';
            s[l + 1] = 's';
        }
        else if (s[l - 1] == 'n') {
            s[l - 1] = 'a';
            s[l] = 'n';
            s[l + 1] = 'e';
            s[l + 2] = 's';
        }
        else if (s[l - 2] == 'n' && s[l - 1] == 'e') {
            s[l - 2] = 'a';
            s[l - 1] = 'n';
            s[l] = 'e';
            s[l + 1] = 's';
        }
        else {
            s[l] = 'u';
            s[l + 1] = 's';
        }
        printf("%s\n", s);
    }
    return 0;
}