#include <stdio.h>
#include <string.h>

/*
문제 : 10자 이하의 소문자로 이루어진 문자열이 주어질 때, 이 문자열의 거울 대칭상인 문자열을 구한다.
b의 거울 대칭은 d이고, p의 거울 대칭은 q이다. i, o, v, w, x는 자기 자신의 거울 대칭이다. 하지만 나머지 문자들은 거울 대칭이 없다.
거울 대칭상이 없는 문자열이라면 INVALID를 출력한다.

해결 방법 : 각 문자마다 거울 대칭상이 있는지 확인하고 반대 위치에 해당 문자를 추가한다.
만약 없는 경우에는 거울 대칭상을 만들 수 없으므로 종료하고 INVALID를 출력하면 된다. 끝까지 만들었다면
지금까지 만든 문자열을 출력한다.

주요 알고리즘 : 구현, 문자열

출처 : MidC 2010 E번
*/

char s[16], m[16];

int main(void) {
    int l, r;
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        l = strlen(s);
        r = 1;
        m[l] = '\0';
        for (int i = 0; i < l; i++) {
            if (s[i] == 'b') m[l - i - 1] = 'd';
            else if (s[i] == 'd') m[l - i - 1] = 'b';
            else if (s[i] == 'p') m[l - i - 1] = 'q';
            else if (s[i] == 'q') m[l - i - 1] = 'p';
            else if (s[i] == 'i' || s[i] == 'o' || s[i] == 'v' || s[i] == 'w' || s[i] == 'x') m[l - i - 1] = s[i];
            else {
                r = 0;
                break;
            }
        }
        if (r) printf("%s\n", m);
        else printf("INVALID\n");
    }
    return 0;
}