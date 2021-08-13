#include <stdio.h>

/*
문제 : N(N <= 1000)일간의 매출이 주어질 때, 2일차 이후부터, 이전 날의 매출 가운데 해당 날의 매출 이하인 날의 수의 합을 구한다.

해결 방법 : 모든 2일차 이후에 대해 이전 날을 전부 확인해보며 해당 날의 매출 이하인 날을 전부 더하면 된다.

주요 알고리즘 : 구현?

출처 : Daejeon 2010 A번
*/

int a[1024];

int main(void) {
    int t, n, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            for (int j = 0; j < i; j++) {
                if (a[j] <= a[i]) r++;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}