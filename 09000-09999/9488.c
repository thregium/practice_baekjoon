#include <stdio.h>

/*
���� : N(N <= 10^6)��° ���ü���� ���Ѵ�.

�ذ� ��� : N��° �ﰢ���� �̸� ã�� ���� ���� �ѹ� �� ���ؼ� ���ü���� �����θ� �ȴ�.

�ֿ� �˰��� : ����

��ó : SEUSA 2013D2 B��
*/

long long r[1048576];

int main(void) {
    int n;
    for (int i = 1; i <= 1000000; i++) {
        r[i] = r[i - 1] + i;
    }
    for (int i = 1; i <= 1000000; i++) {
        r[i] += r[i - 1];
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%lld\n", r[n]);
    }
    return 0;
}