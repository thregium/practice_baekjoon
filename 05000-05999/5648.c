#include <stdio.h>
#include <stdlib.h>

/*
���� : �־��� N(N <= 10^6)���� �ڿ����� �������� �� ������ ������ ����� ����Ѵ�.

�ذ� ��� : �ڿ����� �������� �� ���� ���ϰ�, �� ������ �迭�� ���� ���� �����ؼ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : Phuket 2011 P1��
*/

long long a[1048576];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        y = 0;
        while (x) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        a[i] = y;
    }
    qsort(a, n, sizeof(long long), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%lld\n", a[i]);
    }
    return 0;
}