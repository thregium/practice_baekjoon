#include <stdio.h>

/*
문제 : 길이 3000 이하의 문자열 w와 w보다 길이가 길고 3 * 10^6 이하 길이의 문자열 s가 있다.
s 안에 w의 아나그램 관계인 부분 문자열의 개수를 센다.

해결 방법 : 문자열 w에 등장하는 각 알파벳의 개수를 센 다음, 슬라이딩 윈도우를 통해 S의 길이 G인
모든 부분 문자열에 대해 알파벳의 개수가 문자열 w의 개수와 같은 것의 수를 세면 된다.

주요 알고리즘 : 문자열, 슬라이딩 윈도우

출처 : IOI 2006_1 1번
*/

char w[3072], s[3145728];
int wcnt[52], scnt[52];

int toint(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    else return c - 'A' + 26;
}

int issame(int* a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main(void) {
    int g, l, res = 0;
    scanf("%d %d", &g, &l);
    scanf("%s%s", w, s);
    for (int i = 0; i < g; i++) {
        wcnt[toint(w[i])]++;
        scnt[toint(s[i])]++;
    }
    res += issame(wcnt, scnt, 52);
    for (int i = g; i < l; i++) {
        scnt[toint(s[i])]++;
        scnt[toint(s[i - g])]--;
        res += issame(wcnt, scnt, 52);
    }
    printf("%d", res);
    return 0;
}