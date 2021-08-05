#include <stdio.h>

/*
���� : N * N ũ���� �������� �������� ����, ����, �밢������ �Ͽ� �ű� ��, �������� ���� ������ ������ �Ʒ��� �ű��
����� �������� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �� ĭ�� �� ���⸶�� �������� ���� ��ġ�� �ȴ�.

�ֿ� �˰��� : DP
*/

long long room[32][32], mem[32][32][3]; //0 : ����, 1 : �밢��, 2 : ����

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%lld", &room[i][j]);
	}
	mem[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0 && !room[i][j]) {
				mem[i][j][2] += mem[i - 1][j][2];
				mem[i][j][2] += mem[i - 1][j][1];
			}
			if (j > 0 && !room[i][j]) {
				mem[i][j][0] += mem[i][j - 1][0];
				mem[i][j][0] += mem[i][j - 1][1];
			}
			if (i > 0 && j > 0 && !room[i][j] && !room[i][j - 1] && !room[i - 1][j]) {
				mem[i][j][1] += mem[i - 1][j - 1][0];
				mem[i][j][1] += mem[i - 1][j - 1][1];
				mem[i][j][1] += mem[i - 1][j - 1][2];
			}
		}
	}
	printf("%lld", mem[n - 1][n - 1][0] + mem[n - 1][n - 1][1] + mem[n - 1][n - 1][2]);
	return 0;
}
