#include <stdio.h>

/*
���� : S(S <= 10^9)���� ��ȭ�� �ְ�, �ѹ��� K(K <= 100)�� �ŵ�������ŭ ��ȭ�� ������ �� �ִٸ�
������ �̱� �� �ִ� ���(�������� ��ȭ�� ��)�� �ּڰ��� ã�´�.

�ذ� ��� : �߰� ����

�ֿ� �˰��� : ����, ���� �̷�

��ó : BAPC 2011 G��
*/

int main(void) {
	int t, s, k;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d %d", &s, &k);
		if (k & 1) printf("%d\n", s & 1);
		else {
			if (s % (k + 1) == k) printf("%d\n", k);
			else printf("%d\n", (s % (k + 1)) & 1);
		}
	}
	return 0;
}
