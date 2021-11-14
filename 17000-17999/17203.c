#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 정수(|| <= 1000)로 이루어진 수열이 주어질 때, Q(Q <= 1000)개의 쿼리에 응답한다.
S, E 범위에 대해 인접한 수에 대한 변화량의 합을 구한다.

해결 방법 : 변화량을 직접 구하더라도 시간 내에 풀 수 있으므로, 변화량을 직접 더해가며 구하면 된다.

주요 알고리즘 : 구현, 수학

출처 : 중앙대 2019N C번
*/

int a[1024];

int main(void) {
    int n, q, s, e, r;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        if (s >= e) printf("0\n");
        else {
            r = 0;
            for (int j = s; j < e; j++) {
                r += abs(a[j] - a[j + 1]);
            }
            printf("%d\n", r);
        }
    }
    return 0;
}