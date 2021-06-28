#include <stdio.h>
#include <string.h>

/*
문제 : 수가 매 줄마다 임의의 개수만큼 주어질 때, 줄마다 합을 출력한다.

해결 방법 : 줄 단위로 수를 입력받은 후 공백 단위로 잘라서 파싱한다.

주요 알고리즘 : 문자열, 파싱
*/

char s[1024], *tok;

int main(void) {
    int t, x, r;
    scanf("%d\n", &t);
    for (int tt = 0; tt < t; tt++) {
        fgets(s, 1024, stdin);
        r = 0;
        tok = strtok(s, " ");
        while (tok != NULL) {
            sscanf(tok, "%d", &x);
            r += x;
            tok = strtok(NULL, " ");
        }
        printf("%d\n", r);
    }
    return 0;
}