#include <stdio.h>

/*
문제 : 해당 날의 기분(좋음, 나쁨)이 주어지고, 각 날의 기분에 따라 기분이 바뀔 확률이 주어질 때,
N(N <= 100)일 후의 기분에 대한 확률 출력한다.

해결 방법 : N일간 각 날의 기분이 나올 확률을 갱신해 나가며 계산한다. N일이 끝나면 두 확률을 출력하면 된다.

주요 알고리즘 : 수학, 확률론

출처 : 한양대E 2019M B번 / 2019P B번
*/

int main(void) {
    int n, m;
    double good = 0.0, bad = 0.0, gg, gb, bg, bb, ng, nb;
    scanf("%d %d", &n, &m);
    if (m) bad = 1.0;
    else good = 1.0;
    scanf("%lf %lf %lf %lf", &gg, &gb, &bg, &bb);
    for (int i = 0; i < n; i++) {
        ng = good * gg + bad * bg;
        nb = good * gb + bad * bb;
        good = ng;
        bad = nb;
    }
    printf("%.0f\n%.0f", good * 1000, bad * 1000);
    return 0;
}