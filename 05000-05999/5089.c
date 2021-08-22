#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 문자열들 중 중복을 제외한 문자열이 몇 개인지 구한다.

해결 방법 : 각 문자열들을 입력받은 다음 문자열들을 정렬한다. 그 다음으로는 전체 문자열에서
이전 문자열과 같은 문자열의 수를 제외한 문자열의 수를 구하면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : NZPC 2011 D번
*/

char towns[128][32];

int main(void) {
    int n, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            fgets(towns[i], 30, stdin);
            if (towns[i][0] == '\n') {
                i--;
                continue;
            }
        }
        qsort(towns, n, sizeof(char) * 32, strcmp);
        r = n;
        for (int i = 1; i < n; i++) {
            if (!strcmp(towns[i], towns[i - 1])) r--;
        }
        printf("Week %d %d\n", tt, r);
    }
    return 0;
}