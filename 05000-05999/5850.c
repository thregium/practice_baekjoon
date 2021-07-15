#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 100 * 100 ��ǥ ���� ¤ ���̰� �����¿�� ����� ���·� �־��� ��, ¤ ������ �ѷ��� ���Ѵ�.
��, ¤ ������ ���ʿ� �ִ� ������ �ѷ��� ���Ե��� �ʴ´�.

�ذ� ��� : ¤�� �ٱ��� �κк��� �÷������� �ϸ� ���� ������ �����ϸ� �ѷ��� ���� �� �ִ�.
�÷������� �� �����ٰ� ¤�� �ִ� �κ��� �߰��ϸ� �ѷ� ���� 1 �ø��� �÷������� ������ ���� �ѷ� ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : USACO 2013F B3��
*/

int hay[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int perm = 0;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 128 || y >= 128) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (!isvalid(x + dxy[i][0], y + dxy[i][1])) continue;
        if (hay[x + dxy[i][0]][y + dxy[i][1]]) {
            perm++;
            continue;
        }
        else dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("perimeter.in", "r");
        fo = fopen("perimeter.out", "w");
    }
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        hay[x][y] = 1;
    }
    dfs(0, 0);
    printf("%d", perm);
    return 0;
}