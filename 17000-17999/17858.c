#include <stdio.h>

/*
���� : ���� N(N <= 10^6)�� ���� ���������� ������ �������� �̺� Ž���� ���� ã�� �� �ִ� ���� ������ ���Ѵ�.
��� ������ ������ 2^31���� ���� ���� �ƴ� �����̴�.

�ذ� ��� : ������ ���� ���� ����, �̺� Ž���� ���� ã�� �� �ִ� ��
���θ� Ȯ���ϸ� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, �̺� Ž��

��ó : ECNA 2019 G��
*/

long long x[1048576];

int main(void) {
    long long n, m, a, c, res = 0, lo, mid, hi;
    scanf("%lld %lld %lld %lld", &n, &m, &a, &c);
    scanf("%lld", &x[0]);
    for (int i = 1; i <= n; i++) {
        x[i] = (x[i - 1] * a + c) % m;
    }
    for (int i = 1; i <= n; i++) {
        lo = 1, hi = n;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            if (x[mid] == x[i]) {
                res++;
                break;
            }
            else if (x[mid] < x[i]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    printf("%lld", res);
    return 0;
}