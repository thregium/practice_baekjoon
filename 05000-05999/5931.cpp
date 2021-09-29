#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N * M(N, M <= 50) ũ���� ���ڿ� '*'�� �̷���� �� ����� �ִ�. �� ����� �ϳ��� ��ġ�� ���� �ʿ���
'*'�� ������ ���Ѵ�.  �� ����� ��� '*'���� �����¿�� �̵��� ������ '*'�� �����̴�.

�ذ� ��� : ���� �÷������� ���� �� ����� ��ġ�� ã�´�. �� ����, ù ��° ����� �ִ� '*'�� ��ġ�� ���� ť�� �ְ�
BFS�� ������. ���� �� ��° ����� �ִ� '*' ��� ���� ù ��° ����� ���� ���� ã��, �װ������� �Ÿ����� 1�� ����
�� ��� ������ �Ÿ��� �ǰ�, �� ��η� '*'�� �߰��ϸ� �� ����� �ǹǷ� �̰��� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : USACO 2011N B4��
*/

char pattern[64][64];
int vis[64][64], dist[64][64], spot[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, pn = 1;
queue<pair<int, int>> q;

int isvalid(int x, int y, int c) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if ((!c && vis[x][y]) || (c && spot[x][y]) || (c && pattern[x][y] == '.')) return 0;
    return 1;
}

void dfs(int x, int y) {
    spot[x][y] = pn;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], 1)) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

void bfs(void) {
    int x, y;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1], 0)) {
                q.push(pair<int, int>(x + dxy[i][0], y + dxy[i][1]));
                vis[x + dxy[i][0]][y + dxy[i][1]] = 1;
                dist[x + dxy[i][0]][y + dxy[i][1]] = dist[x][y] + 1;
            }
        }
    }
}

int main(void) {
    int res = INF;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", pattern[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pattern[i][j] == 'X' && !spot[i][j]) {
                dfs(i, j);
                pn++;
            }
            if (spot[i][j] == 1) {
                q.push(pair<int, int>(i, j));
                vis[i][j] = 1;
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spot[i][j] == 2 && dist[i][j] < res) res = dist[i][j];
        }
    }
    if (res == INF) return 1;
    printf("%d", res - 1);
    return 0;
}