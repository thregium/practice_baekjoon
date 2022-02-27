#include <stdio.h>

/*
���� : N * M(N, M <= 40) ũ���� ���̿� K(K <= 100)���� R_i * C_i(R_i, C_i <= 10) ũ����
���̵��� ������� ������ ��ŭ ���̷��� �Ѵ�. �켱 ������ �ʰ� ���� ������ ���ʷ�
��ġ�� �ʰ� ���� �� �ִ� ĭ���� ã�ƺ���, 90���� �ð�������� �������� �̸� �ݺ��Ѵ�.
���� �� ���ٸ� ���� ��ƼĿ�� ����. ���������� ��ƼĿ�� ���� ĭ�� ������ ���Ѵ�.

�ذ� ��� : ������ ũ�� ���� ���̹Ƿ� ���� ���Ʈ ������ ���� ��ƼĿ�� ���� ��ġ�� ã��,
�ִٸ� ��ƼĿ�� ���̰� ���ٸ� ���� ��ƼĿ�� ���� ������ �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ���Ʈ ����

��ó : BaaaaaaaaaaarkingDog
*/

int notebook[64][64], sticker[128][4][16][16];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void rotr(int* a, int* t, int* h, int* w, int lsz) {
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) {
            t[i * lsz + j] = a[(*h - j - 1) * lsz + i];
        }
    }
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) a[i * lsz + j] = t[i * lsz + j];
    }
    swap(h, w);
}

int main(void) {
    int n, m, k, r, c, tmp1, tmp2, res = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &r, &c);
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                scanf("%d", &sticker[i][0][j][k]);
            }
        }
        tmp1 = 0;
        for (int j = 0; j < 4; j++) {
            if (j) rotr(sticker[i][j - 1], sticker[i][j], &r, &c, 16);
            for (int k = 0; k <= n - r; k++) {
                for (int l = 0; l <= m - c; l++) {
                    tmp2 = 1;
                    for (int x = 0; x < r; x++) {
                        for (int y = 0; y < c; y++) {
                            if (sticker[i][j][x][y] && notebook[k + x][l + y]) {
                                tmp2 = 0;
                                break;
                            }
                        }
                        if (!tmp2) break;
                    }
                    if (tmp2) {
                        for (int x = 0; x < r; x++) {
                            for (int y = 0; y < c; y++) notebook[k + x][l + y] |= sticker[i][j][x][y];
                        }
                        tmp1 = 1;
                        break;
                    }
                }
                if (tmp1) break;
            }
            if (tmp1) break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res += notebook[i][j];
        }
    }
    printf("%d", res);
    return 0;
}