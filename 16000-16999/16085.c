#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795

/*
문제 : Y = 0인 직선 도로가 있다. 도로를 통해 차를 타면 단위시간당 C, 걸어가면 아무 방향으로든
단위시간당 W의 속력으로 이동 가능할 때, (0, 0)에서 출발한 지 시간 T(C, W, T <= 100, 자연수) 후
도달할 수 있는 범위의 넓이를 구한다.

해결 방법 : W가 C 이상인 경우에 이동 가능한 범위는 반지름이 WT인 원이 된다.
C가 W보다 커지면 이동 가능한 범위는 원에다가 (0, WC), (0, -WC)에서 반지름이 WT이고 중심이 (0, 0)인 원에
그은 접선의 내부를 추가로 포함하게 된다. 이 부분의 범위를 계산하여 답을 구하면 된다.

주요 알고리즘 : 기하학

출처 : MNPC 2018 I번
*/

int main(void) {
    int t;
    double tm, w, c, wl, cl, sl, area;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lf %lf %lf", &tm, &w, &c);
        wl = w * tm, cl = c * tm;

        if (wl + 1E-9 >= cl) printf("%.3f\n", wl * wl * PI);
        else {
            sl = sqrt(cl * cl - wl * wl);
            area = wl * wl * PI;
            area += sl * wl * 2;
            area -= acos(wl / cl) * wl * wl * 2;
            printf("%.3f\n", area);
        }
    }
    return 0;
}