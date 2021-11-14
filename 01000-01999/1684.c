#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ 10^6 ������ �������� �־��� ��, �ش� ���� �������� �� ��� �������� ����
�ڿ��� D ��� ���� ū ���� ���Ѵ�. �׻� �����ϴ� ��츸 �־�����.

�ذ� ��� : ��� ������ ���� ���� ���� �� ���� ������ ���� ���� ���� ������ ��� ���� �ִ������� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, ��Ŭ���� ȣ����
*/

int a[1024], r[2048];
int rp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, g;
    scanf("%d", &n);
    int m = 1234567890;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < m) m = a[i];
    }
    for (int i = 0; i < n; i++) a[i] -= m;
    g = a[1];
    for (int i = 2; i < n; i++) {
        g = gcd(g, a[i]);
    }
    for (int i = 2; i * i <= g; i++) {
        if (g % i == 0) {
            r[rp++] = i;
            if (g / i != i) r[rp++] = g / i;
        }
    }
    r[rp++] = g;
    qsort(r, rp, sizeof(int), cmp1);
    printf("%d", r[rp - 1]);

    return 0;
}