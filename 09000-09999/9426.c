#include <stdio.h>
#define SZ 262144

/*
문제 : 길이 N(N <= 250000)의 65535 이하 음이 아닌 정수로 이루어진 수열이 주어질 때,
이 수열의 모든 연속한 K개 값의 중앙값의 합을 구한다. K가 짝수인 경우 중앙값은 K / 2번째 값이다.

해결 방법 : 세그먼트 트리를 통해 현재 부분의 수마다 개수를 저장한다.
그리고, 매개 변수 탐색을 통해 앞의 수가 ceil(K / 2)개 이상인 가장 앞의 값을 찾으면 중앙값이므로,
이를 반복해 나가며 중앙값들을 찾아서 더해나가면 된다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 파라메트릭
*/

int a[SZ], seg[SZ * 2];

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1);
}

void upd(int a, int b) {
    seg[a + SZ] += b;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, k, lo, hi, mid;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        upd(a[i], 1);
    }
    for (int i = 0; i <= n - k; i++) {
        lo = 0, hi = 65535;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (getsum(0, mid, 0, SZ - 1, 1) >= ((k + 1) >> 1)) hi = mid;
            else lo = mid + 1;
        }
        //printf("#%d\n", lo);
        r += lo;
        upd(a[i + k], 1);
        upd(a[i], -1);
    }
    printf("%lld", r);
    return 0;
}