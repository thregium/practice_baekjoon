#include <stdio.h>

/*
���� : R * C(R, C <= 250) ũ���� ���ڿ��� ��Ÿ���� ��, ������ ��ġ�� �־�����. �� ��Ÿ���� �ѷ����� ���� �ȿ���
��, ����� �����¿�� ������ �� �ִ�. ���� ������ ���� ���� ������ ������ ���ٸ� ���� ��� ���븦 �ѾƳ���,
�� �ܿ��� ���밡 ��� ���� �Դ´ٸ� �����ִ� ��� ������ ���� ���Ѵ�. ��Ÿ�� �ۿ��� ��� ���밡 ����.

�ذ� ��� : �÷������� ���� ��Ÿ�� �������� �ȿ� �ִ� ��� ������ ���� ���Ѵ�. �� �� �� ���� �ʸ� �����(���� ��� ����),
������ ���� ���� ����� ���ϴ� ���� �ݺ��Ѵ�. �׸��� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : CHCI 2005RS 3��
*/

char f[256][256];
int vis[256][256];
int r, c;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (f[x][y] == '#' || vis[x][y]) return 0;
    return 1;
}

long long dfs(int x, int y, long long sw) {
    vis[x][y] = 1;
    if (f[x][y] == 'k') sw += 1000000;
    else if (f[x][y] == 'v') sw++;
    if (isvalid(x, y + 1)) sw += dfs(x, y + 1, 0);
    if (isvalid(x + 1, y)) sw += dfs(x + 1, y, 0);
    if (isvalid(x, y - 1)) sw += dfs(x, y - 1, 0);
    if (isvalid(x - 1, y)) sw += dfs(x - 1, y, 0);
    return sw;
}

int main(void) {
    int s = 0, w = 0;
    long long sw;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", f[i]);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!isvalid(i, j)) continue;
            sw = dfs(i, j, 0);
            if (sw / 1000000 > sw % 1000000) s += sw / 1000000;
            else w += sw % 1000000;
        }
    }
    printf("%d %d", s, w);
    return 0;
}