#include <stdio.h>

/*
문제 : 자연수 N(3 <= N <= 10^9)이 주어질 때, N보다 작은 자연수 가운데 N을 나누어 떨어지지 않게 하는
가장 작은 수와 가장 큰 수를 구한다.

해결 방법 : N의 약수는 많지 않기 때문에 1부터 올라가며, N부터 내려가며 나누어 떨어지지 않는
첫 수를 찾더라도 항상 시간 내에 약수가 아닌 수를 빠르게 찾을 수 있다.

주요 알고리즘 : 수학, 정수론?

출처 : ILOCAMP 2010B 0번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        if (n % i) {
            printf("%d ", i);
            break;
        }
    }
    for (int i = n - 1; i > 1; i--) {
        if (n % i) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}