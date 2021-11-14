#include <stdio.h>

/*
문제 : 두 수 X와 K(X, K <= 10^9)가 주어질 때, X OR Y = X + Y가 되는 K번째로 작은 자연수 Y를 구한다.

해결 방법 : 조건을 만족하기 위해서는 X와 Y가 이루는 비트가 전부 달라야 한다.
따라서, K를 이진수로 만들되 X의 비트가 0인 비트에 적용하면 답이 된다.

주요 알고리즘 : 수학

출처 : SRM 430 D1A / D2B
*/

int main(void) {
    long long x, y, z = 0, p = 0;
    scanf("%lld %lld", &x, &y);
    for (int i = y; i; i >>= 1) {
        while ((x >> p) & 1) p++;
        if (i & 1) z += (1LL << p);
        p++;
    }
    printf("%lld", z);
    return 0;
}