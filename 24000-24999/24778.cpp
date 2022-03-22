#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : 3 * 3 ũ���� ĭ�鿡 0���� 3������ ���� ���� �ִ�. �� ĭ�� ������ ���� ��� ���� ������
1�� ����(3�� ��쿣 0���� ��ȭ)�Ѵٰ� �� ��, ��� ĭ�� ���� 0���� �ٲ� �� �ִ� �� ���ϰ�,
������ ��� ������ �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : �� ĭ���� ��� ���´� ���ƾ� 4^9 = 262144�����̹Ƿ� BFS�� �� �� �ִ�.
Ư�� 4�� 2�� �ŵ����� ���̹Ƿ� ��Ʈ����ŷ�� �̿��� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : VTH 2015 D��
*/

int vis[262144], dist[262144];
queue<int> q;
int panelmv[9][5] = { {0, 1, 2, 3, 6}, {0, 1, 2, 4, 7}, {0, 1, 2, 5, 8}, {0, 3, 4, 5, 6},
    {1, 3, 4, 5, 7}, {2, 3, 4, 5, 8}, {0, 3, 6, 7, 8}, {1, 4, 6, 7, 8}, {2, 5, 6, 7, 8} };

void bfs(int p) {
    int t;
    q.push(p);
    vis[p] = 1;
    while (q.size()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 9; i++) {
            t = p;
            for (int j = 0; j < 5; j++) {
                t -= ((p >> (panelmv[i][j] * 2)) & 3) << (panelmv[i][j] * 2);
                t += ((((p >> (panelmv[i][j] * 2)) & 3) + 1) & 3) << (panelmv[i][j] * 2);
            }
            if (vis[t]) continue;
            vis[t] = 1;
            dist[t] = dist[p] + 1;
            q.push(t);
        }
    }
}

int main(void) {
    int x, p = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &x);
        p += x << (i << 1);
    }
    bfs(p);
    if (vis[0] == 0) printf("-1");
    else printf("%d", dist[0]);
    return 0;
}