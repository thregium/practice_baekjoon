#include <stdio.h>

/*
문제 : T(T < 1000)개의 정수에 대해 N(N < 10000)이 완전수인지 부족수인지 과잉수인지 구한다.

해결 방법 : 1부터 N - 1까지의 모든 수에 대해 N의 약수인지 확인하며 N의 진약수의 합을 구한 다음 종류를 판별하면 된다.

주요 알고리즘 : 수학, 정수론, 브루트 포스

출처 : 중앙대 2017 C번
*/

int main(void) {
    int t, n, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        s = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) s += i;
        }
        if (s < n) printf("Deficient\n");
        else if (s == n) printf("Perfect\n");
        else printf("Abundant\n");
    }
    return 0;
}