#include <stdio.h>

/*
���� : 1000 ������ ��ȣ�� ���� �� ������ ���� ���°� �־�����. �־��� ������ ���� ����� �����ε�,
�� ��带 �����ؼ� ���� ��Ұ� �������� ������ ��츦 ��ȣ ������ ã�� �� ���� �������� ���Ѵ�.

�ذ� ��� : ��� ��ȣ�� ���� ��ȣ ������ ������ ����� �ش� ��带 ������ ä�� �÷������� ����
���� ����� ������ ã�´�. ���� 2�� �̻��� ��� �ش��ϴ� ���� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���Ʈ ����, �÷�����

��ó : GNY 2000 H��
*/

int node[1024], vis[1024], edge[1024][1024];

void dfs(int x, int spf) {
    vis[x] = 1;
    for (int i = 1; i <= edge[x][0]; i++) {
        if (vis[edge[x][i]] || edge[x][i] == spf) continue;
        dfs(edge[x][i], spf);
    }
}

int main(void) {
    int a, b, subs, cnt;
    for (int tt = 1;; tt++) {
        cnt = 0;
        while (1) {
            scanf("%d", &a);
            if (a == 0) break;
            scanf("%d", &b);
            node[a] = 1;
            node[b] = 1;
            edge[a][++edge[a][0]] = b;
            edge[b][++edge[b][0]] = a;
            cnt++;
        }
        if (cnt == 0) break;

        printf("Network #%d\n", tt);
        cnt = 0;
        for (int i = 1; i <= 1000; i++) {
            if (!node[i]) continue;
            subs = 0;
            for (int j = 1; j <= 1000; j++) {
                if (node[j] && !vis[j] && j != i) {
                    dfs(j, i);
                    subs++;
                }
            }
            if (subs > 1) {
                printf("  SPF node %d leaves %d subnets\n", i, subs);
                cnt++;
            }
            for (int j = 1; j <= 1000; j++) vis[j] = 0;
        }
        if (cnt == 0) printf("  No SPF nodes\n");
        printf("\n");
        for (int i = 1; i <= 1000; i++) {
            node[i] = 0;
            edge[i][0] = 0;
        }
    }
    return 0;
}