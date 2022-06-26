#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 길이 200 이하의 올바른 괄호가 포함된 수식이 주어진다. 이 수식에서 쌍을 이루는 괄호를 하나 이상
제거하여 만들 수 있는 모든 서로 다른 수식들을 사전순으로 출력한다.

해결 방법 : 주어진 문자열의 각 괄호에 스택을 이용하여 번호를 매긴다.
그 다음, 괄호를 지우는 모든 경우의 문자열을 만들어내고 정렬하고 중복을 제거하여 출력하면 된다.

주요 알고리즘 : 문자열, 자료 구조, 스택, 브루트 포스, 정렬

출처 : COCI 11/12#6 3번
*/

char s[256], res[1024][256];
int pnum[256], stk[16];

int main(void) {
    int level = 0, pcnt = 0, pos;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            stk[level++] = pcnt++;
            pnum[i] = pcnt - 1;
        }
        else if (s[i] == ')') {
            level--;
            pnum[i] = stk[level];
        }
        else pnum[i] = -1;
    }

    if (pcnt > 10) return 1;
    for (int i = 0; i < (1 << pcnt) - 1; i++) {
        pos = 0;
        for (int j = 0; s[j]; j++) {
            if (pnum[j] < 0 || ((i >> pnum[j]) & 1)) res[i][pos++] = s[j];
        }
    }
    qsort(res, (1 << pcnt) - 1, sizeof(char) * 256, strcmp);
    for (int i = 0; i < (1 << pcnt) - 1; i++) {
        if (i > 0 && !strcmp(res[i], res[i - 1])) continue;
        printf("%s\n", res[i]);
    }
    return 0;
}