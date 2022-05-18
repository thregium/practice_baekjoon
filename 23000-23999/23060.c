#include <stdio.h>

/*
문제 : N * N(N <= 500) 크기의 체스판에서 (X, Y)에 나이트가 있을 때, 나이트를 2 * N^2회 이내로
모든 칸에 1회 이상 방문하도록 움직이는 방법이 있는 지 찾고, 있다면 그러한 방법 가운데 하나를 구한다.

해결 방법 : V자 형태로 움직여 나가면 행과 (floor(행 / 2) + 열)의 홀짝성이 같은 칸을
모두 방문할 수 있다. 이를 이용해 그러한 칸들을 모두 방문한 다음, 다시 (floor(행 / 2) + 열)의 홀짝성을
바꾼 후 그러한 칸들을 전부 방문한다. ㄹ자 형태로 행을 이동해 나가면 (1, 1)에서 시작했을 때 홀수번째 행을
모두 방문하는 것이 가능하다. 다시 (2, 1)로 움직인 다음 모든 짝수번째 행을 같은 방법으로
방문해 돌아오면 된다.

(1, 1)로 돌아오는 방법으로는 행의 변화가 2인 이동 가운데 (1, 1)에 가까워지는 순서대로 가능한 이동을 하여
행과 열의 값이 모두 2 이하가 되도록 한 다음 각 칸들에 대해 (1, 1)로 움직이는 것이 있다.

이 방법대로 이동하면 약 N^2 + 2N회 안에 항상 이동이 가능하다.

위 방법을 각 상태에 대해 경우의 수를 나누어 해결하면 된다. N이 2 또는 3인 경우 불가능하고,
N이 1인 경우는 가능하지만 3 이하에 대해서는 따로 예외 처리를 하는 것이 좋다.

주요 알고리즘 : 케이스 워크, 구성적

출처 : 충남대 5회 F번
*/

int cnt[512][512] = {{1}, }, res[524288][2] = {{1, 1},};
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };
int n, rlen = 1;

int moveknight(int* x, int* y, int dir) {
    *x += dxy[dir][0];
    *y += dxy[dir][1];
    if (*x < 1 || *y < 1 || *x > n || *y > n) {
        *x -= dxy[dir][0];
        *y -= dxy[dir][1];
        return 0;
    }
    else {
        res[rlen][0] = *x;
        res[rlen++][1] = *y;
        cnt[*x][*y]++;
        return 1;
    }
}

int verify(void) {
    int dx, dy, tmp;
    if (rlen > n * n * 2) return 0;
    for (int i = 0; i < rlen; i++) {
        if (res[i][0] < 1 || res[i][1] < 1 || res[i][0] > n || res[i][1] > n) return 0;
        cnt[res[i][0]][res[i][1]]++;
        if (i == 0) continue;
        dx = res[i][0] - res[i - 1][0];
        dy = res[i][1] - res[i - 1][1];
        tmp = 0;
        for (int j = 0; j < 8; j++) {
            if (dx == dxy[j][0] && dy == dxy[j][1]) {
                tmp = 1;
                break;
            }
        }
        if (!tmp) return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cnt[i][j] == 0) return 0;
        }
    }
    return 1;
}

