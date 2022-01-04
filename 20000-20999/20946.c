#include <stdio.h>
#include <stdlib.h>

/*
���� : 2 �̻��� �ڿ��� N(N <= 10^12)�� �־��� ��, N�� �ռ����� �����ϴ� ��� ��� ���� ������ ���� ���� ���� ���Ѵ�.
�׷��� ����� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : N�� ���μ������� ���� ���������� ������ ����, �տ������� 2���� �������.
���� 3���� ���� ��� 3���� �ѹ��� ���´�.

�ֿ� �˰��� : �׸��� �˰���, ����, �Ҽ� ����

��ó : SUAPC 2021W K��
*/

long long f[64];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int cnt = 0;
    long long n, m, r, r2 = 1;
    scanf("%lld", &m);
    //for (long long m = 2;; m++) {
        cnt = 0, r2 = 1;
        n = m;
        for (long long i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                f[cnt++] = i;
            }
        }
        f[cnt++] = n;
        if (f[cnt - 1] == 1) cnt--;
        qsort(f, cnt, sizeof(long long), cmp1);

        if (cnt < 2) {
            printf("-1\n");
            return 0;
            //continue;
        }
        for (int i = 0; i < cnt - 1; i += 2) {
            r = (i == cnt - 3 ? f[i] * f[i + 1] * f[i + 2] : f[i] * f[i + 1]);
            printf("%lld ", r);
            r2 *= r;
            for (long long j = 2; j * j <= r; j++) {
                if (r % j == 0) r /= j;
            }
            if (r == (i == cnt - 3 ? f[i] * f[i + 1] * f[i + 2] : f[i] * f[i + 1])) {
                return 3;
            }
        }
        printf("\n");
        if (r2 != m) {
            //printf("%lld", m);
            return 2;
        }
    //}
    return 0;
}