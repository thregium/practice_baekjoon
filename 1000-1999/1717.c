#include <stdio.h>

int u[1048576];

int find(int x) {
	if (u[x] < 0) return x;
	else return u[x] = find(u[x]);
}

int main(void) {
	int n, m, o, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) u[i] = -1;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &o, &a, &b);
		if (o) {
			printf("%s\n", find(a) == find(b) ? "YES" : "NO");
		}
		else {
			if(find(a) != find(b)) u[find(b)] = find(a);
		}
	}
	return 0;
}
