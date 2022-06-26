#include <stdio.h>

/*
문제 : K(K <= 10)차 다항식의 각 항의 계수(<= 10, 음이 아닌 정수)가 주어질 때, [A, B](A < B <= 10)
범위를 적분한 것과 N(N <= 10)개의 구간으로 나누어 구분구적한 것이 같도록 하는 엡실론 값을 구한다.

해결 방법 : 엡실론의 범위 안에는 반드시 답이 존재하며 그 범위에서 결괏값은 단조 증가하기 때문에
(모든 항이 양수 또는 0이므로) 매개 변수 탐색을 사용하면 된다.

주요 알고리즘 : 수학, 미적분학, 파라메트릭

출처 : 아주대 2017D2 D2번
*/

int coef[16];

double fx(int k, double x) {
    double res = 0.0, xx = 1.0;
    for (int i = 0; i <= k; i++) {
        res += xx * coef[i];
        xx *= x;
    }
    return res;
}

double func(int k, double ep, int a, int n, double dx) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += fx(k, a + dx * i + ep) * dx;
    }
    //printf("%.9f\n", res);
    return res;
}

int main(void) {
    int k, a, b, n;
    double actual = 0.0, tx, hi, lo, mid, dx;
    scanf("%d", &k);
    for (int i = k; i >= 0; i--) {
        scanf("%d", &coef[i]);
    }
    scanf("%d %d %d", &a, &b, &n);
    dx = (b - (double)a) / n;
    hi = dx, lo = 0.0;
    for (int i = 0; i <= k; i++) {
        tx = coef[i];
        for (int j = 0; j <= i; j++) tx *= b;
        tx /= (i + 1);
        actual += tx;
        tx = coef[i];
        for (int j = 0; j <= i; j++) tx *= a;
        tx /= (i + 1);
        actual -= tx;
    }

    for (int i = 0; i < 0401; i++) {
        mid = (lo + hi) / 2.0;
        if (func(k, mid, a, n, dx) < actual) lo = mid;
        else hi = mid;
    }
    printf("%.9f", lo);
    return 0;
}