#include <stdio.h>

/*
문제 : N(2 <= N <= 30)개의 자연수(<= 9)가 주어질 때, 왼쪽부터의 합과 오른쪽부터의 합이 일치하는
경계가 있는 지 구하고, 있다면 그 위치를 출력한다.

해결 방법 : 경계가 될 수 있는 모든 경우에 대해 양쪽의 합을 계산한 다음,
그 중 양쪽 합이 같은 경우를 출력하면 된다. 그러한 경우가 없었다면 따로 그 경우를 출력한다.

주요 알고리즘 : 브루트 포스

출처 : MidC 2002 B번
*/

int a[32];

int main(void) {
    int n, s, e, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        r = 0;
        for (int i = 2; i <= n; i++) {
            s = 0, e = 0;
            for (int j = 1; j < i; j++) s += a[j];
            for (int j = i; j <= n; j++) e += a[j];
            if (s == e) {
                printf("Sam stops at position %d and Ella stops at position %d.\n", i - 1, i);
                r = 1;
            }
        }
        if (!r) printf("No equal partitioning.\n");
    }
    return 0;
}