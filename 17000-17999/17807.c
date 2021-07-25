#include <stdio.h>
#define MOD 1000000007

/*
���� : A�� B�θ� �̷���� K�ڸ� ������ C�� ������ ���Ѵ�.

�ذ� ��� : ���� A�� B�� ���� �ٸ� ���� ��� A �Ǵ� B�� ������ 2^(k - 1) * k�� ����. ��, K = 0�� ��쿡�� 0�� �Ǿ�� �Ѵ�.
A�� B�� ���� ��쿡�� A = B�� ������ K���̴�. ����, C�� A, B �� �ٿ� �ٸ� ��쿡�� �翬�� 0���� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, ���̽� ��ũ

��ó : CTU 2019 B1��
*/

long long b2[1024];

int main(void) {
    int a, b, c, k;
    b2[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        b2[i] = b2[i - 1] * 2 % MOD;
    }
    scanf("%d %d %d %d", &a, &b, &k, &c);
    if (k == 0 || (c != a && c != b)) {
        printf("0");
    }
    else if (c == a && c == b) {
        printf("%d", k);
    }
    else {
        printf("%lld", b2[k - 1] * k % MOD);
    }
    return 0;
}