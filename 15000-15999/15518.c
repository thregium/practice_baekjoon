#include <stdio.h>

/*
문제 :N(N <= 100)개의 높이 H, 너비 W(H, W <= 100)인 창문이 일렬로 있다. 이때, 각 창문을 X_i(X_i <= W)만큼 옮긴 후
창문의 열린 공간의 너비를 구한다. 홀수번째 창문은 오른쪽으로, 짝수번째 창문은 왼쪽으로 옮긴다.

해결 방법 : 창문이 있는 위치를 배열에 저장한 다음, 배열을 돌며 창문이 없는 위치의 개수를 구하면 된다.

주요 알고리즘 : 구현

출처 : JAG 2017P A번
*/

char wind[128][10240];

int main(void) {
    int n, h, w, x, r = 0;
    scanf("%d %d %d", &n, &h, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (i & 1) {
            for (int j = 0; j < h; j++) {
                for (int k = w * i - x; k < w * (i + 1) - x; k++) {
                    wind[j][k] = 1;
                }
            }
        }
        else {
            for (int j = 0; j < h; j++) {
                for (int k = w * i + x; k < w * (i + 1) + x; k++) {
                    wind[j][k] = 1;
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w * n; j++) {
            r += !wind[i][j];
        }
    }
    printf("%d", r);
    return 0;
}