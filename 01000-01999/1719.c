#include <stdio.h>
#define INF 1012345678;

/*
문제 : N(N <= 200)개의 정점으로 이루어진 그래프에서 M(M <= 10000)개의 양방향 간선들이 주어질 때, 각 정점 쌍마다
해당 정점으로 최단경로로 이동하기 위한 첫 경유지를 구한다. 모든 정점끼리 이동이 가능함이 보장된다.

해결 방법 : 플로이드-워셜 알고리즘을 이용한다. 경유지를 이용하는 것이 더 좋다면 첫 경유지를 그곳으로 바꾸는 방식이다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜, 역추적
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