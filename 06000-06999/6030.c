#include <stdio.h>

/*
문제 : 각각 P, Q(P, Q <= 6000)의 약수가 되는 자연수의 순서쌍을 차례로 전부 구한다.

해결 방법 : 모든 P와 Q에 대해 확인하다가 각각의 약수가 아니라면 넘어가고, 약수라면 해당 순서쌍을 출력한다.

주요 알고리즘 : 브루트 포스, 정수론

출처 : USACO 2010F B1번
*/

int main(void) {
    int p, q;
    scanf("%d %d", &p, &q);
    for (int i = 1; i <= p; i++) {
        if (p % i) continue;
        for (int j = 1; j <= q; j++) {
            if (q % j) continue;
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}