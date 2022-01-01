#include <stdio.h>

/*
문제 : 2차원 평면상의 N(1 <= N <= 5000)개의 점에 대해 좌표와 질량이 주어질 때, 모든 점의 무게중심을 구한다.
주어지는 좌표와 질량은 5000 이하의 자연수 범위에 있다. 이를 N이 음수인 경우가 나올 때 까지 반복한다.

해결 방법 : 각 좌표와 무게의 곱을 더한 값을 무게로 나누면 무게중심이 된다.

주요 알고리즘 : 수학, 물리학

출처 : NCNA 2013 G번
*/

int main(void) {
    int n;
    double x, y, m, ax, ay, am;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) return 1;
        else if (n < 0) break;
        ax = 0, ay = 0, am = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf", &x, &y, &m);
            ax += x * m;
            ay += y * m;
            am += m;
        }
        printf("Case %d: %.2f %.2f\n", tt, ax / am, ay / am);
    }
    return 0;
}