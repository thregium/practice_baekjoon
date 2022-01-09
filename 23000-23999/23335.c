#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^6)이 주어질 때, 이 수가 완전수인지, 부족수인지, 과잉수인지 구한다.
이를 T(T <= 10^6)번 반복한다.

해결 방법 : 에라토스테네스의 체를 응용하여 각 수마다 진약수의 합을 구한다. 그 후 자연수가 들어올 때 마다,
진약수의 합과 비교해 완전수, 부족수, 과잉수 여부를 각각 판정하면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스

출처 : TOPC 2021 B번
*/

int s[1048576];

int main(void) {
    int t, n;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i * 2; j <= 1000000; j += i) s[j] += i;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (s[n] == n) printf("perfect\n");
        else if (s[n] > n) printf("abundant\n");
        else printf("deficient\n");
    }
    return 0;
}