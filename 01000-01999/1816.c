#include <stdio.h>

/*
문제 : 자연수 S(10^12 <= S <= 10^18)에 대해 모든 소인수가 10^6 이상인지 구한다.

해결 방법 : 2 이상 10^6 이하의 모든 수에 대해 나누어 떨어지는지 확인한다. 하나라도 나누어 떨어진다면 10^6 이하의
소인수가 있는 것이고, 나누어 떨어지지 않는다면 10^6 이하의 소인수가 없는 것이다.

주요 알고리즘 : 브루트 포스
*/

int main(void) {
    int n, r;
    long long s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s);
        r = 1;
        for (int j = 2; j <= 1000000; j++) {
            if (s % j == 0) {
                r = 0;
                break;
            }
        }
        printf("%s\n", r ? "YES" : "NO");
    }
    return 0;
}