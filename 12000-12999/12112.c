#include <stdio.h>
#include <stdlib.h>

/*
문제 : [A, B](A <= B <= 10^7) 범위의 수에 대한 각 수와 진약수의 차의 합을 구한다.

해결 방법 : 1부터 B까지의 자연수에 대해 그 수의 배수들에 대해 진약수의 합을 더한다.
그 다음 A부터 B까지 확인해 나가면서 진약수의 합과 각 수의 절댓값 차이를 구해서 더해나가면 답이 된다.

주요 알고리즘 : 수학, 정수론, 체

출처 : COCI 16/17#6 4번
*/

int sieve[10485760];

int main(void) {
    int a, b;
    long long res = 0;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= b; i++) {
        for (int j = i * 2; j <= b; j += i) sieve[j] += i;
    }
    for (int i = a; i <= b; i++) {
        res += abs(sieve[i] - i);
    }
    printf("%lld", res);
    return 0;
}