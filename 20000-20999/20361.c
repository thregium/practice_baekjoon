#include <stdio.h>

/*
문제 : N개의 컵 중 X번째 컵에 공을 넣고 K(K <= 100000)회 컵을 움직였다. 컵을 움직인 순서가 주어질 때,
마지막에 공이 든 컵을 구한다.

해결 방법 : 컵을 움직일 때 마다 공을 따라가며 마지막에 공이 있는 곳을 찾으면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 인천대 2020 A번
*/

int main(void) {
    int n, x, k, a, b;
    scanf("%d %d %d", &n, &x, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        if (x == a) x = b;
        else if (x == b)  x = a;
    }
    printf("%d", x);
    return 0;
}