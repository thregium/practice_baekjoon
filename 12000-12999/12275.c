#include <stdio.h>
#include <string.h>

/*
문제 : 100KB 이하의 문자열이 주어질 때, 주석을 문제에 주어진 방식대로 없앤 결과를 출력한다.

해결 방법 : 주석을 괄호로 생각하고 0단계 주석인 상태의 문자들만 출력하면 된다.
이때, 0단계에서 닫는 주석을 무시함에 주의한다.

주요 알고리즘 : 문자열, 파싱

출처 : GKS 2013B B2번
*/

char s[103000], buff[103000];

int main(void) {
    int len, level = 0;
    while (fgets(buff, 102500, stdin)) {
        strcat(s, buff);
    }
    len = strlen(s);
    printf("Case #1:\n");
    for (int i = 0; i < len; i++) {
        if (s[i] == '/' && s[i + 1] == '*') {
            level++;
            i++;
            continue;
        }
        if (s[i] == '*' && s[i + 1] == '/' && level > 0) {
            level--;
            i++;
            continue;
        }
        if (level == 0) printf("%c", s[i]);
    }
    return 0;
}