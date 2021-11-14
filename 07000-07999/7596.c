#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 200)개의 250자 이하의 문자열을 정렬한 결과를 출력한다.

해결 방법 : strcmp와 qsort() 함수를 이용한다.

주요 알고리즘 : 문자열, 정렬

출처 : NZPC 2008 B번
*/

char s[256][256];

int main(void) {
    int n;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        getchar();
        for (int i = 0; i < n; i++) {
            fgets(s[i], 253, stdin);
            if (s[i][strlen(s[i]) - 1] == '\n') s[i][strlen(s[i]) - 1] = '\0';
        }
        qsort(s, n, sizeof(char) * 256, strcmp);
        printf("%d\n", tt);
        for (int i = 0; i < n; i++) {
            printf("%s\n", s[i]);
        }
    }
    return 0;
}