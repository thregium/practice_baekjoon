#include <stdio.h>

/*
문제 : 가장 작은 N(N <= 10000)개의 자연수, 홀수 자연수, 짝수 자연수의 합을 각각 구한다.

해결 방법 : 각각 N개의 자연수, 홀수, 짝수를 찾아서 다한 다음 결과를 출력하면 된다.

주요 알고리즘 : 수학, 구현

출처 : GNY 2015 A번
*/

int main(void) {
    int p, k, n, r1, r2, r3;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d %d", &k, &n);
        r1 = 0, r2 = 0, r3 = 0;
        for (int i = 1; i <= n; i++) {
            r1 += i;
            r2 += i * 2 - 1;
            r3 += i * 2;
        }
        printf("%d %d %d %d\n", k, r1, r2, r3);
    }
    return 0;
}