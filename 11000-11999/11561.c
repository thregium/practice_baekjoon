#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^16)이 주어질 때, 징검다리를 이전에 건넌 칸수에서 칸수를 늘려가며 건너며
밟을 수 있는 최대 돌 수를 구한다.

해결 방법 : 매개 변수 탐색을 이용하여 1부터 M까지의 합이 N을 넘지 않는 가장 큰 M을 구하면 된다.

주요 알고리즘 : 수학, 파라메트릭

출처 : 연세대 2015 E번
*/

int main(void) {
    int t;
    long long n, l, h, m;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld", &n);
        l = 1, h = 1012345678;
        while (l < h) {
            m = (l + h + 1) >> 1;
            if (m * (m + 1) <= 2 * n) l = m;
            else h = m - 1;
        }
        printf("%lld\n", l);
    }
    return 0;
}