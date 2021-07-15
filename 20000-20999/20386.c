#include <stdio.h>
#define INF 10123456789

/*
���� : N(N <= 1000)���� ��ǥ������ ������ ������ü�� �ִ�. ������ü�� ���� ���� �Ʒ� �������� ��ǥ�� �� ���� ���̰� �־����ٸ�
��� ������ü�� ��ġ�� �κ��� ���Ǹ� ���Ѵ�.

�ذ� ��� : ��� ������ü�� ��ġ�� �κ� ���� ��ǥ������ ������ ������ü ���°� �ȴ�. ������ü�� �� ����
���� �������� �� ��ǥ���� ����, �̸� ��� ���⿡ ���� ���� ���ϸ� �ȴ�. �̶� ���θ� ����ģ ���� �ִٸ� ���ǰ� 0�� �ʿ� �����Ѵ�.

�ֿ� �˰��� : ����, ������

��ó : MidC 1993 4��
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