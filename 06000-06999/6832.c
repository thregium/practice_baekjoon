#include <stdio.h>

/*
���� : N(N <= 10)���� ��ǥ�󿡼� �������� ������, �׸��� �׵� ������ ��ΰ� ���� �־��� ��,
�־��� ��ε��� �̿��Ͽ� �������� ���� �������� ���Ѵ�.

�ذ� ��� : �� �����鿡 ��ȣ�� �ű� ���� ������ ���� ������ ��� �� ��ȣ�� �ΰ�,
���� ���� �����̶�� ���ο� ��ȣ�� �Ҵ��Ѵ�. �� ���� ���ΰ��� ������踦 �ľ��ϰ� �÷������� �ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, �÷�����

��ó : GNY 2000 G��
*/

int nodes[1024][16], edges[1024][1024], vis[1024];

int dfs(int x, int r) {
    if (x == 1) r = 1;
    vis[x] = 1;
    for (int i = 1; i <= edges[x][0]; i++) {
        if (!vis[edges[x][i]]) r |= dfs(edges[x][i], r);
    }
    return r;
}

int main(void) {
    int n, sz, a, st, ed, tmp, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &nodes[0][i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &nodes[1][i]);
        }
        sz = 2;
        while (1) {
            st = sz;
            for (int i = 0; i < n; i++) {
                scanf("%d", &nodes[sz][i]);
                if (nodes[sz][i] < 0) break;
            }
            if (nodes[sz][0] < 0) break;
            for (int i = 0; i < sz; i++) {
                tmp = 1;
                for (int j = 0; j < n; j++) {
                    if (nodes[i][0] != nodes[sz][0]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp) {
                    st = i;
                    break;
                }
            }
            if (st == sz) sz++;

            ed = sz;
            for (int i = 0; i < n; i++) {
                scanf("%d", &nodes[sz][i]);
                if (nodes[sz][i] < 0) break;
            }
            if (nodes[sz][0] < 0) break;
            for (int i = 0; i < sz; i++) {
                tmp = 1;
                for (int j = 0; j < n; j++) {
                    if (nodes[i][0] != nodes[sz][0]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp) {
                    ed = i;
                    break;
                }
            }
            if (ed == sz) sz++;

            edges[st][++edges[st][0]] = ed;
        }

        printf("Maze #%d %s be travelled\n", tt, dfs(0, 0) ? "can" : "cannot");
        for (int i = 0; i < sz; i++) {
            edges[i][0] = 0;
            vis[i] = 0;
        }
    }
    return 0;
}