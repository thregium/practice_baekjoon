#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 10000자 이하의 문자열이 주어진다. 알파벳과 '-'로 이루어진 것을 단어라 하고, 그 외의 문자가 있다면
단어끼리 떨어진 것으로 생각할 때, 가장 긴 단어 가운데 처음 나오는 것을 소문자로 출력한다. 문자열의 끝은
E-N-D라는 단어로 주어진다.

해결 방법 : 문자열의 구분자를 알파벳 문자와 '-' 외의 모든 문자로 넣은 다음, 해당 구분자로 문자열을 단어 단위로 파싱한다.
현재까지의 단어 가운데 가장 긴 것보다 긴 단어가 나오면 가장 긴 단어를 갱신한다. 해당 단어를 소문자로 바꾸는 것도 잊지 않는다.
E-N-D가 나오면 현재까지의 단어 가운데 가장 긴 것을 출력하면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : Hatyai 2012 J번
*/

char buff[10240], lng[128], delim[256];

int main(void) {
    int p = 0;
    char* t;
    for (char i = 1; i; i++) {
        if (i > 0 && (isalpha(i) || i == '-')) continue;
        delim[p++] = i;
    }
    while (1) {
        fgets(buff, 10123, stdin);
        t = strtok(buff, delim);
        if (t == NULL) continue;
        if (!strcmp(t, "E-N-D")) {
            if (lng[0] == '\0') return 1;
            printf("%s", lng);
            return 0;
        }
        if (strlen(t) > strlen(lng)) {
            strcpy(lng, t);
            for (int i = 0; lng[i]; i++) lng[i] = tolower(lng[i]);
        }
        while (t != NULL) {
            t = strtok(NULL, delim);
            if (t == NULL) break;
            if (!strcmp(t, "E-N-D")) {
                if (lng[0] == '\0') return 1;
                printf("%s", lng);
                return 0;
            }
            if (strlen(t) > strlen(lng)) {
                strcpy(lng, t);
                for (int i = 0; lng[i]; i++) lng[i] = tolower(lng[i]);
            }
        }
    }
    return 0;
}