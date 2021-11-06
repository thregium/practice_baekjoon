#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : 길이 1000 이하의 두 문자열이 주어질 때, 첫 번째 문자열을 재배열하여 두 번째 문자열을 만들 수 있는지 확인한다.

해결 방법 : 두 문자열을 각 문자 단위로 정렬한 다음 두 문자열이 같은지 살펴보면 된다.
만약 두 문자열이 같다면 구성하는 모든 문자의 개수가 같다는 의미이므로 재배열이 가능하고, 다르다면
개수가 다른 문자가 있으므로 재배열이 불가능하다.

주요 알고리즘 : 문자열, 정렬

출처 : Calgary 2014 E번
*/

char s1[1024], s2[1024];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", s1, s2);
        qsort(s1, strlen(s1), sizeof(char), cmp1);
        qsort(s2, strlen(s2), sizeof(char), cmp1);
        if (strcmp(s1, s2)) printf("Impossible\n");
        else printf("Possible\n");
    }
    return 0;
}