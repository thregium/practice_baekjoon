#include <stdio.h>

/*
���� : �� �� A, B(A, B <= 20000)�� �հ� ���� ���� ����Ѵ�.

�ذ� ��� : �հ� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : Kabul 2019 7��
*/

int main(void) {
    int t, n, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            printf("%d %d\n", a + b, a * b);
        }
    }
    return 0;
}