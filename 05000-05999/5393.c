#include <stdio.h>

/*
���� : N(N <= 10^9)�� �־��� ��, ��� ¦���� ���� ������ �������� ������ �ְ�, ��� Ȧ���� ���� 3k + 1�� ��������
������ �ִٰ� �� ��, N ������ ���� �̻��� ������ ���� ������ ���Ѵ�.

�ذ� ��� : ����� �� �ϸ� �ȴ�.

�ֿ� �˰����� : ����

��ó : BAPC 2010 D��
*/

int main() {
	int t, n;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d\n", &n);
		printf("%d\n", (n + 1) / 2 * 2 - ((n - 1) / 3 + 1) / 2);
	}
	return 0;
}