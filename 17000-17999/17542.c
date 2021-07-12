#include <stdio.h>

/*
문제 : R * C(R, C <= 100) 크기의 격자에 건물들이 있다. 동쪽과 북쪽에서 보았을 때의 각 줄의 가장 높은 건물의 높이가 주어지면,
해당하는 형태로 건물을 지을 수 있는지 구한다.

해결 방법 : 동쪽에서 보았을 때 기준으로 가장 높은 줄과 북쪽에서 보았을 때 가장 높은 줄이 만나는 칸을 기준으로
해당 줄에서 가로와 세로로 건물들을 배치하면 양쪽에서 가장 높은 건물의 높이가 같다면 항상 건물을 지을 수 있다.
그러나 양쪽에서 가장 높은 건물의 높이가 다르다면 어떻게 하더라도 건물을 지을 수 없다.

주요 알고리즘 : 그리디 알고리즘

출처 : BAPC 2019P A번
*/

int main(void) {
    int r, c, xi, yi, xm = 0, ym = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%d", &xi);
        if (xi > xm) xm = xi;
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", &yi);
        if (yi > ym) ym = yi;
    }
    if (xm == ym) printf("possible");
    else printf("impossible");
    return 0;
}