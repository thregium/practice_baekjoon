#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 100자 이하의 소문자로 이루어진 두 문자열이 주어질 때, 두 문자열이 애너그램 관계인지 구한다.

해결 방법 : 각 문자열을 정렬한 다음 두 문자열을 비교한다. 두 문자열이 같다면 애너그램 관계인 것이고,
같지 않다면 애너그램 관계가 아닌 것이다.

주요 알고리즘 : 구현, 문자열, 정렬

출처 : HSPC 2013 2번
*/

char word1[128], word2[128], st1[128], st2[128];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %s", word1, word2);
        strcpy(st1, word1);
        strcpy(st2, word2);
        qsort(st1, strlen(st1), sizeof(char), cmp1);
        qsort(st2, strlen(st2), sizeof(char), cmp1);
        if (strcmp(st1, st2)) printf("%s & %s are NOT anagrams.\n", word1, word2);
        else printf("%s & %s are anagrams.\n", word1, word2);
    }
    return 0;
}