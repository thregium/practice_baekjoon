#include <stdio.h>
#include <math.h>

/*
문제 : 반지름 R(1 <= R <= 1000, 자연수)인 원에서 거리 H(R <= H <= 1000, 자연수)인 점에 이르도록
줄을 감았을 때, 줄의 길이를 구한다. 매듭의 길이로 전체의 S(S <= 100, 음이 아닌 정수)%를 추가해야 한다.

해결 방법 : 접선 부분은 피타고라스 정리를 이용해 구할 수 있다. 호 부분은 360도에서 삼각 함수를 이용해서
원주에 닿지 않는 길이만큼을 빼면 되고, 이는 acos() 함수를 이용해 구할 수 있다.
최종적으로 매듭의 길이를 보정하면 답이 된다.

주요 알고리즘 : 기하학

출처 : VTH 2014 H번
*/

int main(void) {
    double r, h, s, ang, res;
    while (1) {
        scanf("%lf %lf %lf", &r, &h, &s);
        if (r < 0.5) break;
        ang = acos(0) * 4;
        res = sqrt(h * h - r * r) * 2;
        ang -= 2 * acos(r / h);
        printf("%.2f\n", (res + ang * r) * (100.0 + s) / 100.0);
    }
    return 0;
}
