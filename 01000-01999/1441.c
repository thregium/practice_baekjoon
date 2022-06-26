#include <stdio.h>

/*
���� : ���� [L, R](1 <= L <= R <= 10^9)���� N(N <= 18)���� �ڿ���(<= 10^9) �� ��� �ϳ���
������ �������� �ڿ����� ������ ���Ѵ�.

�ذ� ��� : ���� ������ ������ �̿��Ͽ� Ȧ�� ���� ���ҷ� ���������� ���� ���� �� - ¦�� ����
���ҷ� ���������� ���� ���� ���� ���ϸ� �ȴ�. �� �������� �� �������� ���������� ���� ������
��Ŭ���� ȣ�������� �ּҰ������ ���ϴ� ����� ���� ã���� �ȴ�. ��, �����÷ΰ� �Ͼ�� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : ����, ��Ŭ���� ȣ����, ���� ����
*/

long long a[32];

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, l, r, pcnt;
    long long res = 0, lcm;
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < (1 << n); i++) {
        pcnt = 0, lcm = 1;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                pcnt++;
                lcm = (lcm * a[j]) / gcd(lcm, a[j]);
                if (lcm > r) lcm = r + 1;
            }
        }
        if (pcnt & 1) res += r / lcm - (l - 1) / lcm;
        else res -= r / lcm - (l - 1) / lcm;
    }
    printf("%lld", res);
    return 0;
}