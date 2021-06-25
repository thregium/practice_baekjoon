#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
문제 : 수직선상에 M(M <= 100000)개의 점이 있고, 좌표평면 상에 N(N <= 100000)개의 점이 있다. 좌표평면의 점 가운데
하나 이상의 수직선상의 점과 거리가 L(L <= 10^9) 이하인 것의 개수를 구한다. 단, 모든 좌표는 10^9 이하의 자연수이다.

해결 방법 : 수직선과 좌표평면상의 점들을 X축을 기준으로 정렬한 후 좌표평면상의 점에서 X좌표 기준 양쪽에 있는 점들의 좌표를
비교해서 둘 중 거리가 더 작은 것의 거리가 L 이하인 것을 세면 된다.

주요 알고리즘 : 정렬, 스위핑

출처 : 정올 2013 중1/고1번
*/

int sa[103000], ani[103000][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getdist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(void) {
    int m, n, l, dist, p = 0, r = 0;
    scanf("%d %d %d", &m, &n, &l);
    for (int i = 0; i < m; i++) {
        scanf("%d", &sa[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &ani[i][0]);
        scanf("%d", &ani[i][1]);
    }
    qsort(sa, m, sizeof(int), cmp1);
    qsort(ani, n, sizeof(int) * 2, cmp1);
    sa[m] = 1012345678;
    for (int i = 0; i < n; i++) {
        while (ani[i][0] > sa[p]) p++;
        if (p == 0) dist = getdist(ani[i][0], ani[i][1], sa[p], 0);
        else if (p == m) dist = getdist(ani[i][0], ani[i][1], sa[p - 1], 0);
        else dist = small(getdist(ani[i][0], ani[i][1], sa[p - 1], 0), getdist(ani[i][0], ani[i][1], sa[p], 0));
        if (dist <= l) r++;
    }
    printf("%d", r);
    return 0;
}
