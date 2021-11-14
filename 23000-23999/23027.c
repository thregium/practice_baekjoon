#include <stdio.h>

/*
문제 : 길이 1000 이하의 대문자로 이루어진 문자열이 주어질 때, 각 문자열을 규칙에 맞게 바꾼 문자열을 출력한다.
'A'가 있다면 'B', 'C', 'D', 'F'를 'A'로 바꾸고,
'A'는 없지만 'B'가 있다면 'C', 'D', 'F'를 'B'로 바꾸고,
'A', 'B'는 없지만 'C'가 있다면 'D', 'F'를 'C'로 바꾼다.
전부 없다면 모든 글자를 'A'로 바꾼다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현, 문자열

출처 : 가톨릭대 3회 A번
*/

char s[1024];

int main(void) {
    int a = 0, b = 0, c = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A') a = 1;
        if (s[i] == 'B') b = 1;
        if (s[i] == 'C') c = 1;
    }
    if (a) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'F') s[i] = 'A';
        }
    }
    else if (b) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'C' || s[i] == 'D' || s[i] == 'F') s[i] = 'B';
        }
    }
    else if (c) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'D' || s[i] == 'F') s[i] = 'C';
        }
    }
    else {
        for (int i = 0; s[i]; i++) {
            s[i] = 'A';
        }
    }
    printf("%s", s);
    return 0;
}
