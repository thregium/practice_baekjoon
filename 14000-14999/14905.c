#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^8)�� ���� �� �־��� ��, �� ���� �Ҽ� 4���� ������ ��Ÿ�� �� �ִ��� ���ϰ�,
�׷��ϴٸ� �� ��� �� �ϳ��� ����Ѵ�.

�ذ� ��� : �������� ������ ���� N�� 8 �̻��� ��� �׻� �����ϴ�. N�� ¦���� ��� 2 2, Ȧ���� ��� 2 3�� �̸� ����ϸ�
���� �� ���� 4 �̻��� ¦���� �ȴ�. 4 �̻��� ��� ¦���� �׻� �� �Ҽ��� ������ ��Ÿ�� �� �ֱ� ������
�Ҽ����� ���� ������ Ȯ���� ���� �ݵ�� ���� ������ �ȴ�.

�̶�, N�� ������ ũ�� ������ ��Ʈ ������ �̿��� �����佺�׳׽��� ü�� ������ ���� ����. ����, 2�� ������ ��� �Ҽ���
Ȧ���� ������ �ѹ��� 2�� ���� �ø� �� �ֵ��� 10 �̸��� ���� �̸� ��ó���� �ϴ� ���� ���� �� �ִ�.

�ֿ� �˰����� : ����, �����佺�׳׽�, ��Ʈ��

��ó : �Ѿ��E 2017A A��
*/

unsigned char sieve[13107200];

int main(void) {
    int n;
    for (int i = 2; i <= 50000000; i++) {
        if (sieve[i >> 3] & (1 << (i & 7))) continue;
        for (int j = i * 2; j <= 100000000; j += i) sieve[j >> 3] |= (1 << (j & 7));
    }
    while (scanf("%d", &n) != EOF) {
        if (n < 10) {
            if (n < 8) printf("Impossible.\n");
            else if (n == 8) printf("2 2 2 2\n");
            else printf("2 2 2 3\n");
            continue;
        }

        if (n & 1) {
            printf("2 3 ");
            n -= 5;
        }
        else {
            printf("2 2 ");
            n -= 4;
        }
        for (int i = 3; i * 2 <= n; i += 2) {
            if (!(sieve[i >> 3] & (1 << (i & 7))) && !(sieve[(n - i) >> 3] & (1 << ((n - i) & 7)))) {
                printf("%d %d\n", i, n - i);
                break;
            }
        }
    }
    return 0;
}