#include <stdio.h>

/*
문제 : 두 기차가 D km 거리에서 서로를 향해 출발한다. 한 열차는 시속 A km, 다른 열차는 시속 B km이다. 두 열차가 만날 때 까지
파리는 시속 F km로 두 열차 사이를 움직일 때, 파리가 움직인 거리를 구한다.

해결 방법 : 파리가 움직인 거리는 파리가 움직인 속도 * 움직인 시간이다. 움직인 시간은 두 열차가 만날 때 까지의 시간이므로
D / (A + B)이고, 따라서, 답은 D / (A + B) * F가 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : GNY 2013 B번
*/

int main(void) {
    int p, n;
    double d, a, b, f;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d %lf %lf %lf %lf", &n, &d, &a, &b, &f);
        printf("%d %lf\n", n, d / (a + b) * f);
    }
    return 0;
}