#include <stdio.h>

/*
���� : �ڿ��� N(N <= 100)�� �־��� ��, N ������ ��� Ȧ���� ���� ���Ѵ�.

�ذ� ��� : N�� ũ�� �ʱ� ������ ��� Ȧ���� ���� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Khawa 2011 A��
*/

int main(void) {
    int t, n, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        s = 0;
        for (int i = 1; i <= n; i += 2) {
            s += i;
        }
        printf("%d\n", s);
    }
    return 0;
}