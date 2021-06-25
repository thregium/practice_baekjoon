#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���� : N(N <= 5000)���� �� ��� ���� ������ ���� ���� �� ���� ã�´�.

�ذ� ��� : ���� ������ ��, �� ���� ������Ų ���� �ش� �� ���� ���� ���� ������ ���������� �����͸� �������� �������
�� ���� ���� 0�� ��������� ����� ���� ���� ã�´�. �� ����� �ݺ��� ���� ������ �۾����� �� ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, �� ������

��ó : ���� 2010 ��1��
*/

long long a[5120];
long long best = 12345678987654321, b[3];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, p1, p2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    qsort(a, n, sizeof(long long), cmp1);
    for (int i = 0; i < n; i++) {
        p1 = i + 1;
        p2 = n - 1;
        while (p1 < p2) {
            if (llabs(a[i] + a[p1] + a[p2]) < best) {
                best = llabs(a[i] + a[p1] + a[p2]);
                b[0] = a[i];
                b[1] = a[p1];
                b[2] = a[p2];
            }
            if (a[i] + a[p1] + a[p2] > 0) p2--;
            else p1++;
        }
    }
    qsort(b, 3, sizeof(long long), cmp1);
    printf("%lld %lld %lld", b[0], b[1], b[2]);
    return 0;
}