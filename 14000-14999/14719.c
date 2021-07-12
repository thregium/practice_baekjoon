#include <stdio.h>

/*
문제 : H * W(H, W <= 500) 크기의 격자에서 물을 채울 때, 물이 차게 되는 칸의 수를 구한다.
각 벽들은 밑에서부터 차례로 쌓아올려진 형태이며, 해당 높이에서 양쪽에 벽이 있는 경우에만 벽의 사이에 물이 차게 된다.

해결 방법 : 맨 아래에서부터 차례로 양쪽에 벽이 있는지 확인한 후 있다면 해당 칸에 물을 채워가며 물이 차는 칸 수를 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : 충남대 1회 D번
*/

char rain[512][512];

int main(void) {
    int h, w, x, last, r = 0;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < w; i++) {
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            rain[i][j] = 1;
        }
    }
    for (int i = 0; i < h; i++) {
        last = -1;
        for (int j = 0; j < w; j++) {
            if (!rain[j][i]) continue;
            if (last == -1) {
                last = j;
                continue;
            }
            else {
                r += j - last - 1;
                last = j;
            }
        }
    }
    printf("%d", r);
    return 0;
}