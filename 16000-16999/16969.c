#include <stdio.h>
#define MOD 1000000009

/*
문제 : 각 자리에 숫자 또는 알파벳 소문자를 넣을 수 있는 길이 10^6 이하의 번호판이 있다. 
이 번호판의 인접한 자리에는 같은 문자를 넣을 수 없다.
이 번호판의 각 자리에 넣을 수 있는 값(숫자, 알파벳)이 주어질 때, 만들 수 있는 문자열의 가짓수를 구한다.

해결 방법 : 알파벳은 26자이고, 숫자는 10자이므로 숫자가 나오면 10가지 경우, 알파벳이 나오면 26가지 경우를 이전 단계에서
곱할 수 있다. 단, 이전 자리가 같은 종류의 문자를 넣을 수 있다면 같은 문자를 넣을 수 없으므로 숫자인 경우 9가지,
알파벳인 경우 25가지를 곱해나간다.

주요 알고리즘 : 수학, 조합론
*/

char s[1048576];

int main(void) {
    int r = 1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'c') {
            if (i == 0 || s[i - 1] != s[i]) r = (long long)r * 26 % MOD;
            else r = (long long)r * 25 % MOD;
        }
        else if (s[i] == 'd') {
            if (i == 0 || s[i - 1] != s[i]) r = (long long)r * 10 % MOD;
            else r = (long long)r * 9 % MOD;
        }
        else return 1;
    }
    printf("%d", r);
    return 0;
}