#include <stdio.h>

/*
���� : N(N <= 10^9) ������ �ڿ��� ��� K(K <= 20)���� �ڿ��� �� �ϳ� �̻��� �ڿ�����
������ �������� ���� ������ ���Ѵ�. �� �ڿ����� 10^9 ���ϴ�.

�ذ� ��� : ���� ������ ������ ������ Ȧ������ ���� ������� ���� ���ϰ� ¦������ ����
������� ���� ���� ���ϴ� ���� ���´�. ������� ��Ŭ���� ȣ������ �̿��� �ּ� ������� ���� ��,
N�� �� ������ ������ ���� �� �ִ�. �����÷ο� �����Ѵ�.

�ֿ� �˰��� : ����, ������, ��Ŭ���� ȣ����, ���� ����
*/

long long a[32];

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, k, pcnt;
    long long res = 0, lcm;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < (1 << k); i++) {
        pcnt = 0, lcm = 1;
        for (int j = 0; j < k; j++) {
            if ((i >> j) & 1) {
                pcnt++;
                lcm = (lcm * a[j]) / gcd(lcm, a[j]);
                if (lcm > n) lcm = n + 1;
            }
        }
        if (pcnt & 1) res += n / lcm;
        else res -= n / lcm;
    }
    printf("%lld", res);
    return 0;
}