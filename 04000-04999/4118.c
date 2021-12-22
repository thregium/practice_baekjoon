#include <stdio.h>

/*
문제 : N(N <= 100)개의 복권 용지를 샀을 때, 1부터 49까지의 모든 수가 최소한 하나의 용지에 포함되었는지 여부를 구한다.

해결 방법 : 각 용지에 포함된 모든 복권 번호를 체크한다. 그리고 1부터 49까지 하나씩 확인하며 체크되지 않은 것은 없는지 확인한다.
체크되지 않은 것이 있다면 포함되지 않은 것이 있는 것이고, 없다면 모두 포함된 것이다.

주요 알고리즘 : 구현

출처 : SEUSA 2008 F번
*/

char chk[64];

int main(void) {
    int n, x, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                scanf("%d", &x);
                chk[x] = 1;
            }
        }
        r = 1;
        for (int i = 1; i <= 49; i++) {
            if (!chk[i]) r = 0;
            chk[i] = 0;
        }
        printf("%s\n", r ? "Yes" : "No");
    }
    return 0;
}