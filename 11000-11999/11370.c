#include <stdio.h>

/*
���� : H * W ũ���� �����ǿ� 'T'�� 'S'���� ���� ��, 'S'�� �����¿�� ������������ ������ 'T'���� 'S'�� �ٲپ� ����Ѵ�.

�ذ� ��� : 'S'�鸶�� �÷������� �����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : UVaH 2014 F��
*/

char wood[1024][1024], vis[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int w, h;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || (wood[x][y] != 'S' && wood[x][y] != 'T')) return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0) break;
        for (int i = 0; i < h; i++) {
            scanf("%s", wood[i]);
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (wood[i][j] == 'S') {
                    dfs(i, j);
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%c", wood[i][j] != '.' ? (vis[i][j] ? 'S' : 'T') : '.');
                vis[i][j] = 0;
                wood[i][j] = '\0';
            }
            printf("\n");
        }
    }
    return 0;
}