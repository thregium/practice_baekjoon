#include <stdio.h>

/*
문제 : N(N <= 100000)개의 수를 가진 배열이 있을 때, 배열의 특정 위치부터 특정 위치까지의 합을
M(M <= 10000)번 구한다.

해결 방법 : 미리 배열의 첫 원소부터 X번째 원소까지의 합을 구해놓고,
(Y + 1번째까지의 합) - (X번째까지의 합)을 구하면 구하고자 하는 값이 나온다.

주요 알고리즘 : 누적 합

출처 : AIPO 2015J 3번
*/

int a[103000], s[103000];

int main(void) {
    int n, m, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        printf("%d\n", s[y + 1] - s[x]);
    }
    return 0;
}