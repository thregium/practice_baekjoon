#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : N(N <= 50)개의 대문자로 이루어진 문자열(<= 100자)들과 대문자로 이루어진 문자열이 주어질 때,
다른 주어진 문자열을 만들기 위해 마지막에 주어진 문자열의 다음 문자가 될 수 있는 문자의 목록을 출력한다.

해결 방법 : 각 문자열들을 확인하면서 마지막 문자열이 접두사인 경우 다음 문자를 목록에 추가한다.
그리고 목록을 양식에 맞게 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : COCI 16/17#4 2번
*/

char s[64][128], t[128];
char res[64];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    scanf("%s", t);
    for (int i = 0; i < 32; i++) res[i] = '*';
    for (int i = 0; i < n; i++) {
        if (strstr(s[i], t) == s[i] && isupper(s[i][strlen(t)])) {
            res[s[i][strlen(t)] - 'A' + 3] = s[i][strlen(t)];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", res[i * 8 + j]);
        }
        printf("\n");
    }
    return 0;
}