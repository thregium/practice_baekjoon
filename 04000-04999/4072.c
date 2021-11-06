#include <stdio.h>
#include <string.h>

/*
문제 : 길이 250 이하의 문자열이 주어질 때, 띄어쓰기 단위로 떨어진 단어들을 각각을 뒤집어 출력한다.

해결 방법 : 각 문자열을 fgets()함수를 이용해 받은 다음, 개행 문자를 제거한다. 그 후로는 strtok()함수를 통해
공백 단위로 단어를 분리해낸 다음 각 단어들을 뒤집은 단어를 만들어 출력하면 된다.

주요 알고리즘 : 구현, 파싱

출처 : NZPC 2004 Z번
*/

char s[256], t[256];

int main(void) {
    char* c;
    while (1) {
        fgets(s, 254, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (s[0] == '#' && strlen(s) == 1) break;
        c = strtok(s, " ");
        while (c) {
            t[strlen(c)] = '\0';
            for (int i = 0, j = strlen(c) - 1; i <= j; i++, j--) {
                t[i] = c[j];
                t[j] = c[i];
            }
            printf("%s ", t);
            c = strtok(NULL, " ");
        }
        printf("\n");
    }
    return 0;
}