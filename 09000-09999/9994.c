#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 길이 100 이하의 문자열이 주어질 때, 이 문자열이 되는 비밀 문자열을 만드는 방법의 가짓수를 구한다.
비밀 문자열은 특정한 문자열의 맨 앞 글자 또는 맨 뒷 글자를 지운 것을 해당 문자열의 맨 앞 또는 맨 뒤에 붙이는 것을 반복해서
문자열을 만드는 것이고, 결과가 같더라도 붙인 또는 지운 위치가 다르다면 다른 방법이다.

해결 방법 : 해당 문자열의 길이가 홀수라면 이전 단계의 비밀 문자열이 될 수 있는 4가지 경우가 나온다.
이는 문자열의 시작점과 길이를 알면 겹치는 부분을 확인하여 비밀 문자열이 될 수 있는 경우인지 확인하고 재귀적으로 풀면 된다.
같은 곳을 확인하더라도 서로 다른 경우가 될 수 있음에 유의한다.

주요 알고리즘 : 브루트 포스, 재귀

출처 : USACO 2014F B3번
*/

char s[128];

int track(int st, int l) {
    int tmp1 = 1, tmp2 = 1, tmp3 = 1;
    int r = 1;
    if (~l & 1) return r;
    for (int i = 0; i < (l >> 1); i++) {
        if (s[st + i] != s[st + i + (l >> 1)]) tmp1 = 0;
    }
    for (int i = 0; i < (l >> 1); i++) {
        if (s[st + i] != s[st + i + (l >> 1) + 1]) tmp2 = 0;
    }
    for (int i = 0; i < (l >> 1); i++) {
        if (s[st + i + 1] != s[st + i + (l >> 1) + 1]) tmp3 = 0;
    }
    if (tmp2 || tmp3) {
        r += track(st, (l >> 1) + 1) * (tmp2 + tmp3);
    }
    if (tmp1 || tmp2) {
        r += track(st + (l >> 1), (l >> 1) + 1) * (tmp1 + tmp2);
    }
    return r;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("scode.in", "r");
        fo = fopen("scode.out", "w");
    }
    int len;
    scanf("%s", s);
    len = strlen(s);
    printf("%d", track(0, len) - 1);
    return 0;
}