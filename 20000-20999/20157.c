#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 점이 좌표평면상에 있을 때, (0, 0)에서 그은 반직선이 최대 몇 개의 점을 지날 수 있는 지 구한다.
단, 점은 (0, 0)을 제외한 (-10^6 <= X, Y <= 10^6)인 정수 점에 존재한다.

해결 방법 : 모든 점들을 각에 따라 정렬한 다음, 두 개의 포인터를 움직여가며 같은 각도에 있는 점의 개수를 센다.
그 중 가장 큰 것이 답이 된다.

주요 알고리즘 : 기하학, 정렬, 투 포인터

출처 : 가톨릭대 2회 F번
*/

long long balloon[103000][2];

int cmp1(const void* a, const void* b) {
    long long ax = *(long long*)a;
    long long bx = *(long long*)b;
    long long ay = *((long long*)a + 1);
    long long by = *((long long*)b + 1);
    if ((ay < 0 || (ay == 0 && ax > 0)) && (by > 0 || (by == 0 && bx < 0))) return 1;
    else if ((ay > 0 || (ay == 0 && ax < 0)) && (by < 0 || (by == 0 && bx > 0))) return -1;
    else if (ay != 0 && by == 0) return 1;
    else if (ay == 0 && by != 0) return -1;
    else return (ax * by > bx * ay) ? 1 : (ax * by == bx * ay) ? 0 : -1;
}

long long ccw(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

long long cross(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return ((bx - ax) * (cx - ax) + (by - ay) * (cy - ay));
}

int main(void) {
    int n, e = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &balloon[i][0], &balloon[i][1]);
    }
    qsort(balloon, n, sizeof(long long) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        while (e < n && ccw(0, 0, balloon[i][0], balloon[i][1], balloon[e][0], balloon[e][1]) == 0
            && cross(0, 0, balloon[i][0], balloon[i][1], balloon[e][0], balloon[e][1]) > 0) e++;
        if (e - i > r) r = e - i;
    }
    printf("%d", r);
    return 0;
}