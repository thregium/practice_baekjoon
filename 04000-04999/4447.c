#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 각 사람의 이름에 있는 B와 G의 개수를 비교해서 더 많은 것을 찾는다. 대소문자를 구별하지 않아야 한다. 이름은 최대 25자이다.

해결 방법 : 이름의 모든 글자에 대해 소문자로 바꾸어 b와 g의 개수를 각각 센 다음 둘의 개수를 비교하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : PacNW 2011 A번
*/

char s[64];

int main(void) {
    int n, b, g;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 60, stdin);
        b = 0, g = 0;
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        for (int i = 0; s[i]; i++) {
            if (tolower(s[i]) == 'b') b++;
            else if (tolower(s[i]) == 'g') g++;
        }
        if (b > g) printf("%s is A BADDY\n", s);
        else if (b < g) printf("%s is GOOD\n", s);
        else printf("%s is NEUTRAL\n", s);
    }
    return 0;
}