#include <stdio.h>

/*
문제 : N!를 P(N, P <= 10^8)로 나눈 값을 구한다.

해결 방법 : X를 P로 나눈 수에 Y를 곱하고 다시 P를 나눈 나머지를 구하더라도 XY에서 P를 나눈 나머지를 구한 것과 같다.
따라서, 1부터 N까지 곱을 구하며 P로 나눈 나머지를 취하는 것을 반복하면 된다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int n, p;
    long long r = 1;
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
        r *= i;
        r %= p;
    }
    printf("%lld", r);
    return 0;
}