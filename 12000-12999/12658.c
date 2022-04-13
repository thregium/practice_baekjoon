#include <stdio.h>

/*
���� : H * W(H, W <= 100) ũ���� ���� �� ĭ�� ���� ������ ����(<= 10000)�� ���� �־�����. �� ĭ����
�ֺ� 4ĭ ��� ���� ��ġ���� ���� �� �� ���� ���� ��, ���� ���� ��� ��->��->��->���� �켱������
���� �帥��. ����, ���� �带 �� ���� ���� ���� ���̴� ���� �ȴ�. ���� ���̴� ���� 26�� ���϶��
���� ���̴� ���� �ٸ� ��ġ���� ���ĺ����� ����Ѵ�. ������ ��� ��� ���������� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �׷����� �����¿츦 ���캸�� ���ǿ� �°� ���� �帣�� ���� ã�´�.
�װ��� ã������ ����� ������ �����Ѵ�. �� �� ��ü ���� ���캸�鼭 ���� �湮���� ���� ������
�÷������� ���ش�. ���������� �÷������� �� ��°���� �� ĭ�� ���� ���̴� ��ġ ��ȣ�� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : GCJ 2009Q B2��
*/

int ht[128][128], ed[128][128][16], edc[128][128], vis[128][128];
int dxy[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int isvalid(int h, int w, int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    else if (vis[x][y]) return -1;
    return 1;
}

void dfs(int h, int w, int x, int y, int s) {
    vis[x][y] = s;
    for (int i = 0; i < edc[x][y]; i++) {
        if (isvalid(h, w, ed[x][y][i] >> 7, ed[x][y][i] & 127) > 0) {
            dfs(h, w, ed[x][y][i] >> 7, ed[x][y][i] & 127, s);
        }
    }
}

int main(void) {
    int t, h, w, dir, lwst, xx, yy, sinkcnt;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &ht[i][j]);
                edc[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dir = -1, lwst = ht[i][j];
                for (int k = 0; k < 4; k++) {
                    xx = i + dxy[k][0];
                    yy = j + dxy[k][1];
                    if (!isvalid(h, w, xx, yy)) continue;
                    if (ht[xx][yy] < lwst) {
                        lwst = ht[xx][yy];
                        dir = k;
                    }
                }
                if (dir < 0) continue;
                xx = i + dxy[dir][0];
                yy = j + dxy[dir][1];
                ed[i][j][edc[i][j]++] = xx * 128 + yy;
                ed[xx][yy][edc[xx][yy]++] = i * 128 + j;
            }
        }

        sinkcnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (vis[i][j]) continue;
                else dfs(h, w, i, j, ++sinkcnt);
            }
        }
        
        printf("Case #%d:\n", tt);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%c%c", vis[i][j] + 'a' - 1, j == w - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}