#include <stdio.h>

/*
문제 : N - 1부터 1까지 1씩 감소하는 수열에서 전체의 절반 위치는 몇 번 째 수인 지 구한다.

해결 방법 : 매개 변수 탐색을 이용하여 앞에서부터 합이 전체의 절반 이상이 되는 첫 X를 찾으면 된다.

주요 알고리즘 : 수학, 파라메트릭?

출처 : PacNW 2017 Q번 // SEUSA 2017D2 C번
*/

long long getarithsum(long long a, long long b) {
    return ((b - a + 1) * (b + a)) >> 1;
}

int main(void) {
    long long n, s = 0, lo, hi, mid;
    scanf("%lld", &n);
    s = getarithsum(1, n - 1);
    lo = 1, hi = n - 1;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (getarithsum(n - mid, n - 1) * 2 >= s) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld", lo);
    return 0;
}