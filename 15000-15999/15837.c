#include <stdio.h>

/*
문제 : 

해결 방법 : 식을 전개하면 N^2 이하 제곱수의 합의 제곱이 된다. 이 값을 계산하면 답이 된다.

주요 알고리즘 : 수학

출처 : Khwarizmi 2018 F번
*/

int main(void) {
    int t, n;
    long long res;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        res = n * (n + 1LL) * (n + 2LL);
        res /= 6;
        res *= res;
        printf("%lld\n", res);
    }
    return 0;
}