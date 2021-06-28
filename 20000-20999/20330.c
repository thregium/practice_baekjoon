#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^18)�� �־��� ��, ���� N�� �ǵ��� �ϴ� 10�� ������ ��Ī���� ��Ÿ����.

�ذ� ��� : �� �ܰ踶�� N ������ ũ���� ���� �� ��Ī���� �����. �׷��� ���� �ܰ迡���� �ڸ�����
���� �ܰ��� �ڸ����� D��� ���� ��, �ִ� (D + 1) / 2�� �ȴ�. ù �ܰ迡�� �ִ� 19�ڸ��� ���� �� �����Ƿ�,
��Ī���� 19->10->5->3->2->1->1�� ���ƾ� 7���� ����ϴ�. �̶� 1->1�� �Ǵ� ���� 10�� ������ ����,
���� �ڸ� ���� 2�� ��� �ϴ� ������ ����̴�.

�ֿ� �˰��� : 

��ó : UKIEPC 2020 B�� // BAPC 2020 B��
*/

long long ns[16], b10[24];
int ncnt = 0;

int getdigits(long long n) {
    for (int i = 18; i > 0; i--) {
        if (n >= b10[i]) return i + 1;
    }
    return 1;
}

long long getpal(long long n) {
    if (n == 10) return 9;
    int digits = getdigits(n);
    long long fpal = 0;
    for (int i = 0, j = digits - 1; i <= j; i++, j--) {
        fpal += b10[i] * (n / b10[j] % 10);
        if (i != j) fpal += b10[j] * (n / b10[j] % 10);
    }
    if (fpal <= n) return fpal;
    long long m = n - b10[digits >> 1];
    fpal = 0;
    digits = getdigits(m);
    for (int i = 0, j = digits - 1; i <= j; i++, j--) {
        fpal += b10[i] * (m / b10[j] % 10);
        if (i != j) fpal += b10[j] * (m / b10[j] % 10);
    }
    return fpal;
}

int main(void) {
    b10[0] = 1;
    for (int i = 1; i <= 18; i++) b10[i] = b10[i - 1] * 10;
    long long n;
    scanf("%lld", &n);
    while (n > 0) {
        ns[ncnt++] = getpal(n);
        n -= ns[ncnt - 1];
    }
    printf("%d\n", ncnt);
    for (int i = 0; i < ncnt; i++) {
        printf("%lld\n", ns[i]);
    }
    return 0;
}