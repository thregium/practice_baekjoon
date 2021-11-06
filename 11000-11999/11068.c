#include <stdio.h>

/*
문제 : 자연수 N(64 <= N <= 10^6)이 주어질 때, 2진법부터 64진법 사이의 수 가운데 해당 진법으로 나타내어
회문이 되는 진법이 있는지 구한다.

해결 방법 : 2진법부터 64진법까지의 각 진법으로 N을 나타내보면서 회문인 경우를 찾아나가면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : Daejeon 2015I H번
*/

int digit[32];

int main(void) {
    int t, n, l, r, r2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = 2; i <= 64; i++) {
            l = 0;
            for (int j = n; j; j /= i) {
                digit[l++] = j % i;
            }
            r2 = 1;
            for (int j = 0, k = l - 1; j <= k; j++, k--) {
                if (digit[j] != digit[k]) {
                    r2 = 0;
                    break;
                }
            }
            r |= r2;
            if (r) break;
        }
        printf("%d\n", r);
    }
    return 0;
}