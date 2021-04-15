#include <stdio.h>

/*
문제 : N(N <= 100)개의 정점으로 이루어진 그래프가 주어질 때, 가장 먼 정점의 거리가 가장 작은 정점을 출력한다.

해결 방법 : N의 수가 충분히 작으므로 각 정점에 대해 BFS를 시행해 가장 먼 정점의 거리를 찾은 다음 최솟값인 정점을 찾아 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS, 브루트 포스
*/

int f[128][5120], vis[128], dist[128], q[1024];
int qf, qr;

int bfs(int x) {
	q[qr++] = x;
	while(qr - qf) {
		x = q[qf++];
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = 1; i <= f[x][0]; i++) {
			q[qr++] = f[x][i];
			dist[f[x][i]] = dist[x] + 1;
		}
	}
}

int main(void) {
	int n, m, a, b, s, best = 1234567, besf = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		f[a][++f[a][0]] = b;
		f[b][++f[b][0]] = a;
	}
	for(int i = 1; i <= n; i++) {
		qf = 0;
		qr = 0;
		bfs(i);
		s = 0;
		for(int j = 1; j <= n; j++) s += dist[j];
		if(s < best) {
			best = s;
			besf = i;
		}
		for(int j = 1; j <= n; j++) {
			dist[j] = 0;
			vis[j] = 0;
		}
	}
	printf("%d", besf);
	return 0;
}
