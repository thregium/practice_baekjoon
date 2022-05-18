#include <stdio.h>

/*
문제 : 주어진 형태의 그래프로 잠을 잘 때 일의 효율이 나오는 경우 가장 일을 많이 할 수 있는
수면 시간에서의 할 수 있는 일의 양을 구한다.

해결 방법 : 그래프의 개형이 위로 볼록한 형태가 되기 때문에 삼분 탐색을 통해 빠르게 답을 구할 수 있다.

주요 알고리즘 : 수학, 삼분 탐색

출처 : ROI 2021H K번
*/

int main(void) {
    double p, t, lo, hi, mid1, mid2, eff1, eff2;
    scanf("%lf %lf", &p, &t);
    lo = 0, hi = t / 3.0;
    for (int i = 0; i < 401; i++) {
        mid1 = (lo * 2 + hi) / 3;
        mid2 = (lo + hi * 2) / 3;
        if (mid1 < t / 6.0) eff1 = p * (mid1 / (t / 6.0)) / 100.0;
        else eff1 = (p + (mid1 - t / 6.0) / (t / 6.0) * (100.0 - p)) / 100.0;
        if (mid2 < t / 6.0) eff2 = p * (mid2 / (t / 6.0)) / 100.0;
        else eff2 = (p + (mid2 - t / 6.0) / (t / 6.0) * (100.0 - p)) / 100.0;

        if ((t - mid1) * eff1 < (t - mid2) * eff2) lo = mid1;
        else hi = mid2;
    }
    printf("%.9f", (t - mid1) * eff1 * 100.0);
    return 0;
}