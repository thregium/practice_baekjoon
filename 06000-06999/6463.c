#include <stdio.h>

/*
문제 : 10000 이하의 자연수 N이 주어질 때, N!의 0이 아닌 마지막 수를 구한다.

해결 방법 : N!에서 0이 아닌 뒤의 6자리(5^6 > 10000이므로) 수만 저장하며 계산해나가면 된다.

주요 알고리즘 : 수학, 정수론

출처 : SCNA 1997 4번
*/

int main(void) {
    int n;
    long long l;
    while (scanf("%d", &n) != EOF) {
        l = 1;
        for (int i = 1; i <= n; i++) {
            l *= i;
            while (l % 10 == 0) l /= 10;
            l %= 100000000;
        }
        printf("%5d -> %lld\n", n, l % 10);
    }
    return 0;
}