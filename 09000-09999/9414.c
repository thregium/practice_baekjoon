#include <stdio.h>
#include <stdlib.h>

/*
���� : 40�� ������ ���� ���� ������ �ų� ó�� ���� �踸ŭ ���� ��, ��� ���� ��� ���� �� ���� ���Ѵ�.

�ذ� ��� : ���� ��� �� ���� ���ʷ� ��� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : Thai 2010N G��
*/

int price[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, r, x;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        n = 0;
        while (1) {
            scanf("%d", &price[n]);
            if (price[n] == 0) break;
            n++;
        }
        qsort(price, n, sizeof(int), cmp1);
        r = 0;
        for (int i = 0; i < n; i++) {
            x = 2;
            for (int j = 0; j <= i; j++) x *= price[i];
            r += x;
            if (r > 5000000) {
                r = -1;
                break;
            }
        }
        if (r < 0) printf("Too expensive\n");
        else printf("%d\n", r);
    }
    return 0;
}