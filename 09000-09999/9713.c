#include <stdio.h>

/*
문제 : 자연수 N(N <= 100)이 주어질 때, N 이하의 모든 홀수의 합을 구한다.

해결 방법 : N이 크지 않기 때문에 모든 홀수의 합을 직접 구하면 된다.

주요 알고리즘 : 구현

출처 : Khawa 2011 A번
*/

int main(void) {
    int t, n, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        s = 0;
        for (int i = 1; i <= n; i += 2) {
            s += i;
        }
        printf("%d\n", s);
    }
    return 0;
}