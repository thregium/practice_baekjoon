#include <stdio.h>
#include <stdlib.h>

/*
문제 : 현재 위치와 엘리베이터의 위치, 높이 1당 걸어갈 때와 엘리베이터가 움직일 때의 단위 시간이
주어질 때, 높이 0으로 가는 대 걸리는 최소 시간을 구한다.

해결 방법 : 모든 칸을 걸어가는 것과 엘리베이터를 기다리는 것, 엘리베이터의 위치까지
이동한 다음 타는 것 3가지의 경우를 비교해서 가장 빠른 것을 타면 된다. 중간에서 버튼을 누르는 것은
의미가 없으므로 생각하지 않아도 된다.

주요 알고리즘 : 수학, 케이스 워크

출처 : CTU 2021 I번
*/

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    long long t, yp, lp, ys, ls, a, b, c;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld %lld %lld", &yp, &lp, &ys, &ls);
        a = yp * ys;
        b = (yp + abs(yp - lp)) * ls;
        c = abs(yp - lp) * ys + lp * ls;
        printf("%lld\n", small(a, small(b, c)));
    }
    return 0;
}