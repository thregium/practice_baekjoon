#include <stdio.h>

/*
���� : P(P <= 100)���� ������ C(C <= 5000)���� �������� �̷���� ����� ���� �׷����� �־��� ��,
���� �ϳ��� �����Ͽ� ���� �׷����� �ƴϰ� ���� �� �ִ� �� ���Ѵ�.

�ذ� ��� : P�� C�� ���� �����Ƿ� ��� ������ �ϳ��� ����鼭 ����׷����� �� ���θ� Ȯ���ؼ�
�ϳ��� �ƴ� ���� �ִ� �� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ���Ʈ ����

��ó : VTH 2014 I��
*/

int ed[128][128], edn[5120][2], vis[128];

void dfs(int x, int a, int b) {
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if ((x == a && ed[x][i] == b) || (x == b && ed[x][i] == a)) continue;
        if (vis[ed[x][i]]) continue;
        dfs(ed[x][i], a, b);
    }
}

int main(void) {
    int p, c, r;
    //freopen("E:\\PS\\High School\\VTH\\2014\\birthday.in", "r", stdin);
    //freopen("E:\\PS\\High School\\VTH\\2014\\birthday_t.out", "w", stdout);
    while (1) {
        scanf("%d %d", &p, &c);
        if (p == 0) break;
        for (int i = 0; i < c; i++) {
            scanf("%d %d", &edn[i][0], &edn[i][1]);
            ed[edn[i][0]][++ed[edn[i][0]][0]] = edn[i][1];
            ed[edn[i][1]][++ed[edn[i][1]][0]] = edn[i][0];
        }
        r = 1;
        for (int i = 0; i < c; i++) {
            dfs(0, edn[i][0], edn[i][1]);
            for (int j = 0; j < p; j++) {
                if (!vis[j]) r = 0;
                vis[j] = 0;
            }
            if (!r) break;
        }
        printf("%s\n", r ? "No" : "Yes");
        for (int i = 0; i < p; i++) ed[i][0] = 0;
    }
    return 0;
}
