#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^6)에 대해 합이 N이고 각각은 N의 약수인 세 자연수가 있는지 확인하고 있다면 그 자연수들 중
가장 곱이 큰 것을 구한다.

해결 방법 : 자연수 N을 합이 N이고 각각이 N의 약수인 세 자연수로 나타내는 방법은 단 두 가지 뿐이다.
세 수가 모두 N / 3이거나 한 수는 N / 2, 나머지 두 수는 N / 4인 경우이다. 전자는 N이 3의 배수여야 하고,
후자는 N이 4의 배수여야 한다. 따라서, 둘 다 아닌 경우 나타낼 수 없다. 또한, 둘 다 해당하는 경우에는
전자가 곱이 가장 크므로 전자를 적용하면 된다.

주요 알고리즘 : 수학, 애드 혹

출처 : Petro 2018S4 A번
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n % 3 == 0) printf("%lld\n", (long long)n * n * n / 27);
        else if ((n & 3) == 0) printf("%lld\n", (((long long)n * n * n) >> 5));
        else printf("-1\n");
    }
    return 0;
}