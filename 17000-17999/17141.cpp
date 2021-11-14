#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * N(N <= 50) 크기의 연구소에서 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 칸일 때,
M(M <= 10)개의 바이러스를 놓고 바이러스가 모든 칸에 퍼지는데 걸리는 시간 가운데 가장 짧은 것을 구한다.
바이러스는 매 시간 상하좌우로 퍼져나가며 벽으로는 퍼지지 않는다. 모든 칸에 퍼뜨릴 수 없다면 -1을 출력한다.

해결 방법 : 각 바이러스들을 놓을 수 있는 모든 조합을 시도해본다. 각 조합마다 해당 칸들에 바이러스를 놓은 다음,
모든 칸에 퍼지는 시간을 매번 세보면 된다. 초기화에 유의한다.

주요 알고리즘 : 그래프 이론, BFS, 브루트 포스
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
	//바이러스들을 퍼뜨린다.
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
		//방문과 거리를 초기화하며 모든 칸에 퍼졌는지 여부를 확인하고 그 시간을 확인한다.
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
	//바이러스의 조합을 만든다.
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
				//바이러스가 있는 칸을 확인하고 바이러스를 초기화한다.
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
