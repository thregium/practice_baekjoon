#include <stdio.h>

/*
문제 : 자연수 A, B(A, B <= 10^9)가 주어질 때, A의 모든 약수가 B의 모든 약수에 포함되는지 여부를 구한다.
이를 Z(Z <= 10^6)번 반복한다.

해결 방법 : B가 A로 나누어 떨어지는 경우 조건을 만족한다. 반복문을 통해 조건을 만족하는지 계속 확인하면 된다.

주요 알고리즘 : 수학, 정수론

출처 : ILOCAMP 2011B 5-4번
*/

int main(void) {
    int z, a, b;
    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        scanf("%d %d", &a, &b);
        if (b % a == 0) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}