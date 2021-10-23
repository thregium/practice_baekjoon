#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 카드 집합 2개가 주어질 때, 두 집합의 구성이 같은지 구한다. 각 카드는 길이 2의 문자열로 주어진다.
카드의 첫 자는 'R', 'Y', 'B' 중 하나, 두 번째 자는 숫자이다.

해결 방법 : 각 카드 집합을 사전순으로 정렬한 다음, 모든 순서에 대해 같은지 검사한다.
다른 것이 하나라도 있다면 다른 것이고 모두 같다면 같은 것이다.

주요 알고리즘 : 구현, 정렬
*/

char s1[256][8], s2[256][8];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s1[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", s2[i]);
        }
        qsort(s1, n, sizeof(char) * 8, strcmp);
        qsort(s2, n, sizeof(char) * 8, strcmp);
        r = 1;
        for (int i = 0; i < n; i++) {
            if (strcmp(s1[i], s2[i])) r = 0;
        }
        printf("%s\n", r ? "NOT CHEATER" : "CHEATER");
    }
    return 0;
}