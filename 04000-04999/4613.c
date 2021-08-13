#include <stdio.h>
#include <ctype.h>

/*
문제 : 256자 미만 길이의 대문자 또는 공백으로 이루어진 문자열이 주어질 때, 각 문자열의 Quicksum을 구한다.
Quicksum은 각 문자의 위치에 문자의 번호(X번째 알파벳)를 곱한 값들을 모두 더한 값이다. 공백인 칸의 번호는 0이다.

해결 방법 : 문자열의 각 문자들을 확인하며 알파벳인 경우 문자의 번호에 문자의 위치를 결괏값에 더해준다.
마지막까지 더한 다음 결괏값을 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : MidC 2006 A번
*/

char s[320];

int main(void) {
    int r;
    while (1) {
        fgets(s, 300, stdin);
        if (s[0] == '#') break;
        r = 0;
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) r += (s[i] - 'A' + 1) * (i + 1);
        }
        printf("%d\n", r);
    }
    return 0;
}