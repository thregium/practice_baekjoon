#include <stdio.h>

/*
문제 : N문제 가운데 K(N, K <= 10000)문제를 풀었고 전체 문제의 평균 난이도가 D, 푼 문제의 평균 난이도가 S(0 <= D, S <= 100)라 할때,
남은 문제들의 평균 난이도를 구한다. 단, 범위를 벗어나는 경우 impossible을 출력한다.

해결 방법 : 먼저 아직 풀지 못한 문제의 난이도 합을 구한다. 전체 난이도 합에서 푼 문제의 난이도 합을 빼서 D * N - K * S의 값을 구하면 된다.
풀지 못한 문제의 평균 난이도는 풀지 못한 문제의 난이도 합 / 풀지 못한 문제의 수이므로 이를 계산하고, 범위 안에 있는지 확인한 다음
범위 안이라면 평균값을 출력하고 밖이라면 impossible을 출력하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : NWERC 2020 C번
*/

int main(void) {
    int n, k, d, s, rem;
    double ave;
    scanf("%d %d%d %d", &n, &k, &d, &s);
    rem = d * n - k * s;
    ave = rem / ((double)n - k);
    if (ave >= 0 && ave <= 100) printf("%.9f", ave);
    else printf("impossible");
    return 0;
}