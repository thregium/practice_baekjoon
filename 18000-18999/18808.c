#include <stdio.h>

/*
문제 : N * M(N, M <= 40) 크기의 종이에 K(K <= 100)개의 R_i * C_i(R_i, C_i <= 10) 크기의
종이들을 순서대로 가능한 만큼 붙이려고 한다. 우선 돌리지 않고 왼쪽 위부터 차례로
겹치지 않고 붙일 수 있는 칸들을 찾아보며, 90도씩 시계방향으로 돌려가며 이를 반복한다.
붙일 수 없다면 다음 스티커를 본다. 최종적으로 스티커가 붙은 칸의 개수를 구한다.

해결 방법 : 제한이 크지 않은 편이므로 직접 브루트 포스를 통해 스티커가 붙을 위치를 찾고,
있다면 스티커를 붙이고 없다면 다음 스티커를 보는 식으로 반복하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 브루트 포스

출처 : BaaaaaaaaaaarkingDog
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