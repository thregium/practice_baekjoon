#include <stdio.h>

/*
문제 : 해가 += 10^6만 범위에 유일하게 있는 N(N <= 11)차 방정식이 주어질 때,
이 방정식의 해 * 1000을 자연수 단위로 버림한 수를 구한다. 단, 중근을 갖는 경우는 주어지지 않는다.
또한, 모든 답은 정밀도 1E-6으로 충분히 구할 수 있다.

해결 방법 : +100만과 -100만에서 시작해 범위를 좁혀가며 해가 있는 곳을 찾아나간다. 해가 유일하고 양쪽의 부호가 다르기 때문에
가운데 값의 부호를 통해 좁힐 범위를 정할 수 있다. 가운데 값이 양수인 경우 감소하는 그래프라면 오른쪽으로 좁히고,
증가하는 그래프라면 왼쪽으로 좁히면 되고, 음수인 경우에는 그 반대로 좁히면 된다.

주요 알고리즘 : 수학, 파라메트릭, 수치해석

출처 : USACO 2009F B2번
*/

double coef[16];

double calc_poly(int n, double x) {
    double r = 0, t = 1;
    for (int i = 0; i <= n; i++) {
        r += coef[i] * t;
        t *= x;
    }
    return r;
}

int main(void) {
    int n, dir = 0;
    double lo = -1048576, hi = 1048576, mid;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &coef[i]);
    }
    if (calc_poly(n, lo) * calc_poly(n, hi) >= 0) return 1;
    if (calc_poly(n, lo) < 0) dir = 1;
    else dir = -1;

    while (hi - lo > 1E-7) {
        mid = (hi + lo) / 2;
        if (calc_poly(n, mid) > 0) {
            if (dir > 0) hi = mid;
            else lo = mid;
        }
        else {
            if (dir > 0) lo = mid;
            else hi = mid;
        }
    }
    printf("%lld", (long long)(hi * 1000LL));
    return 0;
}