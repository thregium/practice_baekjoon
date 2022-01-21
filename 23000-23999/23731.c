#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^15)이 주어질 때, N을 뒤에서부터 반올림한 수 가운데 가장 큰 것을 구한다.

해결 방법 : 뒤에서부터 자리마다 반올림하며 가장 큰 값을 찾아나가면 된다.
반올림을 반복하면 반드시 0이 되기 때문에 0이 될 때 까지 반복할 수 있다.

주요 알고리즘 : 수학, 그리디 알고리즘

출처 : UNIST 3회 B번
*/

int main(void) {
    long long n, r = 0;
    scanf("%lld", &n);
    r = n;
    for (long long i = 10; n; i *= 10) {
        if (n % i >= i / 2) n += i - n % i;
        else n -= n % i;
        if (n > r) r = n;
    }
    printf("%lld\n", r);
    return 0;
}