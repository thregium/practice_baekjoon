#include <stdio.h>

/*
문제 : N * N(N <= 250) 크기의 0과 1이 쓰인 배열에서 각 칸과 주위 R칸의 배열에
쓰인 값의 합을 각각 구해 출력한다.

해결 방법 : 제한시간이 길기 때문에 직접 합을 구하더라도 시간 내에 들어올 수 있다.
배열의 밖으로 벗어나지 않도록 주의한다.

주요 알고리즘 : 구현

출처 : POI 2000/2001_1 3번
*/

int a[256][256];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, r, s;
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s = 0;
            for (int ii = big(0, i - r); ii <= small(n - 1, i + r); ii++) {
                for (int jj = big(0, j - r); jj <= small(n - 1, j + r); jj++) s += a[ii][jj];
            }
            printf("%d ", s);
        }
        printf("\n");
    }
    return 0;
}