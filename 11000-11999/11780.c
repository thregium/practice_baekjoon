#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100)개의 정점으로 이루어진 그래프와 M(M <= 100000)개의 단방향 가중치 간선이 주어질 때,
모든 정점 사이의 최단거리를 구하고, 그 방법을 아무거나 하나씩 출력한다.

해결 방법 : 플로이드-워셜 알고리즘을 사용한다. 각 정점 쌍마다 다음 점을 저장해두고, 이를 이용해 경로를 복원하면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜, 역추적
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