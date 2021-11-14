#include <stdio.h>

/*
���� : N(N <= 10^6)���� ���ڰ� �ְ�, ������ 10^9 ������ �����̴�. ��� ���ڸ� ���� ũ��� M(M <= 10^6)���� �������� �� ��,
�� ������� �� �� �ִ� ������ �ִ� ���� ���Ѵ�. ��, ���ڴ� �� �������� �־�� �Ѵ�.

�ذ� ��� : �Ű� ���� Ž���� �̿��Ͽ� ���ڸ� X�� ���̸�ŭ �������� �� ������ �� �� �ִ� ��� ����
M�� �̻��� ���� ū X�� ���ϸ� �ȴ�.

�ֿ� �˰��� : �Ķ��Ʈ��

��ó : ȫ�ʹ� 2018 H��
*/

int snak[1048576];

int getres(int n, long long x) {
    long long r = 0;
    for (int i = 0; i < n; i++) {
        r += snak[i] / x;
    }
    return r;
}

int main(void) {
    int m, n;
    long long lo = 0, hi = 12345678987654321, mid;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &snak[i]);
    }
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (getres(n, mid) >= m) lo = mid;
        else hi = mid - 1;
    }
    printf("%lld", lo);
    return 0;
}