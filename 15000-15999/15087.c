#include <stdio.h>
#include <string.h>

/*
문제 : 암호화된 15000자 이하의 문자열(대문자)이 주어질 때, 이 문자열을 문제에 주어진 방식대로 복호화한다.
문자열을 둘로 쪼개고 문자열의 합을 기준으로 문자들을 돌린 다음, 둘을 합치는 방식이다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현, 문자열

출처 : ECNA 2017 C번
*/

char s[16384];

void rot(int st, int ed) {
    int sum = 0;
    for (int i = st; i < ed; i++) {
        sum += s[i] - 'A';
    }
    for (int i = st; i < ed; i++) {
        s[i] = ((s[i] - 'A') + sum) % 26 + 'A';
    }
}

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    if (l & 1) return 1;
    rot(0, l >> 1);
    rot(l >> 1, l);
    for (int i = 0; i < (l >> 1); i++) {
        printf("%c", ((s[i] - 'A') + (s[i + (l >> 1)] - 'A')) % 26 + 'A');
    }
    return 0;
}