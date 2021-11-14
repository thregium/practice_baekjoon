#include <stdio.h>

/*
문제 : 두 자연수 A, B(A, B <= 1000)가 주어질 때, A와 B를 나머지 없이 나눌 수 있는 자연수를 오름차순으로 출력한다.

해결 방법 : 1부터 1000까지 모든 수로 A와 B를 나누어 보며 둘 다 나누어 떨어지는 것을 전부 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : 한양대E 2017B F번
*/

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= 1000; i++) {
        if (a % i == 0 && b % i == 0) {
            printf("%d %d %d\n", i, a / i, b / i);
        }
    }
    return 0;
}