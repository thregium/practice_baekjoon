#include <stdio.h>

/*
���� : N(2 <= N <= 30)���� �ڿ���(<= 9)�� �־��� ��, ���ʺ����� �հ� �����ʺ����� ���� ��ġ�ϴ�
��谡 �ִ� �� ���ϰ�, �ִٸ� �� ��ġ�� ����Ѵ�.

�ذ� ��� : ��谡 �� �� �ִ� ��� ��쿡 ���� ������ ���� ����� ����,
�� �� ���� ���� ���� ��츦 ����ϸ� �ȴ�. �׷��� ��찡 �����ٸ� ���� �� ��츦 ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : MidC 2002 B��
*/

int a[32];

int main(void) {
    int n, s, e, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        r = 0;
        for (int i = 2; i <= n; i++) {
            s = 0, e = 0;
            for (int j = 1; j < i; j++) s += a[j];
            for (int j = i; j <= n; j++) e += a[j];
            if (s == e) {
                printf("Sam stops at position %d and Ella stops at position %d.\n", i - 1, i);
                r = 1;
            }
        }
        if (!r) printf("No equal partitioning.\n");
    }
    return 0;
}