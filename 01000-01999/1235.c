#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 같은 길이(<= 100)의 숫자로 되어 있는 문자열이 주어진다. 이때, 모든 문자열에서 서로 다른
접미사 가운데 가장 길이가 짧은 것의 길이를 구한다.

해결 방법 : 맨 앞에서부터 해당 문자에서 시작하는 접미사를 복사하고 정렬한 다음, 겹치는 것이 있는지 확인한다.
겹치는 것이 생기는 순간의 접미사 길이 + 1이 답이 된다. 그러한 경우가 없다면 답은 1이다.

주요 알고리즘 : 브루트 포스, 문자열, 정렬
*/

char s[1024][128], ns[1024][128];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; s[0][i]; i++) {
        for (int j = 0; j < n; j++) {
            strcpy(ns[j], s[j] + i);
        }
        qsort(ns, n, sizeof(char) * 128, strcmp);
        r = 1;
        for (int j = 1; j < n; j++) {
            if (!strcmp(ns[j], ns[j - 1])) {
                r = 0;
                break;
            }
        }
        if (!r) {
            printf("%d", strlen(ns[0]) + 1);
            return 0;
        }
    }
    printf("1");
    return 0;
}