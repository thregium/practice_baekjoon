#include <stdio.h>

/*
���� : R * C(R, C <= 50) ũ���� �ڿ����� ���� ���ڿ��� �����¿�밢������ ������ 2ĭ �̻��� ���� �� ��� ���� ū ���� ���Ѵ�.

�ذ� ��� : ��� ĭ���� ���� 8ĭ�� ���캸�� ���� ���� ���� ĭ�� �ִ� ĭ�� ���� ��� ���� ū ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : USACO 2009M B2��
*/

int depth[64][64];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int main(void) {
    int r, c, t, best = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &depth[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            t = 0;
            for (int d = 0; d < 8; d++) {
                if (i + dxy[d][0] < 0 || i + dxy[d][0] >= r || j + dxy[d][1] < 0 || j + dxy[d][1] >= c) continue;
                if (depth[i + dxy[d][0]][j + dxy[d][1]] == depth[i][j]) t = 1;
            }
            if (t && depth[i][j] > best) best = depth[i][j];
        }
    }
    printf("%d", best);
    return 0;
}