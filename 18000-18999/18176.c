#include <stdio.h>

/*
���� : ���� [N, M](N <= M <= 10^12)�� �־��� ��, [N, M] ���� ��� �ڿ������� ��� ������ ���� ���Ѵ�.

�ذ� ��� : M������ ��� ������ �տ��� N - 1������ ��� ������ ���� ���� �ȴ�.
1���� X���� ��� ������ ���� 1���� sqrt(X)���� ���鼭 i^2���� ũ�� X ������ i�� ��� +
i^2 �̻��̸鼭 X ������ i�� ����� ���� ���� ���̴�.

�ֿ� �˰��� : ����, ������

��ó : CERC 2019 G��
*/

long long getcount(long long x) {
    long long r = 0;
    for (long long i = 1; i * i <= x; i++) {
        r += (x / i - i) * 2 + 1;
    }
    return r;
}

int main(void) {
    long long n, m, r = 0;
    scanf("%lld %lld", &n, &m);
    printf("%lld", getcount(m) - getcount(n - 1));
    return 0;
}