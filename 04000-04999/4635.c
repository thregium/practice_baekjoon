#include <stdio.h>

/*
���� : N(N <= 10)���� �ӷ°� ���� �ð� ����� �־��� ��, ��ü �̵� �Ÿ��� ���Ѵ�.

�ذ� ��� : �ش� �������� �޸� �Ÿ��� (������ �ð� - �� �� �ð�) * �ӷ��̴�. �̵��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : MidC 2004 G��
*/

int main(void) {
    int n, s, t, lt, r = 0;
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        lt = 0, r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &s, &t);
            r += s * (t - lt);
            lt = t;
        }
        printf("%d miles\n", r);
    }
    return 0;
}