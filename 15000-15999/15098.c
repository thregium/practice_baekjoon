#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 80자 이하의 문자열(대문자, 공백)이 주어질 때, 이 문자열의 단어 가운데 같은 단어가 있는지 구한다.

해결 방법 : 각 문자열을 단어 단위로 자른 다음, 단어들을 정렬하고, 인접한 단어 가운데 같은 것이 있는지 확인하면 된다.

주요 알고리즘 : 문자열, 파싱, 정렬

출처 : MidC 2017 D번
*/

char buff[128], word[128][128];

int main(void) {
    int wc = 0, r = 1;
    char* c;
    fgets(buff, 100, stdin);
    buff[strlen(buff) - 1] = '\0';
    c = strtok(buff, " ");
    while (c) {
        strcpy(word[wc], c);
        wc++;
        c = strtok(NULL, " ");
    }
    qsort(word, wc, sizeof(char) * 128, strcmp);
    for (int i = 1; i < wc; i++) {
        if (!strcmp(word[i], word[i - 1])) r = 0;
    }
    printf("%s", r ? "yes" : "no");
    return 0;
}