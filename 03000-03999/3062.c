#include <stdio.h>

/*
문제 : 주어진 수 N(N <= 100000)과 N을 뒤집은 수의 합이 대칭수인지 확인한다.

해결 방법 : N을 뒤집은 수를 찾은 다음 N과 더한다. 이 값이 대칭수인지 다시 확인해본다.
N이 비교적 작으므로 케이스 워크를 해도 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : Seoul 2003I A번
*/

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n >= 100000) r = 1;
        else if (n >= 10000) r = n / 10000 + n / 1000 % 10 * 10 + n / 100 % 10 * 100 + n / 10 % 10 * 1000 + n % 10 * 10000;
        else if (n >= 1000) r = n / 1000 + n / 100 % 10 * 10 + n / 10 % 10 * 100 + n % 10 * 1000;
        else if (n >= 100) r = n / 100 + n / 10 % 10 * 10 + n % 10 * 100;
        else r = n / 10 + n % 10 * 10;
        r += n;
        if (r >= 100000) {
            if (r / 100000 == r % 10 && r / 10000 % 10 == r / 10 % 10 && r / 1000 % 10 == r / 100 % 10) printf("YES\n");
            else printf("NO\n");
        }
        else if (r >= 10000) {
            if (r / 10000 == r % 10 && r / 1000 % 10 == r / 10 % 10) printf("YES\n");
            else printf("NO\n");
        }
        else if (r >= 1000) {
            if (r / 1000 == r % 10 && r / 100 % 10 == r / 10 % 10) printf("YES\n");
            else printf("NO\n");
        }
        else if (r >= 100) {
            if (r / 100 == r % 10) printf("YES\n");
            else printf("NO\n");
        }
        else {
            if (r / 10 == r % 10) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}