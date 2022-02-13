#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : H * W(H, W <= 25) 크기의 격자 형태 도로에서 한 행과 한 열을 간선으로 하려고 한다.
각 격자점에는 A_ij(<= 1000)명의 사람이 산다. 이때, 모든 사람의 간선도로에서의 맨해튼 거리 합이
최소가 되도록 간선도로를 설정할 때, 그 합의 최솟값을 구한다.

해결 방법 : H와 W가 작으므로 간선도로를 선택하는 모든 경우를 해보고 맨해튼 거리 합의 최솟값을 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : JOI 2018예 3번
*/

int a[32][32];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int h, w, c, r = INF;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            c = 0;
            for (int ii = 0; ii < h; ii++) {
                for (int jj = 0; jj < w; jj++) {
                    c += a[ii][jj] * small(abs(ii - i), abs(jj - j));
                }
            }
            if (c < r) r = c;
        }
    }
    printf("%d\n", r);
    return 0;
}