#include <stdio.h>

/*
문제 : (0, 0)에서 (X, Y) 지점으로 직선 형태로 광선을 쏘려고 한다. 중간에 겹치지 않는 N(N <= 100)개의
구간에서는 X방향의 속도가 F(0.0 < F <= 10.0)배로 바뀐다.
이때, 광선을 쏴야 하는 각도(Y에 대한 X값)를 구한다.

해결 방법 : 전체 값에서 Y를 굴절률만큼 보정한 다음 X / Y를 하면 된다.

주요 알고리즘 : 수학, 기하학

출처 : NWERC 2016 C번
*/

int main(void) {
    int n, l, u;
    double f, x, y, r = 0.0;
    scanf("%lf %lf%d", &x, &y, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %lf", &l, &u, &f);
        y -= (u - l) - (u - l) * f;
    }
    printf("%.9f", x / y);
    return 0;
}