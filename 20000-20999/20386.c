#include <stdio.h>
#define INF 10123456789

/*
문제 : N(N <= 1000)개의 좌표공간에 평행한 정육면체가 있다. 정육면체의 왼쪽 앞쪽 아래 꼭짓점의 좌표와 한 변의 길이가 주어진다면
모든 정육면체가 겹치는 부분의 부피를 구한다.

해결 방법 : 모든 정육면체가 겹치는 부분 역시 좌표공간에 평행한 직육면체 형태가 된다. 직육면체의 각 면은
가장 안쪽으로 들어간 좌표평면과 같고, 이를 모든 방향에 대해 각각 구하면 된다. 이때 서로를 지나친 면이 있다면 부피가 0이 됨에 주의한다.

주요 알고리즘 : 구현, 기하학

출처 : MidC 1993 4번
*/

int main(void) {
    int n, xl, xh, yl, yh, zl, zh, x, y, z, d;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\cubes.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        xl = -INF, yl = -INF, zl = -INF, xh = INF, yh = INF, zh = INF;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x, &y, &z, &d);
            if (x > xl) xl = x;
            if (x + d < xh) xh = x + d;
            if (y > yl) yl = y;
            if (y + d < yh) yh = y + d;
            if (z > zl) zl = z;
            if (z + d < zh) zh = z + d;
        }
        if (xh <= xl || yh <= yl || zh <= zl) printf("0\n");
        else printf("%d\n", (xh - xl) * (yh - yl) * (zh - zl));
    }
    return 0;
}