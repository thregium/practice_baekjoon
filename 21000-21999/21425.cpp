#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : 3�������� H * M * N(H, M, N <= 50) ũ���� ���ڿ��� �����¿�� �Ʒ��� �̵� �����ϰ�, �� �̵����� 5�ʾ� �ɸ���.
o�� ǥ�õ� ĭ�� �̵��� �� ���ٸ�, 1�� ǥ�õ� ĭ���� 2�� ǥ�õ� ĭ���� �ּ� �� �ʰ� �ɸ����� ���Ѵ�.
�̵� ������ ��츸 �־�����.

�ذ� ��� : BFS�� ���� 2�� ���� �Ÿ��� ���� �� 5�� �����ָ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ROI 2006H G��
*/

char laby[64][64][64];
int vis[64][64][64], dist[64][64][64];
int dxy[5][3] = { {0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0} };
int h, m, n;

queue<tuple<int, int, int>> q;

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= h || y >= m || z >= n) return 0;
    if (vis[x][y][z] || laby[x][y][z] == 'o') return 0;
    return 1;
}

int bfs(int x, int y, int z) {
    vis[x][y][z] = 1;
    q.push(make_tuple(x, y, z));
    while (q.size()) {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        q.pop();
        if (laby[x][y][z] == '2') {
            return dist[x][y][z];
        }
        for (int i = 0; i < 5; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], z + dxy[i][2])) {
                q.push(make_tuple(x + dxy[i][0], y + dxy[i][1], z + dxy[i][2]));
                vis[x + dxy[i][0]][y + dxy[i][1]][z + dxy[i][2]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]][z + dxy[i][2]] = dist[x][y][z] + 1;
            }
        }
    }
}

int main(void) {
    int x = 0, y = 0, z = 0;
    scanf("%d %d %d", &h, &m, &n);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%s", laby[i][j]);
            for (int k = 0; k < n; k++) {
                if (laby[i][j][k] == '1') {
                    x = i;
                    y = j;
                    z = k;
                }
            }
        }
    }
    printf("%d", bfs(x, y, z) * 5);
    return 0;
}