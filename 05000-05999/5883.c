#include <stdio.h>

/*
문제 : N(N <= 1000)개의 자연수로 이루어진 수열이 있을 때, 이 수열에서 한 수를 전부 지우고 남은 수열에서
가장 긴 연속한 같은 수의 길이를 구한다.

해결 방법 : N이 충분히 작기 때문에 모든 수를 한번씩 지워보며 연속한 같은 수의 길이를 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2012O B1번
*/

int want[1024], wnew[1024];

int main(void) {
    int n, wp, c, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &want[i]);
    }
    for (int i = 0; i < n; i++) {
        wp = 0;
        for (int j = 0; j < n; j++) {
            if (want[j] != want[i]) wnew[wp++] = want[j];
        }
        c = 1;
        for (int j = 1; j < wp; j++) {
            if (wnew[j] == wnew[j - 1]) c++;
            else c = 1;
            if (c > r) r = c;
        }
    }
    printf("%d", r);
    return 0;
}