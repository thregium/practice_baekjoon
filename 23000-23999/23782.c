#include <stdio.h>
#include <stdlib.h>

/*
���� : �ڿ��� N(N <= 10^12)�� �־��� ��, N ������ ��� �ڿ�����
N�� ���� �ٸ� ����� ������ ��Ÿ�� �� �ִ� �� ���Ѵ�.

�ذ� ��� : N�� ��� ������� ã�� ���� ������������ �����Ѵ�.
��� �ڿ����� ������ ��Ÿ���� ���ؼ��� ��������� �� + 1���� ū ����� ���ͼ��� �� �ȴ�.
��������� ���� ������ �����鼭 �׷��� ��찡 �ִ� �� ������������ Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : CTU 2021 F��
*/

long long dv[103000];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, cnt, res;
    long long n, sum;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld", &n);
        cnt = 0;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i) continue;
            dv[cnt++] = i;
            if (i * i != n) dv[cnt++] = n / i;
        }
        qsort(dv, cnt, sizeof(long long), cmp1);
        res = 1, sum = 0;
        for (int i = 0; i < cnt; i++) {
            if (dv[i] > sum + 1) res = 0;
            sum += dv[i];
        }
        printf("%s\n", res ? "Yes" : "No");
    }
    return 0;
}
