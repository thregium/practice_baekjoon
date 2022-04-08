#include <stdio.h>

/*
문제 : 길이 N(N <= 10^6)의 선형 동차법으로 생성된 수열에서 이분 탐색을 통해 찾을 수 있는 수의 개수를 구한다.
모든 수열의 변수는 2^31보다 작은 음이 아닌 정수이다.

해결 방법 : 수열을 직접 만들어낸 다음, 이분 탐색을 통해 찾을 수 있는 지
여부를 확인하며 수의 개수를 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 이분 탐색

출처 : ECNA 2019 G번
*/

long long x[1048576];

int main(void) {
    long long n, m, a, c, res = 0, lo, mid, hi;
    scanf("%lld %lld %lld %lld", &n, &m, &a, &c);
    scanf("%lld", &x[0]);
    for (int i = 1; i <= n; i++) {
        x[i] = (x[i - 1] * a + c) % m;
    }
    for (int i = 1; i <= n; i++) {
        lo = 1, hi = n;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            if (x[mid] == x[i]) {
                res++;
                break;
            }
            else if (x[mid] < x[i]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    printf("%lld", res);
    return 0;
}