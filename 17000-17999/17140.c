#include <stdio.h>
#include <stdlib.h>

int mat[128][128], hsz[128], vsz[128], cnt[128], nm[128]; //mat : 행렬, hsz : 행 길이, vsz : 열 길이, cnt : 행 또는 열의 숫자별 갯수, nm : 임시 배열
int w = 3, h = 3;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int ac = *((int*)a + 1);
    int bc = *((int*)b + 1);
    return ac > bc ? 1 : ac < bc ? -1 : ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int r, c, k, t, nl;
    scanf("%d %d %d", &r, &c, &k);
    r--;
    c--;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
        hsz[i] = 3;
        vsz[i] = 3;
    }
    for (t = 0; t <= 100; t++) {
        if (mat[r][c] == k) {
            break;
        }
        if (h >= w) {
            for (int i = 0; i < h; i++) {
                hsz[i] = 0;
                for (int j = 0; j < w; j++) {
                    cnt[mat[i][j]]++;
                    if (mat[i][j]) hsz[i]++;
                    mat[i][j] = 0;
                }
                nl = 0;
                for (int j = 1; hsz[i]; j++) {
                    if (cnt[j]) {
                        if (nl < 100) {
                            mat[i][nl++] = j;
                            mat[i][nl++] = cnt[j];
                        }
                        hsz[i] -= cnt[j];
                        cnt[j] = 0;
                    }
                }
                hsz[i] = nl;
                qsort(mat[i], hsz[i] >> 1, sizeof(int) * 2, cmp1);
            }
            w = 0;
            for (int i = 0; i < h; i++) {
                if (hsz[i] > w) w = hsz[i];
            }
            for (int i = 0; i < w; i++) {
                vsz[i] = h;
            }
        }
        else {
            for (int i = 0; i < w; i++) {
                vsz[i] = 0;
                for (int j = 0; j < h; j++) {
                    cnt[mat[j][i]]++;
                    if (mat[j][i]) vsz[i]++;
                    mat[j][i] = 0;
                }
                nl = 0;
                for (int j = 1; vsz[i]; j++) {
                    if (cnt[j]) {
                        if (nl < 100) {
                            nm[nl++] = j;
                            nm[nl++] = cnt[j];
                        }
                        vsz[i] -= cnt[j];
                        cnt[j] = 0;
                    }
                }
                vsz[i] = nl;
                qsort(nm, vsz[i] >> 1, sizeof(int) * 2, cmp1);
                for (int j = 0; j < vsz[i]; j++) {
                    mat[j][i] = nm[j];
                    nm[j] = 0;
                }
            }
            h = 0;
            for (int i = 0; i < w; i++) {
                if (vsz[i] > h) h = vsz[i];
            }
            for (int i = 0; i < h; i++) {
                hsz[i] = w;
            }
        }
    }
    if (t > 100) printf("%d", -1);
    else printf("%d", t);
    return 0;
}