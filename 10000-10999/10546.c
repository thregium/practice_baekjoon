#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 문자열 N(N <= 100000)개가 있는 집합과, 그 집합에서 문자열 한 개가 사라진 집합이 주어질 때,
사라진 문자열을 구한다.

해결 방법 : 두 문자열을 정렬한 다음, 앞쪽 원소부터 비교한다. 처음으로 달라지는 원소의 N개 있는 집합에서의 값이 답이 된다.

주요 알고리즘 : 문자열, 정렬

출처 : COCI 14/15#2 2번
*/

char orig[103000][32], fin[103000][32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", orig[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%s", fin[i]);
    }
    qsort(orig, n, sizeof(char) * 32, strcmp);
    qsort(fin, n - 1, sizeof(char) * 32, strcmp);
    for (int i = 0; i < n; i++) {
        if (strcmp(orig[i], fin[i])) {
            printf("%s", orig[i]);
            return 0;
        }
    }
    return 1;
}