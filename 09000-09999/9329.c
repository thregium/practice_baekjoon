#include <stdio.h>

/*
���� : N(N <= 10)���� ����� ��� ����� �־�����. K(K <= 30)���� �־��� ��ƼĿ�� ������ ����� ���� �� �ִ�.
�� ��ƼĿ�� ���ƾ� �ϳ��� ��ݿ��� ���δٸ�, �� ��ƼĿ�� ���� ������ �־����� ���� �� �ִ� �ִ� ����� ���Ѵ�.

�ذ� ��� : �� ��ƼĿ�� ���ƾ� �ϳ��� ��ݿ��� ���̹Ƿ� �� ��ݸ��� ��ȯ�� �� �ִ� �ִ��� ��ƼĿ�� ��ȯ�Ѵ�.
�ش� ��ƼĿ ��� ���� ���� ��ƼĿ�� ���� * ����� ��ȯ �����ϴ�. �̸� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : Rocky 2013 A��
*/

int stk[16][32], cnt[32];

int main(void) {
    int t, n, m, r, worst;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &stk[i][0]);
            for (int j = 1; j <= stk[i][0]; j++) {
                scanf("%d", &stk[i][j]);
            }
            scanf("%d", &stk[i][31]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &cnt[i]);
        }

        r = 0;
        for (int i = 0; i < n; i++) {
            worst = 103000;
            for (int j = 1; j <= stk[i][0]; j++) {
                if (cnt[stk[i][j]] < worst) worst = cnt[stk[i][j]];
            }
            r += worst * stk[i][31];
        }
        printf("%d\n", r);
    }
    return 0;
}