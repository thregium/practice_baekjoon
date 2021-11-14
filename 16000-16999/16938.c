#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 15)개의 자연수(<= 10^6)가 주어질 때, 선택한 자연수의 합이 L 이상 R 이하면서 선택한 가장 큰 자연수와
가장 작은 자연수의 차이가 X 이상이 되도록 선택하는 방법의 가짓수를 구한다.

해결 방법 : N이 매우 작으므로 비트마스킹을 통해 각 문제를 선택하는 방법과 선택하지 않는 방법을 모두 해보면서
조건을 만족하는 경우를 모두 찾아나가면 된다.

주요 알고리즘 : 브루트 포스, 비트마스킹
*/

int a[16];

int main(void) {
    int n, l, r, x, res = 0, s, lo, hi;
    scanf("%d %d %d %d", &n, &l, &r, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        s = 0, lo = INF, hi = -1;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) continue;
            s += a[j];
            if (a[j] < lo) lo = a[j];
            if (a[j] > hi) hi = a[j];
        }
        if (s >= l && s <= r && hi - lo >= x) res++;
    }
    printf("%d", res);
    return 0;
}