#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 집이 좌표평면에 있다. 각 집의 좌표는 20000 이하의 음이 아닌 정수이다.
이때, 두 원전의 좌표와 Q(Q <= 20000)개의 범위들이 주어지면, 각 원전의 범위가 각각
R1, R2(R1, R2 <= 13000)일 때 보호장구를 받을 수 없는 집의 수를 각각 구한다.
원전1에서 R1 이하로 떨어진 집, 원전 2에서 R2 이하로 떨어진 집에 각각 보호장구를 1개씩 준다.
그리고 보호장구가 2개인 집은 보호장구가 없는 집에 1개를 나눠줄 수 있다.

해결 방법 : 각 집의 위치들을 하나는 원전1, 다른 하나는 원전 2와의 거리를 기준으로 하여 정렬한다.
그 후, 쿼리가 들어올 때 마다 두 원전의 범위 안에 있는 집의 개수를 이분 탐색을 통해 세준다.
보호장구를 받을 수 없는 집의 수는 전체 집의 수 - (원전 1에서 범위 안에 있는 집의 수) -
(원전 2에서 범위 안에 있는 집의 수)이고, 이 값이 음수인 경우에는 0이다.

주요 알고리즘 : 기하학, 정렬, 이분 탐색

출처 : Hatyai 2012 A번
*/

typedef struct point {
    long long x, y;
} point;

point house[204800], distp1[204800], distp2[204800];
point npp1, npp2, comparing;

long long getdist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int cmp1(const void* a, const void* b) {
    long long ai = getdist(*(point*)a, comparing);
    long long bi = getdist(*(point*)b, comparing);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getcount(point* arr, int n, int d) {
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (getdist(arr[mid - 1], comparing) <= d) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main(void) {
    int n, q, r1, r2, res;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &house[i].x, &house[i].y);
            distp1[i] = house[i];
            distp2[i] = house[i];
        }
        scanf("%lld %lld %lld %lld", &npp1.x, &npp1.y, &npp2.x, &npp2.y);
        comparing = npp1;
        qsort(distp1, n, sizeof(point), cmp1);
        comparing = npp2;
        qsort(distp2, n, sizeof(point), cmp1);
        scanf("%d", &q);
        printf("Case %d:\n", tt);
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &r1, &r2);
            comparing = npp1;
            res = getcount(distp1, n, r1 * r1);
            comparing = npp2;
            res += getcount(distp2, n, r2 * r2);
            if (res > n) printf("0\n");
            else printf("%d\n", n - res);
        }
    }
    return 0;
}