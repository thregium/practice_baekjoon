#include <stdio.h>

/*
���� : N - 1���� 1���� 1�� �����ϴ� �������� ��ü�� ���� ��ġ�� �� �� ° ���� �� ���Ѵ�.

�ذ� ��� : �Ű� ���� Ž���� �̿��Ͽ� �տ������� ���� ��ü�� ���� �̻��� �Ǵ� ù X�� ã���� �ȴ�.

�ֿ� �˰��� : ����, �Ķ��Ʈ��?

��ó : PacNW 2017 Q�� // SEUSA 2017D2 C��
*/

long long getarithsum(long long a, long long b) {
    return ((b - a + 1) * (b + a)) >> 1;
}

int main(void) {
    long long n, s = 0, lo, hi, mid;
    scanf("%lld", &n);
    s = getarithsum(1, n - 1);
    lo = 1, hi = n - 1;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (getarithsum(n - mid, n - 1) * 2 >= s) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld", lo);
    return 0;
}