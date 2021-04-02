#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char full[16][16], pc[16][16][16], chk[16][16]; //full : 전체 조각, pc : 각 조각, mc : (짝수 : x, 홀수 : y, 0 ~ 1 : 최소, 2 ~ 3 : 최대), chk : 임시 배열
int mc[16][4];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("bcs.in", "r");
        fo = fopen("bcs.out", "w");
    }
    int n, k, r;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", full[i]);
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", pc[i][j]);
        }
        mc[i][0] = 99;
        mc[i][1] = 99;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (pc[i][x][y] == '#') {
                    if (x < mc[i][0]) mc[i][0] = x;
                    if (y < mc[i][1]) mc[i][1] = y;
                    if (x > mc[i][2]) mc[i][2] = x;
                    if (y > mc[i][3]) mc[i][3] = y;
                }
            }
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {

            for (int a = -mc[i][0]; a < n - mc[i][2]; a++) {
                for (int b = -mc[i][1]; b < n - mc[i][3]; b++) {
                    for (int c = -mc[j][0]; c < n - mc[j][2]; c++) {
                        for (int d = -mc[j][1]; d < n - mc[j][3]; d++) {

                            r = 1;
                            for (int x = 0; x < n; x++) {
                                for (int y = 0; y < n; y++) {
                                    chk[x][y] = '.';
                                }
                            }
                            for (int x = mc[i][0]; x <= mc[i][2]; x++) {
                                for (int y = mc[i][1]; y <= mc[i][3]; y++) {
                                    if (pc[i][x][y] == '#') {
                                        if (full[x + a][y + b] != '#') {
                                            r = 0;
                                            break;
                                        }
                                        chk[x + a][y + b] = '#';
                                    }
                                }
                                if (!r) break;
                            }
                            if (!r) continue;
                            for (int x = mc[j][0]; x <= mc[j][2]; x++) {
                                for (int y = mc[j][1]; y <= mc[j][3]; y++) {
                                    if (pc[j][x][y] == '#') {
                                        if (full[x + c][y + d] != '#' || chk[x + c][y + d] == '#') {
                                            r = 0;
                                            break;
                                        }
                                        chk[x + c][y + d] = '#';
                                    }
                                }
                                if (!r) break;
                            }
                            if (!r) continue;
                            for (int x = 0; x < n; x++) {
                                for (int y = 0; y < n; y++) {
                                    if (chk[x][y] != full[x][y]) {
                                        r = 0;
                                        break;
                                    }
                                }
                                if (!r) break;
                            }
                            if (!r) continue;
                            
                            printf("%d %d", i + 1, j + 1);
                            return 0;
                        }
                    }
                }
            }

        }
    }
    return 0;
}