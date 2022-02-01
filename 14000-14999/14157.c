#include <stdio.h>

/*
문제 : S * S(S <= 40) 크기의 건물 옥상에 H(H <= 50)개의 출입구가 있다. 출입구는 모두 격자점에 있으며,
출입구가 아닌 격자점에 개들을 매달아 놓을 수 있다. 각 개들을 옥상에서 떨어지지 않고 묶을 수 있는
점 가운데 모든 출입구에 개들이 도달 가능한 가장 X좌표 -> Y좌표가 작은 점을 구한다.
없다면 -1 -1을 출력한다.

해결 방법 : S의 크기가 작기 때문에 브루트 포스를 하면 된다.
개를 묶을 수 있는 모든 지점에 대해 모든 출입구에 개들이 도달 가능한지 확인한다.
줄의 길이는 가장 가까운 건물 옥상의 테두리까지의 거리와 같고,
이 거리를 피타고라스 정리로 각 출입구까지의 거리와 비교해 모든 경우 줄의 거리가 그 이하인지 살피면 된다.
이때, 출입구와 좌표가 같으면 안 된다는 점에 유의한다.

주요 알고리즘 : 기하학, 브루트 포스

출처 : CPC 2007 C번
*/

int hole[64][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int getlinelen(int s, int x, int y) {
    return small(small(x, y), small(s - x, s - y));
}

int getdist(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(void) {
    int t, s, h, x, y, l, tmp;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &s, &h);
        for (int i = 0; i < h; i++) {
            scanf("%d %d", &hole[i][0], &hole[i][1]);
        }
        x = -1, y = -1;
        for (int i = s - 1; i > 0; i--) {
            for (int j = s - 1; j > 0; j--) {
                l = getlinelen(s, i, j);
                tmp = 1;
                for (int k = 0; k < h; k++) {
                    if (getdist(hole[k][0], hole[k][1], i, j) > l * l) tmp = 0;
                    if (hole[k][0] == i && hole[k][1] == j) tmp = 0;
                }
                if (tmp) {
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}