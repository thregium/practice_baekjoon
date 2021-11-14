#include <stdio.h>

/*
문제 : 주어진 모듈로 M(M <= 10^6)에 대한 피사노 주기를 구한다. 각 피사노 주기는 500000 이하에서 답이 나온다.

해결 방법 : 피보나치 수의 M 모듈로를 구하며 최근 2개의 값이 1로 나올 때 까지 반복한다.
최근 2개의 값이 1이라면 그 값 - 2가 피사노 주기이다.

주요 알고리즘 : 수학, 정수론, DP

출처 : GNY 2013 D번
*/

int fibo[524288];

int main(void) {
    int p, n, m;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d %d", &n, &m);
        fibo[1] = 1, fibo[2] = 1;
        for (int i = 3;; i++) {
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % m;
            if (fibo[i] == 1 && fibo[i - 1] == 1) {
                printf("%d %d\n", n, i - 2);
                break;
            }
        }
    }
    return 0;
}