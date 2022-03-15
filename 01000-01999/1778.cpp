#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 50000)���� ������ M���� �������� �̷���� �׷����� �־��� ��,
�� �׷����� ���� ����� ������ ���Ѵ�.

�ذ� ��� : �� �湮���� ���� �������� �÷������� �ϰ�, �� Ƚ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : Alberta 2003 C��
*/

int vis[65536];
vector<int> ed[65536];

void dfs(int x, int c) {
    vis[x] = c;
    for (int i : ed[x]) {
        if (!vis[i]) dfs(i, c);
    }
}

int main(void) {
    int n, m, x, y, r;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            dfs(i, ++r);
        }
        printf("Case %d: %d\n", tt, r);
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            ed[i].clear();
        }
    }
    return 0;
}