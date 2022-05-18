#include <stdio.h>

/*
문제 : N * N(N <= 10) 크기의 '.'과 '#'으로 이루어진 격자에서 '.'으로 이루어진 가장 큰 정사각형의
한 변의 길이를 구한다.

해결 방법 : N이 작기 때문에 가능한 모든 정사각형에 대해 '.'으로 이루어진 가장 큰 정사각형을 찾고,
그 한 변의 길이를 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : INC 2009 F번
*/

char land[16][16];

int main(void) {
    int t, n, r = 0, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", land[i]);
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; i + k < n && j + k < n; k++) {
                    cnt = 0;
                    for (int ii = i; ii <= i + k; ii++) {
                        for (int jj = j; jj <= j + k; jj++) {
                            if (land[ii][jj] == '#') cnt++;
                        }
                    }

                    if (cnt == 0) {
                        if (k + 1 > r) r = k + 1;
                    }
                }
            }
        }

        printf("%d\n", r);
    }
    return 0;
}