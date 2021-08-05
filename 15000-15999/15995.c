#include <stdio.h>

/*
문제 : (A * X) % M == 1(A, M <= 10000)이 성립하는 가장 작은 양의 X를 구한다.
단, A와 M은 서로소이다.

해결 방법 : A와 M이 서로서이므로 가장 X는 크더라도 10000 이하이다. 따라서, 1부터 차례로 확인하며 가장 작은 X를 구하면 된다. 

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int a, m;
    scanf("%d %d", &a, &m);
    for (int i = 1;; i++) {
        if ((i * a) % m == 1) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}