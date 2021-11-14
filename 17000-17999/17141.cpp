#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N * N(N <= 50) ũ���� �����ҿ��� 0�� �� ĭ, 1�� ��, 2�� ���̷����� ���� �� �ִ� ĭ�� ��,
M(M <= 10)���� ���̷����� ���� ���̷����� ��� ĭ�� �����µ� �ɸ��� �ð� ��� ���� ª�� ���� ���Ѵ�.
���̷����� �� �ð� �����¿�� ���������� �����δ� ������ �ʴ´�. ��� ĭ�� �۶߸� �� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : �� ���̷������� ���� �� �ִ� ��� ������ �õ��غ���. �� ���ո��� �ش� ĭ�鿡 ���̷����� ���� ����,
��� ĭ�� ������ �ð��� �Ź� ������ �ȴ�. �ʱ�ȭ�� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���Ʈ ����
*/

int lab[64][64], vir[16][2], act[16][2], vis[64][64], dist[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, vp = 0, mn = 12345;
queue<pair<int, int>> q;

int isvalid(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return 0;
	if (vis[x][y]) return 0;
	if (lab[x][y] == 1) return 0;
	return 1;
}

int spread(int p) {
	//���̷������� �۶߸���.
	int x, y, t;
	for (int i = 0; i < p; i++) {
		q.push(pair<int, int>(act[i][0], act[i][1]));
		vis[act[i][0]][act[i][1]] = 1;
	}
	while (q.size()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
				vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
				dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
				q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
			}
		}
	}
	int r = 0;
	for (int i = 0; i < n; i++) {
		//�湮�� �Ÿ��� �ʱ�ȭ�ϸ� ��� ĭ�� �������� ���θ� Ȯ���ϰ� �� �ð��� Ȯ���Ѵ�.
		for (int j = 0; j < n; j++) {
			if (!vis[i][j] && lab[i][j] == 0) {
				r = 12345;
			}
			if (lab[i][j] == 0 && r < dist[i][j]) {
				r = dist[i][j];
			}
			vis[i][j] = 0;
			dist[i][j] = 0;
		}
	}
	while (!q.empty()) q.pop();

	return r;
}

void track(int p, int m, int c, int l) {
	//���̷����� ������ �����.
	int r;
	if (m == c) {
		r = spread(m);
		if (r < mn) {
			mn = r;
		}
	}
	for (int i = l + 1; i < p; i++) {
		act[c][0] = vir[i][0];
		act[c][1] = vir[i][1];
		track(p, m, c + 1, i);
	}
}

int main(void) {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 2) {
				//���̷����� �ִ� ĭ�� Ȯ���ϰ� ���̷����� �ʱ�ȭ�Ѵ�.
				vir[vp][0] = i;
				vir[vp++][1] = j;
				lab[i][j] = 0;
			}
		}
	}
	track(vp, m, 0, -1);
	if (mn > 10000) printf("-1");
	else printf("%d", mn);
	return 0;
}
