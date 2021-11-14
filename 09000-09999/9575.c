#include <stdio.h>
#include <stdlib.h>

/*
���� : ũ�Ⱑ 50 ������ �� �ڿ����� �� �迭�� �־�����. �̶�, �� �迭�� ���� ������ ���� �� �ִ�
���� �ٸ� 5�� 8������ �̷���� ���� ������ ���Ѵ�.

�ذ� ��� : �� �ڿ��� �迭�� ���� ���� �� �迭�� ���� ���� ����, 5�� 8������ �̷���� �ִ��� ���Ѵ�.
�׷��ٸ� ��� �迭�� �ִ´�. Ž���� ������ ��� �迭�� ������ ���� �ߺ��� ������ ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����, ����
*/

int a[64], b[64], c[64], res[128000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, na, nb, nc, x, p = 0, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &na);
        for (int i = 0; i < na; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &nb);
        for (int i = 0; i < nb; i++) {
            scanf("%d", &b[i]);
        }
        scanf("%d", &nc);
        for (int i = 0; i < nc; i++) {
            scanf("%d", &c[i]);
        }

        p = 0, r = 0;
        for (int i = 0; i < na; i++) {
            for (int j = 0; j < nb; j++) {
                for (int k = 0; k < nc; k++) {
                    x = a[i] + b[j] + c[k];
                    for (int y = x; y; y /= 10) {
                        if (y % 10 != 5 && y % 10 != 8) {
                            x = 0;
                            break;
                        }
                    }
                    if (x) res[p++] = x;
                }
            }
        }
        qsort(res, p, sizeof(int), cmp1);
        for (int i = 0; i < p; i++) {
            if (i > 0 && res[i] == res[i - 1]) continue;
            r++;
        }
        printf("%d\n", r);
    }
    return 0;
}