#include <stdio.h>

/*
���� : N(1 <= N <= 10^6)���� �־��� ��(<= 10^9, �ڿ���, ��������)�� ������ X���� �ǰ�, �ٸ� ������
������ 0���� �� �� ���� �������� ������ �ִ�. �̰��� ������ �� ��, ������ K(1 <= K <= 10^18) �̻���
�ǵ��� �ϴ� ���� ���� X�� ���Ѵ�.

�ذ� ��� : �Ű� ���� Ž���� ���� ���� ã�Ƴ����� �ȴ�. X�� ���� �ּڰ��� �ִ��� ���ϰ�,
���������� �� ������ �̿��� ������ ���� ���� K �̻��� ���� ���� X�� ã�Ƴ����� �ȴ�.
�̶�, �ִ� ������ �����÷ο� �����Ѵ�.

�ֿ� �˰��� : ����, �Ķ��Ʈ��

��ó : �Ѿ��E 2021 H��
*/

int up[1048576];

long long getsum(long long s, long long e) {
    return ((s + e) * (e - s + 1)) >> 1;
}

int canbe(int n, int m, long long k) {
    long long s = 0;
    for (int i = 0; i < n - 1; i++) {
        if (up[i + 1] - up[i] > m) s += getsum(1, m);
        else s += getsum(m - up[i + 1] + up[i] + 1, m);
    }
    s += getsum(1, m);
    return (s >= k);
}

int main(void) {
    int n;
    long long k, lo = 1, hi = 0x7A35090F, mid;
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &up[i]);
    }
    while (hi > lo) {
        mid = (hi + lo) >> 1;
        if (canbe(n, mid, k)) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld", lo);
    return 0;
}