#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� �׷����� �ִ�. �� �׷������� Q���� �������� ������ ����� 1��°����
��ó Kĭ, 2��°���� ������ �ִ� ������ ��ó 2 * Kĭ... i��°���� ��ó i * Kĭ���� ���������ٰ� �Ѵ�.
�� ������ ������ �����ϴ� ���� ���Ѵ�.

�ذ� ��� : ���� BFS�� ������ �ִ� �������� �� ���������� �Ÿ��� ���� ���� N ������ �Ÿ��� ���� �ش� ������
������ �����ϴ� �ð��� ���ϰ� �� ������ �Ÿ��� ���� �����ϴ� �ð��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : COCI 19/20#6 2��
*/

int vis[103000], dist[103000], conv[103000];
vector<int> ed[103000];
queue<int> qe;

void bfs(void) {
    int x;
    while (qe.size()) {
        x = qe.front();
        qe.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            dist[i] = dist[x] + 1;
            qe.push(i);
        }
    }
}

int main(void) {
    int n, m, q, k, a, b;
    scanf("%d %d %d %d", &n, &m, &q, &k);
    for (int i = 0; i < q; i++) {
        scanf("%d", &a);
        qe.push(a);
        vis[a] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    bfs();

    for (int i = 1, x = 1; i <= n;) {
        for (int j = 0; j < x * k && i <= n; j++) {
            conv[i++] = x;
        }
        x++;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", conv[dist[i]]);
    }
    return 0;
}