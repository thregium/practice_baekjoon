#include <stdio.h>

int cz[128][128], ot[128][128], vis[128][128], mlt[128][128];
int n, m;

int ismlt(int x, int y) {
	return ot[x - 1][y] + ot[x + 1][y] + ot[x][y - 1] + ot[x][y + 1];
}

int isvalid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (vis[x][y] || !cz[x][y]) return 0;
	return 1;
}

int isvalid2(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (vis[x][y] || cz[x][y]) return 0;
	return 1;
}

void dfso(int x, int y) {
	vis[x][y] = 1;
	ot[x][y] = 1;
	if (isvalid2(x, y - 1)) dfso(x, y - 1);
	if (isvalid2(x - 1, y)) dfso(x - 1, y);
	if (isvalid2(x, y + 1)) dfso(x, y + 1);
	if (isvalid2(x + 1, y)) dfso(x + 1, y);
}

int dfs(int x, int y) {
	int r = 1;
	vis[x][y] = 1;
	if (ismlt(x, y)) mlt[x][y] = 1;

	if (isvalid(x, y - 1)) r += dfs(x, y - 1);
	if (isvalid(x - 1, y)) r += dfs(x - 1, y);
	if (isvalid(x, y + 1)) r += dfs(x, y + 1);
	if (isvalid(x + 1, y)) r += dfs(x + 1, y);

	return r;
}

int main(void) {
	int t = 0, c, r = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &cz[i][j]);
			r += cz[i][j];
		}
	}
	if (!r) {
		printf("0\n0");
		return 0;
	}
	while (1) {
		c = 0;
		dfso(0, 0);
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (!vis[i][j] && cz[i][j]) {
					c += dfs(i, j);
				}
			}
		}
		r = 1;
		t++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ot[i][j] = 0;
				vis[i][j] = 0;
				if (mlt[i][j] && cz[i][j]) {
					cz[i][j] = 0;
					mlt[i][j] = 0;
				}
				else if (cz[i][j]) r = 0;
				else if (mlt[i][j]) mlt[i][j] = 0;
			}
		}
		if (r) break;
		if (t > 100) return 1;
	}
	printf("%d\n%d", t, c);
	return 0;
}
