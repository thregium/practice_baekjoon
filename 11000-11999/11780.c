#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 100)���� �������� �̷���� �׷����� M(M <= 100000)���� �ܹ��� ����ġ ������ �־��� ��,
��� ���� ������ �ִܰŸ��� ���ϰ�, �� ����� �ƹ��ų� �ϳ��� ����Ѵ�.

�ذ� ��� : �÷��̵�-���� �˰����� ����Ѵ�. �� ���� �ָ��� ���� ���� �����صΰ�, �̸� �̿��� ��θ� �����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����, ������
*/

int d[128][128], start[128][128], path[256];

int main(void) {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) d[i][j] = INF;
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (c < d[a][b]) d[a][b] = c;
		start[a][b] = b;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					start[i][j] = start[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", (d[i][j] == 1012345678) ? 0 : d[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == 0 || d[i][j] == 1012345678) {
				printf("0\n");
				continue;
			}
			a = i, c = 0;
			while (a != j) {
				path[c++] = a;
				a = start[a][j];
			}
			path[c++] = a;
			printf("%d ", c);
			for (int k = 0; k < c; k++) {
				printf("%d ", path[k]);
			}
			printf("\n");
		}
	}
}