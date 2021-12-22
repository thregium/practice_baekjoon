#include <stdio.h>

/*
문제 : 에스컬레이터 두 줄의 속도와 각 줄의 사람 수, 줄이 줄어드는 속도가 주어질 때, 어느 줄이 더 빠른 지 구한다.
단, 두 줄의 도착 시간은 최소 1초 이상 차이 난다.

해결 방법 : 보장된 차이가 크기 때문에 부동 소숫점 연산을 통해 둘의 예상 도착 시간을 비교하면 된다.

주요 알고리즘 : 수학

출처 : Swoi 2018F A번
*/

int main(void) {
    double m, s, g, a, b, l, r;
    scanf("%lf %lf %lf%lf %lf%lf %lf", &m, &s, &g, &a, &b, &l, &r);
    if (m / s + r / b > m / g + l / a) printf("friskus");
    else printf("latmask");
    return 0;
}