#include <stdio.h>

/*
문제 : 두 달력이 있다. 두 달력의 총 날 수는 같으며, 달 수는 각각 N, M(N, M <= 10^6)이다.
또한, 각 달의 날 수는 최대 1000일이다.
이때, Z(Z <= 100000)개의 쿼리에 응답한다. 각 쿼리는 월과 일, 'A' 또는 'B'가 주어질 때,
해당 달력의 날을 다른 달력으로 바꾸는 것이다.

해결 방법 : 각 달력의 달마다 날짜를 누적한 값을 계산한다. 그 이후 쿼리가 주어질 때 마다,
그 값을 바탕으로 해당 연도의 날 수를 계산한 다음, 반대쪽 배열에서 이분 탐색을 통해
반대쪽 달력의 날로 빠르게 변환하면 된다.

주요 알고리즘 : 누적 합, 이분 탐색

출처 : JPOI 2009 2-2번
*/

int a[1048576], b[1048576];

int main(void) {
    int n, m, z, di, mi, dt, lo, hi, mid;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        b[i] += b[i - 1];
    }

    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        scanf("%d %d %c", &di, &mi, &c);
        if (c == 'A') {
            dt = a[mi - 1] + di;
            lo = 0, hi = m - 1;
            while (lo < hi) {
                mid = (lo + hi + 1) >> 1;
                if (b[mid] < dt) lo = mid;
                else hi = mid - 1;
            }
            printf("%d %d\n", dt - b[lo], lo + 1);
        }
        else {
            dt = b[mi - 1] + di;
            lo = 0, hi = n - 1;
            while (lo < hi) {
                mid = (lo + hi + 1) >> 1;
                if (a[mid] < dt) lo = mid;
                else hi = mid - 1;
            }
            printf("%d %d\n", dt - a[lo], lo + 1);
        }
    }
    return 0;
}