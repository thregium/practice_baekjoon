#include <stdio.h>

/*
���� : RSA ��ȣȭ�� Ű �� N, E�� �־��� ��, D�� ���� ���Ѵ�. N�� 10^6 �̸��� ���̴�.

�ذ� ��� : N�� ���� �����Ƿ� ���Ʈ ������ �� �Ҽ� P, Q�� ã�� �ٽ� ���Ʈ ������
���ΰ� 1�� �Ǵ� D�� ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������, ���Ʈ ����

��ó : VTH 2016 D��
*/

int main(void) {
    long long t, n, e, p, q, f;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld", &n, &e);
        p = -1, q = -1;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                p = i, q = n / i;
                break;
            }
        }
        if (p < 0) return 1;
        f = (p - 1) * (q - 1);
        for (long long i = 1;; i++) {
            if (i * e % f == 1) {
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}