#include <stdio.h>

/*
문제 : 음이 아닌 정수 N(N <= 200)의 배수를 세다가 모든 자릿수가 나오게 되는 첫 수가 몇인지 구한다.
영원히 모든 자릿수가 나오지 않는다면 INSOMNIA를 출력한다.

해결 방법 : 직접 확인해보면 1부터 10^6까지의 모든 수는 모든 자릿수가 금방 나옴을 알 수 있다.
그러므로 직접 시뮬레이션하면 된다. 그러나 0인 경우는 예외적으로 영원히 0이므로 INSOMNIA를 출력해야 한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : GCJ 2016Q A1번
*/

int chk[10];

int main(void) {
    int t, n, x;
    long long r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", tt);
            continue;
        }
        for (r = n;; r += n) {
            for (long long rt = r; rt; rt /= 10) chk[rt % 10] = 1;
            x = 1;
            for (int i = 0; i < 10; i++) {
                if (!chk[i]) {
                    x = 0;
                    break;
                }
            }
            if (x) break;
        }
        for (int i = 0; i < 10; i++) chk[i] = 0;
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}