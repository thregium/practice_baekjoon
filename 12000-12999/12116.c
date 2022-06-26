#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^10)�� �־��� ��, �������� N�� �Ǵ� ������ N N�� �����ϰ� ��� ����Ѵ�.
������ ������� �ʴ´�.

�ذ� ��� : �� ���� �߽����� �ξ��� ���� �����غ��� ������ Ȧ��, ������ ������ �ڿ����� ��
����� ���·� �ٲ� �� �ִ�. �� ������ �������� 1 �̻��̰� ���� ������� ���� �������̶��
�� ������ ����Ѵ�.

�ֿ� �˰��� : ����, ������

��ó : COCI 16/17#7 2��
*/

long long ptd[1024], pcnt;

void swap(long long* a, long long* b) {
    long long c = *a;
    *a = *b;
    *b = c;
}

int found(long long x) {
    for (int i = 0; i < pcnt; i++) {
        if (ptd[i] == x) return 1;
    }
    return 0;
}

void printcon(long long x, long long n) {
    long long y = n / x;
    for (int i = 0; i < 2; i++) {
        if (x & 1) {
            if (y - (x >> 1) >= 1 && x > 1) {
                if (!found(y - (x >> 1))) {
                    ptd[pcnt++] = y - (x >> 1);
                    printf("%lld %lld\n", y - (x >> 1), y + (x >> 1));
                }
            }
            if ((x >> 1) - y + 1 >= 1) {
                if (!found((x >> 1) - y + 1)) {
                    ptd[pcnt++] = (x >> 1) - y + 1;
                    printf("%lld %lld\n", (x >> 1) - y + 1, (x >> 1) + y);
                }
            }
        }
        swap(&x, &y);
    }
}

int main(void) {
    long long n, d;
    scanf("%lld", &n);
    for (long long i = 1; i * i <= n; i++) {
        if (n % i) continue;
        printcon(i, n);
    }
    return 0;
}