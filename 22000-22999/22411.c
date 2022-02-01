#include <stdio.h>
#define HI 1234567890987654321

/*
���� : ������ ���� �������� 0���� ������� �ְ�, �� ���� �� K(2 <= K <= 100000)�� ��� ��ȣ�� ������
���� ����, ���� ������ 0���� �ٽ� ��ȣ�� ���̴� ���� �ݺ����� ��, N(N <= 100000)��° �ൿ����
0���� �ִ� ���� ���� �� ���̾����� ���Ѵ�. ���� 10^18 ������ ��츸 �־�����.

�ذ� ��� : �Ű� ���� Ž���� ���� N�� �ൿ�� �� �� ���� ���� �� ���θ� Ȯ���ϸ鼭
�׷��� �� ��� ���� ���� ���� ���ϸ� ���� �ȴ�. �ּڰ��� 0, �ִ��� 10^18�� ���� �� �ִ�.

�ֿ� �˰��� : ����, �Ķ��Ʈ��

��ó : JAG 2015S2 B��
*/

long long living(long long n, long long k, long long x) {
    if (n == 0) return 1;
    for (int i = 1; i < n; i++) {
        x -= x / k + 1;
    }
    return (x > 0);
}

int main(void) {
    int n, k;
    long long hi = HI, lo = 0, mid;
    scanf("%d %d", &n, &k);
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (living(n - 1, k, mid)) hi = mid;
        else lo = mid + 1;
    }
    while (lo == HI);
    printf("%lld\n", lo);
    return 0;
}