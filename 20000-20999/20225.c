#include <stdio.h>

/*
���� : N(N <= 100)���� ������ M(M <= 1000)���� ������ �ð������� �־�����.
P�� ����� ������������ ������ ���(P ����)�� ���� ���Ѵ�.

�ذ� ��� : ������ ������� �ùķ��̼��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : JDC 2020 B��
*/

int user[128];

int main(void) {
    int n, m, p, r, x, y;
    while (1) {
        scanf("%d %d %d", &n, &m, &p);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) user[i] = 0;
        user[p] = 1;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            user[x] |= user[y];
            user[y] |= user[x];
        }
        r = 0;
        for (int i = 1; i <= n; i++) r += user[i];
        printf("%d\n", r);
    }
    return 0;
}