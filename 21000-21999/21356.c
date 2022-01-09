#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^9)을 가장 적은 1로만 이루어진 자연수의 합으로 표현할 때, 표현하는 수의 개수를 구한다.

해결 방법 : 가능한 가장 큰 수부터 차례로 더해나가면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : SwOI 2021Q C번
*/

int unit[9] = { 111111111, 11111111, 1111111, 111111, 11111, 1111, 111, 11, 1 };

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    while (n) {
        for (int i = 0; i < 9; i++) {
            if (unit[i] <= n) {
                r++;
                n -= unit[i];
                break;
            }
        }
    }
    printf("%d", r);
    return 0;
}