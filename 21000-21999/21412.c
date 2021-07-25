#include <stdio.h>

/*
���� : �и�� ������ ���� N(N <= 1000)�̸� ���м��� �ƴ� ���� ū ���м��� ã�´�.

�ذ� ��� : �и� N / 2 + 1�� �� ���� ��� ���� ���� �и�� ������ �ִ������� 1���� Ȯ���Ѵ�.
1�� �м��� ������ �� �м��� ����ϰ� ���α׷��� �����Ѵ�. ���ڰ� 1�� ��� �׻� ���м��̹Ƿ� �׷��� ���� ã�� ���ϴ� ���� ����.

�ֿ� �˰����� : ����, ������, ��Ŭ���� ȣ����

��ó : ROI 2007H D��
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = n / 2 + 1; i < n; i++) {
        if (gcd(i, n - i) > 1) continue;
        printf("%d %d", n - i, i);
        break;
    }
    return 0;
}