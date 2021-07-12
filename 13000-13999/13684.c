#include <stdio.h>

/*
문제 : 주어진 두 좌표 (N, M)을 기준으로 할 때 (X, Y)가 어느 사분면에 속하는지 또는 경계선에 있는지 구한다.

해결 방법 : X, Y좌표가 N, M에 대해 상대적인 위치를 구한 뒤 사분면을 찾으면 된다.

주요 알고리즘 : 구현

출처 : Brasil 2008 H번
*/

int main(void) {
    int k, n, m, x, y;
    while (1) {
        scanf("%d", &k);
        if (k == 0) break;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y);
            if (x == n || y == m) printf("divisa\n");
            else if (x < n && y < m) printf("SO\n");
            else if (x < n) printf("NO\n");
            else if (y < m) printf("SE\n");
            else printf("NE\n");
        }
    }
    return 0;
}