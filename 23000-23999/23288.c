#include <stdio.h>

/*
���� : N * N(2 <= N <= 20) ũ���� ���� �ڿ���(<= 10)���� ���� �ִ�. �׸��� (1, 1) ������
1�� ��, 3�� �����ʿ� ������ �ֻ����� ���� �ִ�. �̶�, �ֻ����� ���� ���� ������ �� ��� ������ ���Ѵ�.
1. �ֻ����� �̵� ���⿡ �°� ������. �ʱ� �̵� ������ �������̴�. ������ �� ���ٸ� �ݴ�� ������.
2. �ֻ����� ���� ���� ���� ���� ��Ҹ� �̷�� ���� ������ ���� ������ �߰��Ѵ�.
3. �ֻ����� �ظ��� ���� ������ ũ�ٸ� �ð��������, �۴ٸ� �ݽð�������� 90�� �̵� ������ �ٲ۴�.

�ذ� ��� : �� ������ �ùķ��̼��Ѵ�. �ֻ����� ���� �ϵ��ڵ��� �ϴ� ���� ����.

�ֿ� �˰��� : ����, �ùķ��̼�, �÷�����

��ó : �Ｚ SW ���� �׽�Ʈ
*/

int a[32][32], vis[32][32], score[32][32];
const int dice[7][4] = { {0, 0, 0, 0}, {2, 4, 5, 3}, {1, 3, 6, 4}, {1, 5, 6, 2},
    {1, 2, 6, 5}, {1, 4, 6, 3}, {2, 3, 5, 4} };
const int rdice[7][7] = { {-1, -1, -1, -1, -1, -1, -1}, {-1, -1, 0, 3, 1, 2, -1}, {-1, 0, -1, 1, 3, -1, 2},
{-1, 0, 3, -1, -1, 1, 2}, {-1, 0, 1, -1, -1, 3, 2}, {-1, 0, -1, 3, 1, -1, 2}, {-1, -1, 0, 1, 3, 2, -1} };
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y, int sc) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || a[x][y] != sc) return 0;
    return 1;
}

int dfs(int x, int y, int sc) {
    int r = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1], sc)) r += dfs(x + dxy[i][0], y + dxy[i][1], sc);
    }
    return r;
}

int main(void) {
    int k, x = 0, y = 0, dn = 6, rt = 3, mdir = 0, res = 0, ndn, nrt;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < m; jj++) vis[ii][jj] = 0;
            }
            score[i][j] = a[i][j] * dfs(i, j, a[i][j]);
        }
    }

    for (int i = 0; i < k; i++) {
        x += dxy[mdir][0];
        y += dxy[mdir][1];
        if (x < 0 || y < 0 || x >= n || y >= m) {
            mdir = ((mdir + 2) & 3);
            for (int j = 0; j < 2; j++) {
                x += dxy[mdir][0];
                y += dxy[mdir][1];
            }
        }
        ndn = dice[dn][(rdice[dn][rt] + mdir) & 3];
        nrt = dice[ndn][(rdice[ndn][dn] - mdir + 6) & 3];
        dn = ndn;
        rt = nrt;
        res += score[x][y];

        if (dn > a[x][y]) mdir = ((mdir + 1) & 3);
        else if (dn < a[x][y]) mdir = ((mdir + 3) & 3);
    }
    printf("%d", res);
    return 0;
}