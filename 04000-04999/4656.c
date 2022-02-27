#include <stdio.h>

/*
문제 : R(R <= 10) * C 크기의 픽셀로 된 그림이 N개씩 가로로 주어진다. 각 줄의 길이는 80 이하고,
각 그림 사이에는 공백이 주어진다. 이때, 각 그림을 2개 이하의 최소한의 픽셀로 구별할 수 있는 지 구하고,
가능한 경우 각 그림을 구별하는 픽셀을 최소한의 개수로 각각 출력한다.
단, 그러한 것이 여러 개인 경우 왼쪽 -> 위에 있는 것을 우선으로 한다.

해결 방법 : N, R, C의 크기가 크지 않기 때문에 모든 경우의 수를 직접 구하는 것이 가능하다.
단, 구현이 상당히 복잡하므로 주의한다.

주요 알고리즘 : 브루트 포스

출처 : MidC 2001 F번
*/

char px[64][16][96];

int main(void) {
    int n, r, c, res1, res2, res3;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\double\\double.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\double\\double_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d %d %d", &n, &r, &c);
        if (n == 0) break;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%s", px[j][i]);
            }
        }
        res1 = 1;
        for (int i = 0; i < n; i++) {
            res2 = 0;
            for (int x1 = 0; x1 < r; x1++) {
                for (int y1 = 0; y1 < c; y1++) {
                    if (px[i][x1][y1] == '.') continue;
                    res3 = 1;
                    for (int j = 0; j < n; j++) {
                        if (i == j) continue;
                        if (px[j][x1][y1] != '.') {
                            res3 = 0;
                            break;
                        }
                    }
                    if (!res3) continue;
                    px[i][x1][y1] = '#';
                    res2 = 1;
                    break;
                }
                if (res2) break;
            }
            if (res2) continue;
            for (int x1 = 0; x1 < r; x1++) {
                for (int y1 = 0; y1 < c; y1++) {
                    if (px[i][x1][y1] == '.') continue;
                    for (int x2 = 0; x2 < r; x2++) {
                        for (int y2 = 0; y2 < c; y2++) {
                            if (x1 == x2 && y1 == y2) continue;
                            if (px[i][x2][y2] == '.') continue;
                            res3 = 1;
                            for (int j = 0; j < n; j++) {
                                if (i == j) continue;
                                if (px[j][x1][y1] != '.' && px[j][x2][y2] != '.') {
                                    res3 = 0;
                                    break;
                                }
                            }
                            if (!res3) continue;
                            px[i][x1][y1] = '#';
                            px[i][x2][y2] = '#';
                            res2 = 1;
                            break;
                        }
                        if (res2) break;
                    }
                    if (res2) break;
                }
                if (res2) break;
            }
            if (res2 == 0) {
                res1 = 0;
                break;
            }
        }
        printf("Test %d\n", tt);
        if (res1 == 0) {
            printf("impossible\n");
            continue;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < n; j++) printf("%s%c", px[j][i], j == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}