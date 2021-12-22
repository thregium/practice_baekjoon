#include <stdio.h>

/*
문제 : 길이 L(L <= 10^6, 자연수)인 막대에 N(1 <= N <= 100000)마리의 개미가 왼쪽 또는 오른쪽을 보고 있다.
각 개미는 자신의 위치에서 출발해 속도 1로 움직이며 다른 개미를 만나면 반대 방향으로 같은 속도로 이동한다.
각 개미의 위치(<= L, 자연수)가 주어질 때, 모든 개미가 떨어지는 최소 시간과 최대 시간을 구한다.

해결 방법 : 전체 개미의 움직임을 시간별로 확인해보면 개미가 반사되더라도 결국 직선을 그리는 것을 알 수 있다.
따라서, 모든 개미가 떨어지는 시간은 그대로 막대의 끝까지 이동하는 시간과 같고, 최소 시간은 모든 개미가
막대의 가까운 쪽을 보고 있는 경우, 최대 시간은 모든 개미가 막대의 먼 쪽을 보고 있는 경우가 된다.
따라서, 이 가운데 최댓값을 각각 구하면 된다.

주요 알고리즘 : 애드 혹

출처 : Waterloo 20040919 B번
*/

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, l, n, x, hi, lo;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &l, &n);
        hi = 0, lo = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            lo = big(lo, small(x, l - x));
            hi = big(hi, big(x, l - x));
        }
        printf("%d %d\n", lo, hi);
    }
    return 0;
}