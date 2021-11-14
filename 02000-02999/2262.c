#include <stdio.h>

/*
���� : N(N <= 256)���� �����ϴ� ��ʸ�Ʈ���� ������ �����ϸ� ������ ���� ���̰� �ּҰ� �ǵ��� �ϴ� ������
���� ���� ���� ���Ѵ�. ������ 1 �̻� N ���ϰ� �������� ����.

�ذ� ��� : ������ ���� ������� ������ ��ġ�� ������ �� ���� ����� ������ ���δ�.
�׸��� �� ����� �迭���� �����ϰ� �̸� 1���� �� �� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���
*/

int rnk[256];

int big(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, r = 0, worst;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &rnk[i]);
	}

	while (n > 1) { 
		worst = -1;
		for (int i = 0; i < n; i++) {
			if (rnk[i] == n) worst = i;
		}
		if (worst < 0) return 1;

		if (worst == n - 1) r += rnk[worst] - rnk[worst - 1];
		else if (worst == 0) r += rnk[worst] - rnk[worst + 1];
		else r += rnk[worst] - big(rnk[worst - 1], rnk[worst + 1]);

		for (int i = worst; i < n; i++) {
			rnk[i] = rnk[i + 1];
		}
		n--;
	}

	printf("%d", r);
}