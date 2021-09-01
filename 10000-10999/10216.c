#include <stdio.h>

/*
���� : N(N <= 3000)���� ���� ���� ��, ���� ��� ������ ������ �� ������ ���Ѵ�.

�ذ� ��� : �� ���� ��� ���ؼ��� �� ���� �������� ���� �� ���� �߽� ���� �Ÿ����� ũ�ų� ���ƾ� �Ѵ�.
�̴� ��Ÿ��� ������ ���� ����� �� �ִ�. N�� �۱� ������ ��� �ֿ� ���� ���� ����غ��� �ȴ�.
���� ��� �ֵ鳢���� �������� �����ϰ� �÷������� �ϸ� ���� �ٸ� ������ ���� ���� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ������

��ó : Coder's High 2014 C��
*/

int pos[3200][3], ed[3200][3200], vis[3200];

int sqr(int a) {
    return a * a;
}

void dfs(int x) {
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if (!vis[ed[x][i]]) dfs(ed[x][i]);
    }
}

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &pos[i][0], &pos[i][1], &pos[i][2]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (sqr(pos[i][0] - pos[j][0]) + sqr(pos[i][1] - pos[j][1]) <= (sqr(pos[i][2] + pos[j][2]))) {
                    ed[i][++ed[i][0]] = j;
                    ed[j][++ed[j][0]] = i;
                }
            }
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            dfs(i);
            r++;
        }
        printf("%d\n", r);
        for (int i = 1; i <= n; i++) {
            ed[i][0] = 0;
            vis[i] = 0;
        }
    }
    return 0;
}