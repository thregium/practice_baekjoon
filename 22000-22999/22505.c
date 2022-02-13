#include <stdio.h>
#include <math.h>

/*
문제 : [L, R](0 <= L < R <= 12) 범위에서 이분 탐색을 K(K <= 30)회 진행한 후 나온 값이
T와 오차 E(T, E <= 12) 이내일 확률을 구한다. 단, 매 단계마다 잘못 선택할 확률이 P(0 <= P <= 1)이다.

해결 방법 : 범위를 좁혀가며 이분 탐색을 K회 진행한다. 단, 전체 범위가
T와 오차 E보다 큰 경우 더이상 이분 탐색을 진행하더라도 원하는 범위에 들어가지 않으므로 0을 반환하고,
전체 범위가 해당 범위 이내인 경우 반드시 원하는 범위에 들어가므로 해당 범위에 들어갈 확률을 반환한다.
둘 다 아니라면 양쪽으로 범위가 갈 확률을 확인하며 양쪽의 답을 합해서 반환한다.
K회 이분 탐색을 진행한 경우에는 중앙값을 확인하고 그 값이 범위 안이라면 확률을, 아니라면 0을 반환한다.

주요 알고리즘 : 수학, 확률론, 분할 정복

출처 : JAG 2011S3 B번
*/

double slep(int k, double l, double r, double p, double e, double t, double pp) {
    if (l > t + e || r < t - e) return 0;
    else if (t - e <= l && r <= t + e) return pp;
    if (k == 0) {
        if (fabs((l + r) / 2.0 - t) <= e) return pp;
        else return 0;
    }
    else {
        if ((l + r) / 2.0 >= t) {
            return slep(k - 1, l, (l + r) / 2.0, p, e, t, pp * (1.0 - p)) +
                slep(k - 1, (l + r) / 2.0, r, p, e, t, pp * p);
        }
        else {
            return slep(k - 1, l, (l + r) / 2.0, p, e, t, pp * p) +
                slep(k - 1, (l + r) / 2.0, r, p, e, t, pp * (1.0 - p));
        }
    }
}

int main(void) {
    int k;
    double l, r, p, e, t;
    scanf("%d %lf %lf%lf%lf%lf", &k, &l, &r, &p, &e, &t);
    printf("%.9f\n", slep(k, l, r, p, e, t, 1));
    return 0;
}