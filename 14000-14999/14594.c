#include <stdio.h>

/*
���� : N(N <= 100)���� ���� ���� ��, M(M <= 100)�� ���� �㹫�� �ൿ�� �� �� ���� ���� ������ ���Ѵ�.

�ذ� ��� : ���� �㹰��� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ���ִ� 2017D1 B1�� / 2017D2 C1��
*/

int chk[128];

int main(void) {
    int n, m, s, e, r = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        for (int i = s; i < e; i++) {
            chk[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        while (chk[i]) i++;
        r++;
    }
    printf("%d", r);
    return 0;
}