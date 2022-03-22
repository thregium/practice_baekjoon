#include <stdio.h>

/*
���� : H * W(H, W <= 50) ũ���� ���� ��ֹ�('R', 'W', 'T')���� �ִ�. ��ֹ��� ���� ���� ū
���簢�� ������ �� ���̸� ���Ѵ�.

�ذ� ��� : ���Ʈ ������ ��� ������ ���캸�� ���� ���� ���� ����ȭ�ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ���� ��

��ó : GCJ 2011AQ C1��
*/

char land[64][64];
int psum[64][64];

int getsum(int x1, int y1, int x2, int y2) {
    return psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1];
}

int isobst(char c) {
    if (c == 'R' || c == 'W' || c == 'T') return 1;
    else return 0;
}

int main(void) {
    int t, w, h, best;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &w, &h);
        for (int i = 1; i <= h; i++) {
            scanf("%s", land[i] + 1);
            for (int j = 1; j <= w; j++) {
                psum[i][j] = psum[i][j - 1] + isobst(land[i][j]);
            }
        }
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) psum[j][i] += psum[j - 1][i];
        }
        best = 0;
        for (int x = 1; x <= h; x++) {
            for (int y = 1; y <= w; y++) {
                for (int xx = x; xx <= h; xx++) {
                    for (int yy = y; yy <= w; yy++) {
                        if (getsum(x, y, xx, yy) == 0) {
                            if ((xx - x + 1) * (yy - y + 1) > best) best = (xx - x + 1) * (yy - y + 1);
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", tt, best);
    }
    return 0;
}