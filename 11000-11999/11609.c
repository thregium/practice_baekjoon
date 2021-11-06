#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 100)명의 성과 이름이 주어질 때, 성 -> 이름 순으로 정렬한다. 성과 이름은 대문자인 첫 글자를 제외하면
소문자로만 이루어져 있고, 10자 이내이다.

해결 방법 : strcmp 함수와 qsort 함수를 사용한다. last name이 우선임에 유의한다.

주요 알고리즘 : 문자열, 정렬

출처 : PacNW 2015 R번
*/

char name[128][2][16];

int cmp1(const void* a, const void* b) {
    if (strcmp((char*)a + 16, (char*)b + 16)) return strcmp((char*)a + 16, (char*)b + 16);
    return strcmp((char*)a, (char*)b);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", name[i][0], name[i][1]);
    }
    qsort(name, n, sizeof(char) * 2 * 16, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", name[i][0], name[i][1]);
    }
    return 0;
}