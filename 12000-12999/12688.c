#include <stdio.h>
#define INF 1012345678

/*
���� : ��ǥ���� ��ǥ�࿡ ������ ������ ��ǥ�� ���簢���� �ִ�. N(N <= 1000)���� ���� ����
�� ���� ��ġ(<= 10^6, �ڿ���)�� ���簢���� ���ԵǴ� �� ���ΰ� �־��� ��,
M(M <= 1000)���� ���� ���� �� ���� ���簢���� �ݵ�� ���Եǰų� ���Ե��� �ʴ� ��,
�Ǵ� �� �� ���� �� ���θ� ���Ѵ�.

�ذ� ��� : �켱 �ݵ�� ���簢���� ���ԵǴ� ���� ������ ���صд�.
�� ����, �� ���� ���� �� ���� �ݵ�� ���ԵǴ� ���� �ȿ� �ִ� ��� �ݵ�� ���Եȴٰ� �ϸ� �ȴ�.
�� �� ��쿡�� �� ���� ���簢���� ���Եȴٰ� �����ϰ� ���Ե��� �ʴ� ���� ���簢�� ������
���� �� ���θ� Ȯ���Ͽ� ���Ե��� �ʴ� �� ���θ� ���ϸ� �ȴ�.

�ֿ� �˰��� : ������

��ó : GCJ 2008SA A2��
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