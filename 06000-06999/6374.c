#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 배열에서 특정한 직사각형 부분의 합이 가장 큰 것을 구한다.

해결 방법 : X축의 최소, 최대 값을 고정시킨 후 Y값을 순서대로 따라가며 해당하는 X축의 최소, 최대 값에서
Y축의 최솟값에서부터 모든 최댓값에 대한 합을 구할 수 있고, 그렇게 모든 경우를 확인해 보면 된다.

주요 알고리즘 : 브루트 포스

출처 : GNY 2001 H번
*/

int a[128][128];

int main(void) {
    int n, s, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int ii = i; ii < n; ii++) {
                s = 0;
                for (int y = j; y < n; y++) {
                    for (int x = i; x <= ii; x++) {
                        s += a[x][y];
                    }
                    if (s > best) best = s;
                }
            }
        }
    }
    printf("%d", best);
    return 0;
}