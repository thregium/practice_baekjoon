#include <stdio.h>

/*
���� : �Ľ�Į�� �ﰢ���� R�� C������ W(R + W, C + W <= 30) ĭ ũ���� �ﰢ�� �ȿ� �ִ� ������ ���� ���Ѵ�.

�ذ� ��� : ���� �Ľ�Į�� �ﰢ���� ���ϰ� �ﰢ�� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���շ�, DP

��ó : koi4u 2008_05 A��
*/

long long mem[32][32];

int main(void) {
	int r, c, w;
	long long res = 0;
	mem[0][0] = 1;
	for (int i = 1; i <= 30; i++) {
		mem[i][0] = 1;
		for (int j = 1; j <= 30; j++) {
			mem[i][j] = mem[i - 1][j] + mem[i - 1][j - 1];
		}
	}
	scanf("%d %d %d", &r, &c, &w);
	r--, c--;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j <= i; j++) res += mem[i + r][j + c];
	}
	printf("%lld", res);
}