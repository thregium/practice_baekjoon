#include <stdio.h>

/*
���� : N(N <= 10^9)�� �־��� ��, �� ���� �м��� ���ļ� 1/N�� �ǵ��� �ϴ� �м��� ������ ���Ѵ�.

�ذ� ��� : N�� ���μ����� �� ����, �� ���μ��� ���� * 2 + 1�� ���� �ؼ� ����� ���� ����
N���� ������ �ָ� �ȴ�. �̷��� �Ǵ� ������ �̷��� ��츦 ������ �����ϸ� pq = N^2��,
���� ������ N^2�� ��� ������ �������� �����̴�.

�ֿ� �˰��� : ����, ������, ���μ�����

��ó : TUD 2006 1��
*/

int main(void) {
	int t, n, tmp, pcnt;
	long long res = 1;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		res = 1;
		tmp = n;
		for (int j = 2; j * j <= tmp; j++) {
			pcnt = 0;
			while (tmp % j == 0) {
				tmp /= j;
				pcnt++;
			}
			res *= pcnt * 2LL + 1;
		}
		if (tmp > 1) res *= 3;
		res = res / 2 + 1;
		printf("Scenario #%d:\n%lld\n\n", tt, res);
	}
	return 0;
}