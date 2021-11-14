#include <stdio.h>
#include <string.h>

/*
문제 : 길이 500 이하의 DNA 문자열이 주어질 때, 부분 배열에서 a-t, g-c로 만든 괄호 문자열의 최대 개수를 구한다.

해결 방법 : 다이나믹 프로그래밍을 이용한다. 범위를 좁혀나가며 탑다운 방식으로 하면 된다.

주요 알고리즘 : DP

출처 : 정올 2005 중2번
*/

char s[512];
int mem[512][512];

int big(int a, int b) {
    return a > b ? a : b;
}

int dp(int st, int ed) {
    if (st >= ed) return 0;
    if (mem[st][ed] >= 0) return mem[st][ed];

    int r = 0;
    if ((s[st] == 'a' && s[ed] == 't') || (s[st] == 'g' && s[ed] == 'c')) r = dp(st + 1, ed - 1) + 2;
    for (int i = st; i < ed; i++) {
        r = big(r, dp(st, i) + dp(i + 1, ed));
    }
    return mem[st][ed] = r;
}

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    memset(mem, -1, sizeof(int) * 262144);
    printf("%d", dp(0, l - 1));
    return 0;
}