int main(void) {
    int rowp = 0, colp = 0, dirlr = 0, dirud = 0, ok = 1, x = 1, y = 1;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    res[0][0] = x, res[0][1] = y;
    if (n < 4) {
        if (n == 1) printf("1\n1 1");
        else printf("-1");
        return 0;
    }
    while (x > 2 || y > 2) {
        if (rlen > n * 2) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) {
            ok = moveknight(&x, &y, 6);
            if (!ok) {
                ok = moveknight(&x, &y, 2);
                if (!ok) return 11;
            }
        }
    }
    if (x == 2 && y == 2) {
        ok = moveknight(&x, &y, 0);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 2);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) return 12;
    }
    else if (x == 2 && y == 1) {
        ok = moveknight(&x, &y, 7);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 2);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) return 12;
    }
    else if (x == 1 && y == 2) {
        ok = moveknight(&x, &y, 0);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 3);
        if (!ok) return 12;
        ok = moveknight(&x, &y, 5);
        if (!ok) return 12;
    }
    else if (x == 1 && y == 1);
    else return 12;
    if (x != 1 || y != 1) return 12;

    while (rowp < 2) {
        if (colp) {
            if (dirlr) {
                if (dirud) ok = moveknight(&x, &y, 5);
                else ok = moveknight(&x, &y, 2);
                if (!ok) {
                    if (dirud) {
                        ok = moveknight(&x, &y, 6);
                        if (!ok) return 1;
                        ok = moveknight(&x, &y, 5);
                        if (!ok) {
                            ok = moveknight(&x, &y, 1);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 3);
                            if (!ok) return 1;
                            dirlr = 0;
                            dirud = 1;
                            rowp++;
                            colp = 0;
                            continue;
                        }
                        ok = moveknight(&x, &y, 6);
                        dirlr = 0;
                        dirud = 0;
                    }
                    else {
                        ok = moveknight(&x, &y, 6);
                        if (!ok) break;
                        ok = moveknight(&x, &y, 5);
                        dirlr = 0;
                        dirud = 0;
                    }
                }
                else dirud = (!dirud);
            }
            else {
                if (dirud) ok = moveknight(&x, &y, 6);
                else ok = moveknight(&x, &y, 1);
                if (!ok) {
                    if (dirud) {
                        ok = moveknight(&x, &y, 5);
                        if (!ok) return 1;
                        ok = moveknight(&x, &y, 6);
                        if (!ok) return 2;
                        ok = moveknight(&x, &y, 5);
                        dirlr = 1;
                        dirud = 0;
                    }
                    else {
                        ok = moveknight(&x, &y, 5);
                        if (!ok) return 2;
                        ok = moveknight(&x, &y, 6);
                        dirlr = 1;
                        dirud = 0;
                    }
                }
                else dirud = (!dirud);
            }
        }
        else {
            if (dirlr) {
                if (dirud) ok = moveknight(&x, &y, 5);
                else ok = moveknight(&x, &y, 2);
                if (!ok) {
                    if (dirud) {
                        ok = moveknight(&x, &y, 1);
                        if (!ok) {
                            ok = moveknight(&x, &y, 7);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 4);
                            if (!ok) return 1;
                            dirlr = 0;
                            dirud = 0;
                            colp = 1;
                            continue;
                        }
                        ok = moveknight(&x, &y, 2);
                        dirlr = 0;
                        dirud = 1;
                    }
                    else {
                        ok = moveknight(&x, &y, 1);
                        if (!ok) return 1;
                        ok = moveknight(&x, &y, 2);
                        if (!ok) {
                            ok = moveknight(&x, &y, 7);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 4);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 2);
                            if (!ok) return 1;
                            dirlr = 0;
                            dirud = 1;
                            colp = 1;
                            continue;
                        }
                        ok = moveknight(&x, &y, 1);
                        dirlr = 0;
                        dirud = 1;
                    }
                }
                else dirud = (!dirud);
            }
            else {
                if (dirud) ok = moveknight(&x, &y, 6);
                else ok = moveknight(&x, &y, 1);
                if (!ok) {
                    if (dirud) {
                        ok = moveknight(&x, &y, 2);
                        if (!ok) {
                            ok = moveknight(&x, &y, 4);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 7);
                            if (!ok) return 1;
                            dirlr = 1;
                            dirud = 0;
                            colp = 1;
                            continue;
                        }
                        ok = moveknight(&x, &y, 1);
                        dirlr = 1;
                        dirud = 1;
                    }
                    else {
                        ok = moveknight(&x, &y, 2);
                        if (!ok) return 1;
                        ok = moveknight(&x, &y, 1);
                        if (!ok) {
                            ok = moveknight(&x, &y, 4);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 7);
                            if (!ok) return 1;
                            ok = moveknight(&x, &y, 1);
                            if (!ok) return 1;
                            dirlr = 1;
                            dirud = 1;
                            colp = 1;
                            continue;
                        }
                        ok = moveknight(&x, &y, 2);
                        dirlr = 1;
                        dirud = 1;
                    }
                }
                else dirud = (!dirud);
            }
        }
    }

    if (!verify()) return -1;

    printf("%d\n", rlen);
    for (int i = 0; i < rlen; i++) {
        //printf("%d %d\n", res[i][0], res[i][1]);
    }
    return 0;
}