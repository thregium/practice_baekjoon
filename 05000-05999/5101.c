#include <stdio.h>

/*
���� : ������ A�̰� ������ D�� ������������ N�� ���� �ִ��� Ȯ���ϰ�, �ִٸ� �� ��° ������ ���Ѵ�.

�ذ� ��� : A���� ���ʷ� Ȯ���� �����ٰ� N�� �Ѿ�� �ݺ��� �����ϰ� N���� Ȯ���Ѵ�. N�̶�� �ش��ϴ� ��°�� ����ϰ�,
�ƴ϶�� ���� ���̴�.

�ֿ� �˰��� : ����

��ó : NZPC 2010 B��
*/

int main(void) {
    int a, d, n, i;
    while (1) {
        scanf("%d %d %d", &a, &d, &n);
        if (d > 0) {
            for (i = 1; a < n; i++) a += d;
            if (a == n) printf("%d\n", i);
            else printf("X\n");
        }
        else if (d < 0) {
            for (i = 1; a > n; i++) a += d;
            if (a == n) printf("%d\n", i);
            else printf("X\n");
        }
        else break;
    }
    return 0;
}