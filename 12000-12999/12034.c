#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100) * 2 ũ���� �迭(<= 10^9, �ڿ���)�� ���� ���� ���� ������ 4 / 3�� �� ������ ���� �ִ�.
���� ������ ������������ �����Ͽ� ����Ѵ�. �׷��� ��찡 �׻� �������� �־�����.

�ذ� ��� : �� ���� ������������ ������ ����, 4 / 3�� �� ���� �����Ѵ�. �̸� �ݺ��ϸ� �ߺ��ؼ� �������� �ʰ�
��� 4 / 3�� �� ������ ������ �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : GCJ 2016W A2��
*/

long long p[256];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, x;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n * 2; i++) {
            scanf("%lld", &p[i]);
        }
        qsort(p, n * 2, sizeof(long long), cmp1);
        for (int i = 0; i < n; i++) {
            x = 0;
            for (int j = i + 1; j < n * 2 - i; j++) {
                if (p[j] * 3 == p[i] * 4) {
                    for (int k = j; k < n * 2 - i - 1; k++) {
                        p[k] = p[k + 1];
                    }
                    x = 1;
                    break;
                }
            }
            if (!x) return 1;
        }
        printf("Case #%d: ", tt);
        for (int i = 0; i < n; i++) {
            printf("%lld ", p[i]);
        }
        printf("\n");
    }
    return 0;
}