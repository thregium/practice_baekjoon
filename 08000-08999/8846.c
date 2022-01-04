#include <stdio.h>
#define MOD 500000009

/*
문제 : 높이가 A(1 <= A <= 10^6)인 전구를 가는데 필요한 사람 수를 구한다. 책상의 다리는 4개이다.

해결 방법 : 초항이 1이고 공비가 4인 등차수열의 합을 구하면 된다. ((a % m) * b) % m = (a * b) % m임을 이용하여
모듈로의 값을 구할 수 있다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int a, r = 0, x = 1;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        r = (r + x) % MOD;
        x = (x * 4) % MOD;
    }
    printf("%d", r);
    return 0;
}