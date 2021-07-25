#include <stdio.h>

/*
문제 : A * C 이상인 자연수 가운데 [A, B]중 한 자연수 * [C, D]중 한 자연수가 아닌 가장 작은 수를 찾는다. (A, B, C, D <= 10^6)

해결 방법 : 만약 어떠한 수가 소수인 경우 곱해서 그 수가 되는 경우는 1 * 그 수일 때 뿐이다.
따라서, (B와 D, A * C보다 모두 큰 가장 작은 소수) 보다는 반드시 답이 작을 것이다. 그런데, 10^12 범위까지 소수는
10000 이상동안 나오지 않는 경우는 없으므로 AC + 101만까지 곱해지는 수인지 찾은 후, 가장 작은 곱해지지 않는 수를 구하면 된다.

주요 알고리즘 : 수학, 정수론, 브루트 포스

출처 : ROI 2006H H번
*/

char chk[1048576];

int main(void) {
    long long a, b, c, d, ac, di;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    ac = a * c;
    for (long long i = a; i <= b; i++) {
        di = d * i;
        for (long long j = i * c; j < ac + 1048576 && j <= di; j += i) {
            chk[j - ac] = 1;
        }
    }
    for (int i = 0;; i++) {
        if (!chk[i]) {
            printf("%lld", i + ac);
            break;
        }
    }
    return 0;
}