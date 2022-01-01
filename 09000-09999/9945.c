#include <stdio.h>

/*
���� : 2���� ������ N(1 <= N <= 5000)���� ���� ���� ��ǥ�� ������ �־��� ��, ��� ���� �����߽��� ���Ѵ�.
�־����� ��ǥ�� ������ 5000 ������ �ڿ��� ������ �ִ�. �̸� N�� ������ ��찡 ���� �� ���� �ݺ��Ѵ�.

�ذ� ��� : �� ��ǥ�� ������ ���� ���� ���� ���Է� ������ �����߽��� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : NCNA 2013 G��
*/

int main(void) {
    int n;
    double x, y, m, ax, ay, am;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) return 1;
        else if (n < 0) break;
        ax = 0, ay = 0, am = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf", &x, &y, &m);
            ax += x * m;
            ay += y * m;
            am += m;
        }
        printf("Case %d: %.2f %.2f\n", tt, ax / am, ay / am);
    }
    return 0;
}