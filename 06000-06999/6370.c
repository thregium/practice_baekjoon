#include <stdio.h>
#include <math.h>

/*
문제 : v2 = RC d/dt (v1 – v2) 이고 v1 = Vs cos ω t, v2 = Vr cos ( ωt + θ )일 때
고정된 R, C, Vs에 대해 각 ω마다 Vr의 값을 구한다.

해결 방법 : ??

주요 알고리즘 : 수학, 미적분학

출처 : GNY 2001 D번
*/

int main(void) {
    int n;
    double vs, r, c, om;
    scanf("%lf %lf %lf %d", &vs, &r, &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &om);
        printf("%.3f\n", r * c * vs / sqrt(1 + pow(1 / (om * r * c), 2)));
    }
    return 0;
}