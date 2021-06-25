#include <stdio.h>

/*
문제 : A, B(A, B <= 1000)의 최소공배수와 최대공약수를 각각 구한다.

해결 방법 : A와 B의 크기가 충분히 작으므로 최소공배수는 A의 배수를 하나씩 살펴보며 확인하고
최대공약수는 A 이하의 값들에 대해 하나씩 살펴보더라도 시간 내에 돌아가는 것이 가능하다.

주요 알고리즘 : 수학, 브루트 포스
*/

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        for (int i = a; i <= a * b; i += a) {
            if (i % b == 0) {
                printf("%d ", i);
                break;
            }
        }
        for (int i = a; i >= 1; i--) {
            if (a % i == 0 && b % i == 0) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}