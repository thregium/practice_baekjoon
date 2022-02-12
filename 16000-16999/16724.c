#include <stdio.h>

/*
���� : N * M(N, M <= 1000) ũ���� ���ڿ��� �� ĭ���� �̵��ϴ� ������ �־��� ��,
� ĭ���� ����ص� ������ ĭ �� �ϳ��� ������ �� �ֵ��� ĭ���� �����ϱ� ����
���� �ϴ� ĭ�� �ּ� ������ ���Ѵ�.

�ذ� ��� : ���Ͽ�-���ε带 ���� �� ĭ���� �̵��ϴ� ĭ���� �ϳ��� ���� ��ҷ� ���� ����,
���� ����� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���Ͽ� ���ε�

��ó : �Ѿ��E 2018Z F��
*/

char s[1024][1024], vis[1048576];
int g[1048576];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'U') uni((i << 10) + j, ((i - 1) << 10) + j);
            else if (s[i][j] == 'R') uni((i << 10) + j, (i << 10) + j + 1);
            else if (s[i][j] == 'D') uni((i << 10) + j, ((i + 1) << 10) + j);
            else if (s[i][j] == 'L') uni((i << 10) + j, (i << 10) + j - 1);
            else return 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[find((i << 10) + j)]) {
                vis[find((i << 10) + j)] = 1;
                r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}