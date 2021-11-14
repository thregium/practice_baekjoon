#include <stdio.h>
#include <string.h>

/*
문제 : 각 줄에 소문자와 공백으로 이루어진 문자열(100자 이하)이 주어질 때, 각 문자열에서 첫 단어를 "god"로 바꾸고
나머지 문자열과 차례로 붙인 문자열을 출력한다.

해결 방법 : strtok() 함수를 이용한다.

주요 알고리즘 : 문자열, 파싱

출처 : UCPC 2016 E번
*/

char s[128], res[128];

int main(void) {
    int n;
    char* c;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(s, 120, stdin);
        c = strtok(s, " ");
        strcpy(res, "god");
        while (c) {
            c = strtok(NULL, " ");
            if (c == NULL) break;
            strcat(res, c);
        }
        printf("%s\n", res);
    }
    return 0;
}