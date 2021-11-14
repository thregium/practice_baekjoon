#include <stdio.h>

/*
���� : N(N <= 500000)���� �ڿ����� �־��� ��, �ڿ��� X(X <= 10^6)�� ���μ��� �ڿ����� ����� ���Ѵ�.
���μ��� �ڿ����� �ּ� 1�� �̻� ���´�.

�ذ� ��� : ��Ŭ���� ȣ������ �̿��Ͽ� ���μ� ���θ� ���ϰ� ���μ��� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ����, ������, ��Ŭ���� ȣ����
*/

int a[524288];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, x;
    long long sum = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (gcd(a[i], x) == 1) {
            sum += a[i];
            cnt++;
        }
    }
    if (cnt == 0) return 1;
    printf("%.9f", (double)sum / cnt);
    return 0;
}