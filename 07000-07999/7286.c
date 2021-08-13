#include <stdio.h>

/*
문제 : N(N <= 26)개의 자연수 구간 [lo, hi)(hi <= 1000)에 대해 포함되는 모든 자연수에 대해 포함되는 구간의 개수를 알파벳 형태로 출력한다.

해결 방법 : 0부터 차례로 각 자연수에 대해 모든 구간들을 확인하며 포함되는 것이 몇 개인지 구한다.

주요 알고리즘 : 구현

출처 : Tehran 2005 A번
*/

int itvs[32][2];

int main(void) {
    int t, n, r;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c %d %d", &c, &itvs[i][0], &itvs[i][1]);
        }
        for (int i = 0; i <= 1000; i++) {
            r = 0;
            for (int j = 0; j < n; j++) {
                if (i >= itvs[j][0] && i < itvs[j][1]) r++;
            }
            if (r > 0) printf("%c", 'A' + r - 1);
        }
        printf("\n");
    }
    return 0;
}