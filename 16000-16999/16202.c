#include <stdio.h>

/*
���� : N(N <= 1000)���� ������ M(M <= 10000)���� �������� �̷���� �׷������� K(K <= 100)�� MST�� �̷�� ������ ���̸� ���Ѵ�.
��, �Ź� ���� ����, MST�� �̷�� ���� ��� ���� ���̰� ���� ������ �����.
���� �� ���� ��� 0�� ����Ѵ�.

�ذ� ��� : �Ź� MST�� ����ϸ� �ȴ�. ����, ���� ���̰� ���� ������ �׻� MST�� ���� �� �ִ� ��� MST�� ���Ƿ�
���� ª�� i - 1���� ������ �����ϰ� �����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, MST, �ùķ��̼�
*/

int ed[10240][3], g[1024];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, k, c, r;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &ed[i][1], &ed[i][2]);
        ed[i][0] = i + 1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 1024; j++) g[j] = 0;
        c = 0, r = 0;
        for (int j = i; j < m; j++) {
            if (find(ed[j][1]) == find(ed[j][2])) continue;
            uni(ed[j][1], ed[j][2]);
            r += ed[j][0];
            c++;
        }
        if (c == n - 1) printf("%d ", r);
        else printf("0 ");
    }
    return 0;
}