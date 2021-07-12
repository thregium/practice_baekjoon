#include <stdio.h>
#include <stdlib.h>

/*
���� : �־��� K(K <= 50)���� ������ ���� �ִ񰪰� �ּڰ�, ���Ľ� ������ �� �� �� ���� ���̰� ū �� ���� ���̸� ���Ѵ�.
�� ���� 0 �̻� 100 �����̴�.

�ذ� ��� : ������ ���� �Է��� ��� �Ǵ��� �׻� ������ ������ ���� �ʱ�ȭ���ѵ� ���� �����ؾ� �� �� ����
���Ž�Ų ���� ���� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : SouthP 2011 A��
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int k, n, mx, mn, lg;
    scanf("%d", &k);
    for (int kk = 1; kk <= k; kk++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        mx = -1;
        mn = 128;
        lg = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) mx = a[i];
            if (a[i] < mn) mn = a[i];
            if (i > 0 && a[i] - a[i - 1] > lg) lg = a[i] - a[i - 1];
        }
        printf("Class %d\n", kk);
        printf("Max %d, Min %d, Largest gap %d\n", mx, mn, lg);
    }
    return 0;
}