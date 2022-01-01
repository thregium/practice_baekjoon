#include <stdio.h>

/*
문제 : 추격자로부터 직선상으로 D해리 떨어져있는 도망자가 Vf만큼의 속도로 그 수직방향으로 움직이고,
추격자가 Vg만큼의 속도로 쫓는다면 12해리만큼 이동하기 전에 잡히게 되는지 구한다.

해결 방법 : 피타고라스 정리를 통해 직선거리를 계산해보면 된다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : Brasil 2011 G번
*/

int main(void) {
    int d, f, g;
    while (scanf("%d %d %d", &d, &f, &g) != EOF) {
        if (144 * g * g >= (144 + d * d) * (f * f)) printf("S\n");
        else printf("N\n");
    }
    return 0;
}