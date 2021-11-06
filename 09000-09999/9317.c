#include <stdio.h>
#include <math.h>

/*
문제 : D, 가로 해상도, 세로 해상도가 각각 주어질 때, 수직과 수평 DPI를 각각 구한다. (식은 문제에서 주어진다.)
화면 비는 16:9를 따른다고 가정한다.

해결 방법 : 문제에 주어진 식대로 값을 구한 다음 출력한다.

주요 알고리즘 : 수학, 구현

출처 : UVaH 2011 PB번
*/

int main(void) {
    int rh, rv;
    double d, w, h;
    while (1) {
        scanf("%lf %d %d", &d, &rh, &rv);
        if (rh == 0) break;
        w = 16 * d / sqrt(337);
        h = 9.0 / 16.0 * w;
        printf("Horizontal DPI: %.2f\n", rh / w);
        printf("Vertical DPI: %.2f\n", rv / h);
    }
    return 0;
}