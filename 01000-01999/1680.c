#include <stdio.h>

/*
���� : N(N <= 1000)���� ������ ���̿� �뷮, ������ ���� �뷮�� �־��� ��, ������ �־��� ����� ������ ���� ��������
���������� �����̴� �Ÿ��� ���Ѵ�.

�ذ� ��� : ������ �־������ �ùķ��̼��Ѵ�. ������ �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : Alberta 2012 G��
*/

int garb[1024][2];

int main(void) {
    int t, w, n, p, u, r;
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\_Alberta\\2012\\data\\G.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &w, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &garb[i][0], &garb[i][1]);
        }
        p = 0, u = 0, r = 0;
        while (p < n) {
            if (u + garb[p][1] > w) {
                u = 0;
                r += garb[p][0] * 2;
            }
            u += garb[p][1];
            if (u == w || p == n - 1) {
                u = 0;
                r += garb[p][0] * 2;
            }
            p++;
        }
        printf("%d\n", r);
    }
    return 0;
}