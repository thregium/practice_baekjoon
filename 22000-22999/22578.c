#include <stdio.h>
#include <string.h>

/*
문제 : 길이 500 이하의 'm', 'e', 'w'로 이루어진 문자열이 주어진다. 이 문자열의 부분 가운데
'm'과 'w'로 끝나고 사이에 'e'가 들어가며 그 양옆으로 mew 문자열이 나오는 경우,
또는 빈 문자열인 경우 mew 문자열이다. 이때, 주어진 문자열이 mew 문자열인 지 확인한다.

해결 방법 : 문자열을 쪼개가며 mew 문자열인 지 확인한다. 이때, 같은 연산을 반복하면
수행 시간이 길어지므로 같은 범위의 결과는 메모이제이션을 통해 시간을 절약한다.

주요 알고리즘 : DP, 문자열, 분할 정복?

출처 : JAG 2011W3 A번
*/

char s[512];
int mem[512][512];

int iscat(int st, int ed) {
    if (st > ed) return mem[st][ed] = 1;
    if (s[st] != 'm' || s[ed] != 'w' || (ed - st) % 3 != 2) return mem[st][ed] = 0;
    if (mem[st][ed] >= 0) return mem[st][ed];
    int r = 0;
    for (int i = st + 1; i < ed; i++) {
        if (s[i] == 'e') {
            r |= iscat(st + 1, i - 1) & iscat(i + 1, ed - 1);
        }
    }
    return mem[st][ed] = r;
}

int main(void) {
    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) mem[i][j] = -1;
    }
    scanf("%s", s);
    if (iscat(0, strlen(s) - 1)) printf("Cat\n");
    else printf("Rabbit\n");
    return 0;
}