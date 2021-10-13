#include <stdio.h>

/*
문제 : M * M(M <= 5) 크기의 배열이 주어질 때, 해당 배열이 마방진인지 구한다.
모든 행과 열, 대각선의 합이 같은지만 확인하면 된다.

해결 방법 : 배열을 입력받고 각 행과 열, 대각선의 합을 각각 구하고, 전부 같은지 확인하면 된다.

주요 알고리즘 ; 구현

출처 : PLU 2014N 8번
*/

int sqr[8][8];

int main(void) {
    int t, m, s, as, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &sqr[i][j]);
            }
        }
        as = 0, r = 1;
        for (int i = 0; i < m; i++) {
            s = 0;
            for (int j = 0; j < m; j++) s += sqr[i][j];
            if (i == 0) as = s;
            else if (as != s) r = 0;
            s = 0;
            for (int j = 0; j < m; j++) s += sqr[j][i];
            if (as != s) r = 0;
        }
        s = 0;
        for (int i = 0; i < m; i++) s += sqr[i][i];
        if (as != s) r = 0;
        s = 0;
        for (int i = 0; i < m; i++) s += sqr[i][m - i - 1];
        if (as != s) r = 0;

        if (r) printf("Magic square of size %d\n", m);
        else printf("Not a magic square\n");
    }
    return 0;
}