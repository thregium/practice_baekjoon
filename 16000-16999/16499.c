#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 10자 이하의 소문자로 된 문자열이 주어질 때, 서로 아나그램 관계인 그룹이 몇 개인지 구한다.

해결 방법 : 각 문자열을 정렬한 다음, 전체 문자열을 정렬한다. 그 다음, 인접한 문자열끼리 같은 것을 제하고
나머지 문자열의 개수를 세면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : 한양대E 2018B A번
*/

char wd[128][16];

int cmp1(const void* a, const void* b) {
    int ai = *(char*)a;
    int bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", wd[i]);
        qsort(wd[i], strlen(wd[i]), sizeof(char), cmp1);
    }
    qsort(wd, n, sizeof(char) * 16, strcmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && !strcmp(wd[i], wd[i - 1])) continue;
        r++;
    }
    printf("%d", r);
    return 0;
}