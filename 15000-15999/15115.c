#include <stdio.h>
#include <math.h>

/*
문제 : mx + kp / m의 값이 최소가 되는 자연수 m일 때의 해당 식의 값을 찾는다.

해결 방법 : 미분을 통해 도함수의 값이 0일 때의 m 값을 찾으면 sqrt(kp / x)가 된다. 따라서, 이 값에서 가장 가까운
자연수일 때의 식의 값을 구하면 답이 된다.

주요 알고리즘 : 수학, 미적분학

출처 : PacNW 2017 L번/Y번
*/

int main(void) {
    int k, p, x;
    double best = 1E32, m;
    scanf("%d %d %d", &k, &p, &x);
    m = sqrt((double)k * p / x);
    for (int i = (int)(m - 5); i <= (int)(m + 5); i++) {
        if (i < 1) continue;
        if ((double)i * x + (double)k * p / i < best) best = (double)i * x + (double)k * p / i;
    }
    printf("%.3f", best);
    return 0;
}