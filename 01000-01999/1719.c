#include <stdio.h>
#define INF 1012345678;

/*
���� : N(N <= 200)���� �������� �̷���� �׷������� M(M <= 10000)���� ����� �������� �־��� ��, �� ���� �ָ���
�ش� �������� �ִܰ�η� �̵��ϱ� ���� ù �������� ���Ѵ�. ��� �������� �̵��� �������� ����ȴ�.

�ذ� ��� : �÷��̵�-���� �˰����� �̿��Ѵ�. �������� �̿��ϴ� ���� �� ���ٸ� ù �������� �װ����� �ٲٴ� ����̴�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����, ������
*/

int d[256][256];
int start[256][256];

int main(void) {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) d[i][j] = INF;
		d[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = c;
		d[b][a] = c;
		start[a][b] = b;
		start[b][a] = a;
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
			if (i == j) printf("- ");
			else printf("%d ", start[i][j]);
		}
		printf("\n");
	}
}