#include <stdio.h>

/*
���� : H * W(H, W <= 100) ũ���� ������ N���� ������ ���̰� �����Ǿ���. �� �����¿�� ������
������ ���� ���� ���� 1 ���Ϸ� ���� �� �ִ� �� Ȯ���ϰ�, �׷��� ��� ��ü ������ ���� ����
���� ���� ���� ���� ���� ���Ѵ�.

�ذ� ��� : ���� �������� ���ʷ� Ȯ���ϸ鼭 �ֺ� �������� ���̸� 1�� ����������.
�� �������� ������ ������ �ֺ��� ���̰� Ȯ������ ���� �������� ���̸� 1�� �������� �� �ִ�.
�̸� �ݺ��� ���� ������ ���� ���� ���� ���� 2 �̻��� ������ �ִٸ� ���� �� ���� ���̰�,
�� �ܿ��� �̷��� �ϸ� ��ü ���� ���� �ּҰ� �ǹǷ� ���� ���� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : Yokohama 2019 B��
*/

int ht[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y]) return -1;
    return 1;
}

int main(void) {
    int n, x, y, t, res = 0, va = 1;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &t);
        x--, y--;
        ht[x][y] = t;
        vis[x][y] = 1;
    }
    for (int i = 100; i >= -300; i--) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (!vis[j][k] || ht[j][k] != i) continue;
                for (int d = 0; d < 4; d++) {
                    if (isvalid(j + dxy[d][0], k + dxy[d][1]) <= 0) continue;
                    ht[j + dxy[d][0]][k + dxy[d][1]] = i - 1;
                    vis[j + dxy[d][0]][k + dxy[d][1]] = 1;
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int d = 0; d < 4; d++) {
                if (!isvalid(i + dxy[d][0], j + dxy[d][1])) continue;
                if (abs(ht[i][j] - ht[i + dxy[d][0]][j + dxy[d][1]]) > 1) va = 0;
            }
            res += ht[i][j];
        }
    }
    if (va) printf("%d\n", res);
    else printf("No\n");
    return 0;
}