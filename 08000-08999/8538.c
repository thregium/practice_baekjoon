#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
문제 : N(N <= 10000)개의 알파벳과 '-'로 이루어진 문자열이 주어질 때, '-'를 제거하고 대소문자를 무시한다면
서로 다른 문자열의 수를 구한다.

해결 방법 : 각 문자열들에서 -를 제거하고 모든 문자를 소문자로 바꾸어 새로운 문자열들을 저장한다.
그 다음 해당 문자열을 정렬하고 인접한 문자열들 가운데 서로 다른 것의 수 + 1을 하면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : PA 2002.05 1-1번
*/

char buff[103000], reduc[10240][32];

int main(void) {
    int n, p, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        p = 0;
        for (int j = 0; buff[j]; j++) {
            if (isalpha(buff[j])) reduc[i][p++] = tolower(buff[j]);
        }
    }
    qsort(reduc, n, sizeof(char) * 32, strcmp);
    for (int i = 1; i < n; i++) {
        if (strcmp(reduc[i], reduc[i - 1])) r++;
    }
    printf("%d", r);
    return 0;
}