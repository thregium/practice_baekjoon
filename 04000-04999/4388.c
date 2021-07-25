#include <stdio.h>

/*
문제 : 두 자연수 A, B(A, B <= 10^10)가 주어진다. 이때, 두 수를 더할 때의 받아올림 횟수를 구한다.

해결 방법 : 두 수의 마지막 자리부터 확인하며 자릿수의 합 + 받아올림이 10 이상인지 확인한 후 이러한 것의 수를 세면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : Waterloo 2000S23 C번
*/

int main(void) {
    long long a, b;
    int c, r;
    while (1) {
        scanf("%lld %lld", &a, &b);
        if (a == 0 && b == 0) break;
        c = 0, r = 0;
        for (long long i = a, j = b; i || j; i /= 10, j /= 10) {
            if (c + i % 10 + j % 10 >= 10) {
                c = 1;
                r++;
            }
            else c = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}