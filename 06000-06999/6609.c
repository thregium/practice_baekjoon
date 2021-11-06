#include <stdio.h>

/*
문제 : M마리의 모기, P마리의 번데기, L(M, P, L <= 100000)마리의 유충이 있다. 각 주마다 모기는 E(E <= 100)마리의 유충이
되는 알들을 낳고 죽는다. 번데기는 S(R, S <= 10) 마리 가운데 한 마리만 모기가 되고 나머지는 죽으며 유충은 R마리 가운데
한 마리만 모기가 되고 나머지는 죽는다. N(N <= 1000)주 후 모기의 마릿수를 구한다. 살아있는 성체만 포함한다.

해결 방법 : 각 주마다 모기와 번데기, 유충의 수를 계산해 나간다. 다음 주의 모기 수는 전 주의 번데기 수 / S이고,
번데기는 전 주의 유충 수 / R, 유충은 전 주의 모기 수 * E이다. 서로간의 간섭이 일어나지 않도록
임시 변수를 쓰는 것이 좋다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : CTU 2012 F번
*/

int main(void) {
    int m, p, l, e, r, s, n, tm, tp, tl;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2012\\mosquito.in", "r", stdin);
    while (scanf("%d %d %d %d %d %d %d", &m, &p, &l, &e, &r, &s, &n) != EOF) {
        for (int i = 0; i < n; i++) {
            tm = p / s;
            tp = l / r;
            tl = m * e;
            m = tm;
            p = tp;
            l = tl;
        }
        printf("%d\n", m);
    }
    return 0;
}