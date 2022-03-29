#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N * M(N, M <= 100) ũ���� ���ڿ� '0', '1', 'S', 'L', 'R', 'U', 'D'�� ���� �ִ�.
'S'�� ĭ���� �����ϸ� '0'�� ĭ���δ� ������ �� �ְ�, '1'�� ĭ���δ� ������ �� ����.
�ٸ� ĭ���� �� ĭ�� ���� ���⿡�� ���� ��츸 ������ �� �ִ�. �̶�, ������ �����ڸ��� �ð� T(T <= 200) ����
�����ϴ� ����� �ִٸ� �ִ� �ð���, ���ٸ� "NOT POSSIBLE"�� ����Ѵ�.

�ذ� ��� : BFS�� ���� 'S'���� �̵��ϸ� �ִ� �Ÿ��� ���س����� �����ڸ��� T ���� �����ϴ� �� �˾ƺ���,
�׷��ϴٸ� �׶��� �Ÿ��� Ȯ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : VTH 2019 B��
*/

char wall[128][128], vis[128][128];
int dist[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char c[] = "LURD";
int h, w;
queue<pair<int, int>> q;

int isvalid(int x, int y, int d) {
    int nx = x + dxy[d][0];
    int ny = y + dxy[d][1];
    if (nx < 0 || ny < 0 || nx >= h || ny >= w) return 0;
    if (vis[nx][ny] || !(wall[nx][ny] == '0' || wall[nx][ny] == c[d])) return 0;
    return 1;
}

int bfs(int x, int y) {
    int d;
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        d = dist[x][y];
        if (x == 0 || y == 0 || x == h - 1 || y == w - 1) return dist[x][y];
        for (int i = 0; i < 4; i++) {
            if (!isvalid(x, y, i)) continue;
            q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
            vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
            dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
        }
    }
    return 103000;
}

int main(void) {
    int t, x = -1, y = -1, r;
    scanf("%d %d %d", &t, &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", wall[i]);
        for (int j = 0; j < w; j++) {
            if (wall[i][j] == 'S') {
                x = i, y = j, wall[i][j] = '0';
            }
        }
    }
    if (x < 0) return 1;
    r = bfs(x, y);
    if (r > t) printf("NOT POSSIBLE");
    else printf("%d", r);
    return 0;
}