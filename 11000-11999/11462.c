#include <stdio.h>
#include <stdlib.h>

/*
문제 : 자연수 N(N <= 100000)이 주어질 때, N보다 작으면서 자릿수의 합이 N의 자릿수 합보다 1 작은
수 가운데 가장 큰 것을 찾는다.

해결 방법 : N의 범위가 작으므로 N - 1부터 0까지 하나씩 확인하며 자릿수 합이 N의 자릿수 합 - 1이 되는
첫 수를 찾으면 된다.

주요 알고리즘 : 브루트 포스

출처 : CTU 2015 O번
*/

char s[16];

int getdigitsum(int x) {
    int r = 0;
    while (x) {
        r += x % 10;
        x /= 10;
    }
    return r;
}

int main(void) {
    int n, sum;
    while (1) {
        scanf("%s", s);
        if (s[0] == 'E') break;
        n = strtoll(s, NULL, 10);
        sum = getdigitsum(n);
        for (int i = n - 1;; i--) {
            if (i < 0) return 1;
            if (getdigitsum(i) == sum - 1) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}