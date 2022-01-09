#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 150)개의 문자열(<=200자, 소문자)이 주어질 때, 짧은 순 -> 사전순으로 정렬하여 출력한다.

해결 방법 : 구조체와 정렬 함수를 사용해 정렬하면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : JPOI 2007 1-2번
*/

typedef struct gem {
    int len;
    char s[256];
} gem;

gem g[192];

int cmp1(const void* a, const void* b) {
    gem ai = *(gem*)a;
    gem bi = *(gem*)b;
    return ai.len > bi.len ? 1 : ai.len == bi.len ? strcmp(ai.s, bi.s) : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i].s);
        g[i].len = strlen(g[i].s);
    }
    qsort(g, n, sizeof(gem), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%s\n", g[i].s);
    }
    return 0;
}