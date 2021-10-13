#include <stdio.h>

/*
문제 : N * N(N <= 10^9) 크기의 체스판에서 (R1, C1)에서 (R2, C2)로 나이트가 한 수에 이동 가능한지 구한다.
두 칸은 모두 체스판 안에 있다.

해결 방법 : 두 좌표의 차이를 구한 다음, 한 축으로는 절댓값이 1이고 다른 축으로는 절댓값이 2인지 확인하면 된다.

주요 알고리즘 : 구현

출처 : Tunisia 2013 G번
*/

int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

int main(void) {
    int t, n, r1, c1, r2, c2, x, y, res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d %d %d", &n, &r1, &c1, &r2, &c2);
        x = r1 - r2;
        y = c1 - c2;
        res = 0;
        for (int i = 0; i < 8; i++) {
            if (x == dxy[i][0] && y == dxy[i][1]) res = 1;
        }
        printf("Case %d: ", tt);
        if (res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}