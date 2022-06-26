#include <stdio.h>
#define INF 1012345678

/*
문제 : 좌표평면상에 좌표축에 평행한 임의의 좌표의 직사각형이 있다. N(N <= 1000)개의 점에 대해
각 점의 위치(<= 10^6, 자연수)와 직사각형에 포함되는 지 여부가 주어질 때,
M(M <= 1000)개의 점에 대해 그 점이 직사각형에 반드시 포함되거나 포함되지 않는 지,
또는 알 수 없는 지 여부를 구한다.

해결 방법 : 우선 반드시 직사각형에 포함되는 점의 범위를 구해둔다.
그 다음, 각 점에 대해 그 점이 반드시 포함되는 범위 안에 있는 경우 반드시 포함된다고 하면 된다.
그 외 경우에는 그 점이 직사각형에 포함된다고 가정하고 포함되지 않는 점이 직사각형 범위에
들어가는 지 여부를 확인하여 포함되지 않는 지 여부를 구하면 된다.

주요 알고리즘 : 기하학

출처 : GCJ 2008SA A2번
*/

char buff[32];
int pos[1024][2];

int main(void) {
    int t, n, m, p, xh, xl, yh, yl, txh, txl, tyh, tyl, x, y, res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        xl = INF, xh = -1, yl = INF, yh = -1;
        scanf("%d", &n);
        p = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d ", &x, &y);
            fgets(buff, 24, stdin);
            if (buff[0] == 'B') {
                if (x < xl) xl = x;
                if (x > xh) xh = x;
                if (y < yl) yl = y;
                if (y > yh) yh = y;
            }
            else {
                pos[p][0] = x;
                pos[p++][1] = y;
            }
        }

        scanf("%d", &m);
        printf("Case #%d:\n", tt);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            if (xl <= x && x <= xh && yl <= y && y <= yh) printf("BIRD\n");
            else {
                res = 1;
                txl = xl, txh = xh, tyl = yl, tyh = yh;
                if (x < txl) txl = x;
                if (x > txh) txh = x;
                if (y < tyl) tyl = y;
                if (y > tyh) tyh = y;
                for (int j = 0; j < p; j++) {
                    if (txl <= pos[j][0] && pos[j][0] <= txh && tyl <= pos[j][1] && pos[j][1] <= tyh) {
                        res = 0;
                    }
                }
                printf("%s\n", res ? "UNKNOWN" : "NOT BIRD");
            }
        }
    }
    return 0;
}