#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 20)���� ������ Ǯ�� �ð��� �־��� ��, �ð� �� ���� ���� Ǯ�鼭 ���Ƽ�� �ּҷ� �� ����
Ǭ ���� ��, ���������� Ǭ �ð�, ���Ƽ�� ���� ����Ѵ�.

�ذ� ��� : Ǯ�� �ð��� ª�� ������ Ǫ�� ���� �̵��̴�. ����, ������������ ������ ����, �ð��� ������ ������
�� �������� Ǯ����� �� �ᱣ������ ���س����� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : Phuket 2015 B��
*/

int a[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, l, r1, r2, r3;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        r1 = 0, r2 = 0, r3 = 0;
        for (int i = 0; i < n; i++) {
            if (r2 + a[i] <= l) {
                r1++;
                r2 += a[i];
                r3 += r2;
            }
            else break;
        }
        printf("Case %d: %d %d %d\n", tt, r1, r2, r3);
    }
    return 0;
}