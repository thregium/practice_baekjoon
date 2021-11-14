#include <stdio.h>

/*
���� : N(N <= 500)���� ������ M���� �������� �̷���� �׷����� �־��� ��, �� �׷������� Ʈ���� �� �� �ִ��� ���Ѵ�.

�ذ� ��� : ��� �湮���� ���� �������� DFS�� �ϸ鼭 ����Ŭ�� ������ �ʴ� ���� ������ ���ϸ� �ȴ�.
����Ŭ�� ����� ���δ� ������ �湮���� ���� ���������� �̹� �湮�� ������ �ٽ� �湮�Ͽ����� ���η� �� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, DFS, Ʈ��

��ó : Rocky 2012 H��
*/

int ed[512][512], vis[512];

int dfs(int x, int l) {
    int r = 1;
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if (ed[x][i] == l) continue;
        if (vis[ed[x][i]]) r = 0;
        else r &= dfs(ed[x][i], x);
    }
    return r;
}

int main(void) {
    int n, m, a, b, cnt = 0;
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2012\\probH\\cases\\test2\\trees.in", "r", stdin);
    for (int tt = 1;; tt++) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            ed[a][++ed[a][0]] = b;
            ed[b][++ed[b][0]] = a;
        }

        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            cnt += dfs(i, 0);
        }
        printf("Case %d: ", tt);
        if (cnt == 0) printf("No trees.\n");
        else if (cnt == 1) printf("There is one tree.\n");
        else printf("A forest of %d trees.\n", cnt);


        for (int i = 1; i <= n; i++) {
            ed[i][0] = 0;
            vis[i] = 0;
        }
    }
    return 0;
}