#include <stdio.h>

/*
���� : N(N <= 1120)�� K(K <= 14)�� �־��� ��, N�� ���� �ٸ� K(K <= 14)���� �Ҽ��� ������ ����� ����� ���� ���Ѵ�.

�ذ� ��� : �� �Ҽ����� DP�� �� ������ �ȴ�.

�ֿ� �˰��� : DP, ����, �Ҽ� ����

��ó : Yokohama 2006 D��
*/

int sieve[1280], mem[1280][16];

int main(void) {
    int t, n, k;
    mem[0][0] = 1;
	for (int i = 2; i <= 1120; i++) {
		for (int j = i * 2; j <= 1120; j += i) sieve[j] = 1;
		if (!sieve[i]) {
			for (int j = 1120; j >= i; j--) {
				for (int k = 1; k <= 14; k++) {
					mem[j][k] += mem[j - i][k - 1];
				}
			}
		}
	}

    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
		printf("%d\n", mem[n][k]);
    }
    return 0;
}