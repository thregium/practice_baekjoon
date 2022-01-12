#include <stdio.h>

/*
문제 : 초항이 A(A <= 9307)이고 공차가 D(D <= 346)인 등차수열에서 N(N <= 210)번째로 나오는 소수를 구한다.
답은 10^6 이하의 자연수 범위에 있다.

해결 방법 : 답이 10^6 이내의 범위에 있기 때문에 O(sqrt(N)) 시간정도 범위 내에 소수 판정이 가능하다면
답을 시간 내에 구할 수 있다. 이는 2부터 sqrt(N)까지 각각 나누어 보고 나누어 떨어지는 지 확인하는 것으로 판정 가능하다.
단, 0과 1일 때에 유의한다.

주요 알고리즘 : 수학, 소수 판정, 브루트 포스

출처 : JDC 2006 A번
*/

int isprime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int a, d, n;
    while (1) {
        scanf("%d %d %d", &a, &d, &n);
        if (n == 0) break;
        while (n) {
            if (isprime(a)) n--;
            if (!n) break;
            a += d;
        }
        printf("%d\n", a);
    }
    return 0;
}