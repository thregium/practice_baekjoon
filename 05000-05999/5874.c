#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 길이 N(N <= 50000)의 '('와 ')'로 이루어진 문자열이 주어질 때, "((" 이후에 "))"이 오는 순서쌍의 개수를 구한다.

해결 방법 : 먼저 오른쪽부터 부분 문자열 "))"가 들어오는 개수를 센다. 그 다음, 왼쪽부터 읽어나가며 부분 문자열 "(("가
나올 때 마다 오른쪽에 있는 "))"의 개수를 결괏값에 더한다. 마지막까지 한 다음 결괏값이 답이 된다.

주요 알고리즘 : 수학, 조합론, 누적 합

출처 : USACO 2012N B1번
*/

char s[51200];
int rsum[51200];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowfind.in", "r");
        fo = fopen("cowfind.out", "w");
    }
    int l;
    long long r = 0;
    scanf("%s", s);
    l = strlen(s);
    for (int i = l - 1; i >= 0; i--) {
        if (s[i] == ')' && s[i + 1] == ')') rsum[i] = rsum[i + 1] + 1;
        else rsum[i] = rsum[i + 1];
    }

    for (int i = 0; i < l; i++) {
        if (s[i] == '(' && s[i + 1] == '(') r += rsum[i];
    }
    printf("%lld", r);
    return 0;
}