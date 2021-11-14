#include <stdio.h>

/*
문제 : N(N <= 10^9)이 주어질 때, 이 수가 소수의 거듭제곱인지 구한다.

해결 방법 : 1부터 sqrt(N)까지 확인하면서 나누어 떨어지는 수가 나오자 마자 1까지 떨어지는지 확인한다.
1까지 떨어지면 소수의 거듭제곱이고, 그 외에는 아니다.

주요 알고리즘 : 수학, 정수론, 소수 판정

출처 : BAPC 2016 I번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("no");
        return 0;
    }
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            if (n == 1) {
                printf("yes");
                return 0;
            }
            else {
                printf("no");
                return 0;
            }
        }
    }
    printf("yes");
    return 0;
}
