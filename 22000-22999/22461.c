#include <stdio.h>

/*
문제 : 음이 아닌 정수 N(N <= 10^6)이 주어질 때, 한 자리 수가 되기까지 다음 연산을 몇 번 해야 하는지 구한다.
N을 두 부분으로 자른 다음 나올 수 있는 서로의 곱 가운데 가장 큰 것을 다음 N으로 한다.

해결 방법 : 다음 N은 커봐야 현재 N의 0.9배이므로 빠르게 N이 줄어들게 된다. 이를 이용해 연산을 시뮬레이션 하고
그 반복 횟수를 구하면 된다.

주요 알고리즘 : 수학, 시뮬레이션

출처 : JAG 2012S2 A번
*/

int main(void) {
    int t, n, m, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0;; i++) {
            if (n < 10) {
                printf("%d\n", i);
                break;
            }
            b = 0, m = 0;
            for (int j = 1; n; j *= 10) {
                m += j * (n % 10);
                n /= 10;
                if (n * m > b) b = n * m;
            }
            n = b;
        }
    }
    return 0;
}