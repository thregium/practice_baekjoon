#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : ��� ��ٸ� ���ӿ��� �� ��, ��ٸ��� ��ġ���� �־��� ��, 1���� ����� 100�� �����ϱ� ���� �ʿ��� �ֻ��� ���� Ƚ���� ���Ѵ�.

�ذ� ��� : �־��� ������ �� ĭ�� �������� �� �̵��ϴ� ��ġ�� �̸� �����صд�. �� �������δ� �� �ֻ��� ������
�̵��ϴ� ĭ�� �������� ���� �� ĭ�� �������� �� ���� BFS�� ���� 100�� �����ϴ� ���� ���ϸ� �ȴ�.
100�� �����ϸ� �ٷ� ���α׷��� �����ϵ��� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS
*/

int nxt[128], dist[128], vis[128];
queue<int> q;

int main(void) {
    int n, m, x, y;
    for (int i = 1; i <= 100; i++) nxt[i] = i;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++) {
        scanf("%d %d", &x, &y);
        nxt[x] = y;
    }
    q.push(1);
    vis[1] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            if (x + i == 100) {
                printf("%d", dist[x] + 1);
                return 0;
            }
            if (vis[nxt[x + i]]) continue;
            q.push(nxt[x + i]);
            vis[nxt[x + i]] = 1;
            dist[nxt[x + i]] = dist[x] + 1;
        }
    }
    return 0;
}