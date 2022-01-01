#include <stdio.h>
#include <stdlib.h>
#define INF 103000

/*
���� : N(N <= 100)�� ���� ���� �ƴ� ������� �־�����. �̶�, �� ���� �ƴ� ����鳢�� ȸ�Ǹ� �ϰ�, �� ȸ���� ��ǥ��
���� ģ�� �Ÿ��� ����� ����� �Ѵٰ� �� ��, ��ǥ�� ���� �� ��ȣ�� ����Ѵ�.

�ذ� ��� : �÷������� ���� ȸ�Ǹ� ���� ���� ����, �÷��̵�-������ ���� �� ģ�� ������ �Ÿ��� ���Ѵ�.
�׸��� �� ȸ�Ǹ��� ģ�� ���� �Ÿ��� ���� �� ������� �Ÿ��� ���� ����� ����� ã���� ��ǥ�� ã�� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, �÷��̵�-����

��ó : ���� 2004�� ��3/��3��
*/

int dist[128][128], vis[128], meet[128][128], rep[128];
int mcnt = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void dfs(int n, int x) {
    vis[x] = 1;
    meet[mcnt][++meet[mcnt][0]] = x;
    for (int i = 1; i <= n; i++) {
        if (dist[x][i] < INF && !vis[i]) dfs(n, i);
    }
}

int main(void) {
    int n, m, a, b, hi, best;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(n, i);
            mcnt++;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < mcnt; i++) {
        best = INF;
        for (int j = 1; j <= meet[i][0]; j++) {
            hi = -1;
            for (int k = 1; k <= meet[i][0]; k++) {
                if (dist[meet[i][j]][meet[i][k]] > hi) hi = dist[meet[i][j]][meet[i][k]];
            }
            if (hi < 0) return 1;
            if (hi < best) {
                best = hi;
                rep[i] = meet[i][j];
            }
        }
        if (rep[i] == 0) return 2;
    }
    qsort(rep, mcnt, sizeof(int), cmp1);
    printf("%d\n", mcnt);
    for (int i = 0; i < mcnt; i++) {
        printf("%d\n", rep[i]);
    }
    return 0;
}