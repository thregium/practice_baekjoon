#include <stdio.h>

/*
문제 : L과 U (L, U <= 10^8, U - L <= 1000) 사이의 수 가운데 가장 약수가 많은 수의 약수 갯수를 구한다.

해결 방법 : 한 수가 어떠한 수의 약수인 경우 나누는 수를 나눈 몫도 그 수의 약수이다.
그러므로, 한 번 셀 때 2개씩 센다면 sqrt(N)까지만 세더라도 그 수의 약수의 갯수를 알 수 있다.
단, 그 수의 제곱근이 약수인 경우, 중복으로 세어지게 되므로, 그러한 경우 1을 빼야 한다.

주요 알고리즘 : 수학, 정수론

출처 : AIPO 2015P 6번
*/

int main(void) {
    int c, l, u, b, d;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &l, &u);
        b = 0;
        for (int j = l; j <= u; j++) {
            d = 0;
            for (int k = 1; k * k <= j; k++) {
                if (j % k == 0) {
                    d += 2;
                    if (k * k == j) d--;
                }
            }
            if (d > b) b = d;
        }
        printf("%d\n", b);
    }
    return 0;
}