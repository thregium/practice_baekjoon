#include <stdio.h>
#include <string.h>

/*
문제 : 100자 이하의 대문자와 '_'로 이루어진 문자열이 있다. '_'는 10자 이하다. 이 문자열에서
'_'에 대문자를 넣어 만들 수 있는 3 연속으로 자음 또는 모음이 오지 않고 'L'이 1번 이상 나오는
문자열의 개수를 구한다.

해결 방법 : 맨 앞부터 문자열에 'L', 'L'을 제외한 자음, 모음을 각각 넣어보면서
주어진 조건을 만족하는 지 확인한다. 문자열의 끝까지 조건을 만족하는 지 살피고 만족하지 않으면 종료한다.
문자열의 끝에 도달하면 지금까지 넣은 자음(L 제외), 모음의 개수를 확인하며 20^자음 + 5^모음을
답에 더해나간다. 모든 경우를 시도해본 후 나온 값이 답이 된다. 오버플로와 조건 확인에 주의한다.

주요 알고리즘 : 문자열, 브루트 포스, 조합론

출처 : COCI 09/10#3 3번
*/

char s[128];
long long r = 0;

int isvowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
    else return 0;
}

void track(int l, int p, int v, int co, int cl) {
    if (p == l) {
        long long t = 1;
        for (int i = 0; i < v; i++) t *= 5;
        for (int i = 0; i < co; i++) t *= 20;
        if (cl) r += t;
        return;
    }
    if (p >= 2 && s[p] != '_') {
        if (isvowel(s[p]) == isvowel(s[p - 1]) && isvowel(s[p - 1]) == isvowel(s[p - 2])) return;
    }
    if (s[p] == 'L') cl++;
    if (s[p] == '_') {
        if (p < 2 || (isvowel(s[p - 1]) || isvowel(s[p - 2]))) {
            s[p] = 'B';
            track(l, p + 1, v, co + 1, cl);
            s[p] = 'L';
            track(l, p + 1, v, co, cl + 1);
            s[p] = '_';
        }
        if (p < 2 || (!isvowel(s[p - 1]) || !isvowel(s[p - 2]))) {
            s[p] = 'A';
            track(l, p + 1, v + 1, co, cl);
            s[p] = '_';
        }
    }
    else track(l, p + 1, v, co, cl);
}

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    track(l, 0, 0, 0, 0);
    printf("%lld", r);
    return 0;
}