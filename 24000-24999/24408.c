#include <stdio.h>

/*
문제 : N(N <= 1000)개의 자연수(<= 100)가 주어질 때, 첫 자연수의 배수가 나오면 그 수를 출력하고,
다시 이를 반복할 때, 출력해야 하는 수들을 순서대로 모두 출력한다.

해결 방법 : 첫 수가 나오는 경우에 주의하면서 문제에 나온 대로 구하면 된다.

주요 알고리즘 : 수학, 사칙연산, 구현

출처 : NAQ 2021 H번
*/

int main(void) {
    int n, x, f = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (f < 0) f = x;
        else if (x % f == 0) {
            printf("%d\n", x);
            f = -1;
        }
    }
    return 0;
}