#include <stdio.h>
#include <string.h>

/*
문제 : 각 알파벳 대문자마다 다른 5자 이하의 대문자 문자열로 바꾸는 관계가 N(N <= 26)개 주어진다.
처음의 대문자로 이루어진 30자 이하의 문자열이 주어질 때, M(M <= 5)회 후의 문자열을 구한다.
관계가 주어지지 않은 경우 그대로 두면 된다.

해결 방법 : 문제에 주어진대로 각 문자마다 바꿀 문자열들을 저장한 다음,
새 문자열에 문자열들을 추가해 나가면 된다. 원래 문자열은 모든 문자를 바꾼 다음 바꿔야 한다.

주요 알고리즘 : 문자열, 시뮬레이션

출처 : VTH 2016 B번
*/

char buff[32], seq[26][32], res[103000], tmp[103000];

int main(void) {
    int n, m;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 26; i++) seq[i][0] = 'A' + i;
    for (int i = 0; i < n; i++) {
        scanf(" %c -> %s", &c, buff);
        strcpy(seq[c - 'A'], buff);
    }
    scanf("%s", res);
    for (int i = 0; i < m; i++) {
        for (int j = 0; res[j]; j++) {
            strcat(tmp, seq[res[j] - 'A']);
        }
        strcpy(res, tmp);
        tmp[0] = '\0';
    }
    printf("%s", res);
    return 0;
}