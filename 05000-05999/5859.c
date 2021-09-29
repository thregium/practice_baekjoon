#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 1000)���� ����� �ְ�, ��� ������� ������ �ϰų� �������� �Ѵ�. �� ����� ���� M(M <= 10000)���� ������ �Ͽ���.
�� ������ x���� y�� ������ �ϴ��� �������� �ϴ��� ��� ���̴�. ���⼭ x�� y�� ���� �ٸ� ����̴�.
�̶�, ������ ���ʺ��� �Ͽ��� ��, ������ ����� �ϰ����� ���� ���� ������ �ִ��� ���Ѵ�.

�ذ� ��� : �Ű� ���� Ž���� ���� ���� ������ �Űܰ��� ���� ���ϸ� log(M) * (Ž�� �ð�) ���� ���� ���� �� �ִ�.
������ ����� �ϰ����� �������� �̺� �׷��� �Ǻ��� ������ ����� �̿��� Ǯ �� �ִ�.
�� �������� ����� �������̶�� �� ����� ������ ������ ���ΰ� �ٸ� ���̰�, �����̶�� ���ΰ� ���� ���̴�.

����, ��� ����鿡 ���� Ȯ���غ��鼭 ���� Ȯ������ ���� ����� ������ �� ����� ������ �Ѵٰ� �����ϰ�
���� �ݴ��� ������ ����� ������ ��/������ �ٲ㼭 �̵��Ѵ�. �̶�, ����� ����Ǵ� ��찡 �������� Ȯ���ϸ� �ȴ�.
���踦 ������ ������ �� ���� ���谡 �����Ǹ� �ݴ����� ���赵 �����ȴ�. �׷��⿡ �� ���� ����� �ݴ��� �������� ���� �� �ִ�.
�̸� �̿��� �ش��ϴ� ����� �ݴ밡 �̹� �������� �ִٸ� �ٷ� ������� �� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, �Ķ��Ʈ��

��ó : USACO 2013J B3��
*/

int que[10240][3], ed[1024][1024], color[1024];

int dfs(int n, int x, int c) {
    int r = 0;
    color[x] = c;
    for (int i = 1; i <= n; i++) {
        if (ed[x][i] < 0) {
            if (color[i] == c) return 1; //���� �ݴ뿩�� �ϴµ� ���� ���
            if (color[i] == 0) r |= dfs(n, i, (c == 1) ? 2 : 1);
        }
        else if (ed[x][i] > 0) {
            if (color[i] && color[i] != c) return 1; //���� ���ƾ� �ϴµ� �ݴ��� ���
            if (color[i] == 0) r |= dfs(n, i, c);
        }
    }
    return r; //����� ������ 1, ������ 0
}

int getres(int n, int m) {
    int x, y, tl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) ed[i][j] = 0;
    }
    for (int i = 0; i < m; i++) {
        x = que[i][0], y = que[i][1], tl = que[i][2];
        if (ed[x][y]) {
            if (tl != ed[x][y]) return 0; //�̹� �ִ� ������ �ݴ��� ����̴�.
            else continue;
        }
        else {
            if (tl < 0) {
                ed[x][y] = -1;
                ed[y][x] = -1;
            }
            else if (tl > 0) {
                ed[x][y] = 1;
                ed[y][x] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) color[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i]) continue;
        if (dfs(n, i, 1)) return 0; //����� ���� ���
    }
    return 1; //������ ���
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("truth.in", "r");
        fo = fopen("truth.out", "w");
    }

    int n, m, x, y, lo, hi, mid;
    char tl;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &que[i][0], &que[i][1], &tl);
        if (tl == 'L') que[i][2] = -1;
        else if (tl == 'T') que[i][2] = 1;
        else return 1;
    }

    lo = 0, hi = m; //�Ķ��Ʈ���� �̿��� ���� ã�´�.
    while (lo < hi) {
        mid = ((lo + hi + 1) >> 1);
        if (getres(n, mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%d", lo);
    return 0;
}