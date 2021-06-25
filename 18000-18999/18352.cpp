#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : ���� N(N <= 300000)���� ����ġ ���� ���� �׷������� ���� X���� ������� �� �ִܰŸ��� K�� ������ ��� ã�´�.

�ذ� ��� : X���� BFS�� �ϸ� �Ÿ� �迭�� ���� ����� �� ���� BFS�� ������ �Ÿ� �迭�� ���캸�� �Ÿ��� K�� ������ ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS
*/

int vis[327680], dist[327680];
vector<int> ed[327680];
queue<int> q;

void bfs(int x) {
    q.push(x);
    vis[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            dist[i] = dist[x] + 1;
            q.push(i);
        }
    }
}

int main(void) {
    int n, m, k, x, a, b, c = 0;
    scanf("%d %d %d %d", &n, &m, &k, &x);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
    }

    bfs(x);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            printf("%d\n", i);
            c++;
        }
    }
    if (c == 0) printf("-1");
    return 0;
}