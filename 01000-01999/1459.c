#include <stdio.h>
#include <stdlib.h>

/*
문제 : (0, 0)에서 (X, Y)(X, Y <= 10^9)로 이동하려 한다. 상하좌우로 1만큼 이동하는데에는 W,
대각선으로 (1, 1)만큼 이동하는데에는 S만큼 시간이 든다면 이동하는데 걸리는 최소 시간을 구한다.

해결 방법 : 대각선으로 이동하는 시간에 따라 경우를 나누어 해결한다. 만약 2칸 이동하는 시간보다 크다면
상하좌우로만 이동하는 것이 이득이다. 1칸 이동하는 시간과 2칸 이동하는 시간 사이인 경우에는
거리를 줄이는 경우에는 대각선 이동이 이득이고 그 외에는 상하좌우 이동이 이득이다.
1칸 이동하는 시간보다도 작은 경우에는 최대한 대각선 이동하는 것이 이득이다. 하지만 홀짝성이 다른 칸인 경우에는
대각선 이동만으로 도달 불가능하므로 1칸은 상하좌우로 이동해야 한다.

주요 알고리즘 : 기하학, 케이스 워크
*/

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    long long x, y, w, s;
    scanf("%lld %lld %lld %lld", &x, &y, &w, &s);
    if (s > w * 2) printf("%lld", (llabs(x) + llabs(y)) * w);
    else if (s > w) {
        printf("%lld", small(llabs(x), llabs(y)) * s + (big(llabs(x), llabs(y)) - small(llabs(x), llabs(y))) * w);
    }
    else {
        if ((llabs(x) + llabs(y)) & 1) printf("%lld", (big(llabs(x), llabs(y)) - 1) * s + w);
        else printf("%lld", big(llabs(x), llabs(y)) * s);
    }
    return 0;
}