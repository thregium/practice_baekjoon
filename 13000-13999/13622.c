#include <stdio.h>

/*
문제 : N * P(P, N <= 1000) 크기의 격자에서 0, 1이 있을 때, 세로로 C(C <= N)개 이상의 1이 연속하는 구간의 수를 구한다.

해결 방법 : 직접 모든 세로줄에서 해당하는 수의 개수를 세본다. 1이 나오면 연속수를 1씩 올리고 0이 나오면 0으로 초기화한다.
이때 연속수가 C가 되는 경우 결괏값을 1 올린다. 이를 반복해 모든 격자에서 나오는 수를 구할 수 있다.

주요 알고리즘 : 구현

출처 : Brasil 2006 A번
*/

int a[1024][1024];

int main(void) {
    int p, n, c, l, r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2006\\circuito.in", "r", stdin);
    while (1) {
        scanf("%d %d %d", &p, &n, &c);
        if (p == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        r = 0;
        for (int i = 0; i < p; i++) {
            l = 0;
            for (int j = 0; j < n; j++) {
                if (a[j][i]) {
                    l++;
                    if (l == c) r++;
                }
                else l = 0;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}