#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 소문자로 이루어진 1000자 이하의 두 문자열이 주어진다. 첫 번째 문자열을 재배열해서
두 번째 문자열을 만들 수 있는지 구한다.

해결 방법 : 각 문자열을 정렬한 뒤 비교해서 같다면 같은 문자열인 것이고, 다르다면 다른 문자열인 것이다.

주요 알고리즘 : 구현, 문자열, 정렬

출처 : NCNA 2013 H번
*/

char s1[1024], s2[1024];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    for (int tt = 1;; tt++) {
        scanf("%s%s", s1, s2);
        if (!strcmp(s1, "END")) break;
        qsort(s1, strlen(s1), sizeof(char), cmp1);
        qsort(s2, strlen(s2), sizeof(char), cmp1);
        printf("Case %d: ", tt);
        if (strcmp(s1, s2)) printf("different\n");
        else printf("same\n");
    }
    return 0;
}