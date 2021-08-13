#include <stdio.h>

/*
문제 : 100만 이하의 수 N, M이 주어질 때, 매년 B%의 수익을 얻는다면 수익 N원에서 시작해 몇 년이 지나면 M원을 넘는지 구한다.
단, B는 50 이하이고, 모든 수는 소숫점 두 자리 까지의 양수이다.

해결 방법 : 실수 오차는 생각하지 않고 매년 B%씩 늘리며 시뮬레이션 하더라도 풀 수 있다.

주요 알고리즘 : 수학, 시뮬레이션

출처 : Rocky 2008 R번
*/

int main(void) {
    double n, b, m;
    int r = 0;
    while (scanf("%lf %lf %lf", &n, &b, &m) != EOF) {
        r = 0;
        for (double i = n; i <= m; i *= (100 + b) / 100) r++;
        printf("%d\n", r);
    }
    return 0;
}