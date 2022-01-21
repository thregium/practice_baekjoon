#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 15)���� ��Ʈ�� �̷���� ���� 2�� �־�����. �̶�, ù ��° ������ �� ��° ��
�Ǵ� ���� �ݴ� ���� ����� ���� ������ ��Ʈ�� ������ �ٲٴ� ������ �ּ� �� ȸ �ʿ��� �� ���Ѵ�.
�� �� �� ���� ���� �� ������ ����ȴ�.

�ذ� ��� : ��Ʈ����ŷ�� ���� ������ ���� �ٲ� ��, ������ ��Ʈ�� ������ ���� �ٲٸ鼭
BFS�� �����Ѵ�. ��Ʈ ������ ������ Ȱ���Ѵ�. BFS�� ������ �� �� �ּ� �ϳ��� �湮�� �Ǿ� ���� ���̴�.
�湮�� �� �� �� �� �Ÿ��� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ��Ʈ����ŷ

��ó : Tokyo 2014 A��
*/

int vis[32768], dist[32768], bit[16];
queue<int> q;

int small(int a, int b) {
    return a < b ? a : b;
}

void bfs(int n, int x) {
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 1; i < n; i++) {
            if (((x >> i) & 1) ^ ((x >> (i - 1)) & 1)) {
                if (!vis[x ^ (1 << i) ^ (1 << (i - 1))]) {
                    vis[x ^ (1 << i) ^ (1 << (i - 1))] = 1;
                    dist[x ^ (1 << i) ^ (1 << (i - 1))] = dist[x] + 1;
                    q.push(x ^ (1 << i) ^ (1 << (i - 1)));
                }
            }
        }
    }
}

int main(void) {
    int n, m, x = 0, y, z = 0, p = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bit[i]);
        x += (bit[i] << i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &y);
        for (int j = 0; j < y; j++) z += ((i & 1) << (p++));
    }
    bfs(n, x);
    if (!vis[z] && !vis[(1 << n) - z - 1]) return 1;
    printf("%d\n", small(vis[z] ? dist[z] : INF,
        vis[(1 << n) - z - 1] ? dist[(1 << n) - z - 1] : INF));
    return 0;
}