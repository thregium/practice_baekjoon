#include <stdio.h>

/*
문제 : B(B <= 20)개의 은행에서 N(N <= 20)개의 채무 관계가 있다. 이때, 각 은행의 자금을 적절히 이동시켜
모든 채무관계를 청산할 수 있는지 구한다.

해결 방법 : 각 채무 관계를 은행의 실제 자금을 이동시킨 다음 모든 은행의 자금량을 확인한다.
여기서 자금이 음수가 되는 은행이 있다면 채무관계를 청산할 수 없는 것이다.

주요 알고리즘 : 구현

출처 : Brasil 2009 D번
*/

int moneys[32];

int main(void) {
    int b, n, d, c, v, r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\subprime.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\subprime.out", "w", stdout);
    while (1) {
        scanf("%d %d", &b, &n);
        if (b == 0) break;
        for (int i = 1; i <= b; i++) {
            scanf("%d", &moneys[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &d, &c, &v);
            moneys[d] -= v;
            moneys[c] += v;
        }
        r = 1;
        for (int i = 1; i <= b; i++) {
            if (moneys[i] < 0) r = 0;
        }
        printf("%c\n", r ? 'S' : 'N');
    }
    return 0;
}