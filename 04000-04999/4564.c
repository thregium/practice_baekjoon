#include <stdio.h>

/*
문제 : 100000 이하의 자연수 S가 주어질 때, 이 수의 모든 자릿수의 곱으로 바꾸는 것을 반복하는 방식으로 한 자리 수가 될 때 까지
반복할 때, 그 과정을 출력한다.

해결 방법 : 항상 다음 수는 이전 수의 9/10 이하가 된다.(전부 9인 경우가 최대이기 때문) 따라서, 이를 그대로 반복하며
10보다 작아질 때 까지 반복하면 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : MidC 2012 B번
*/

int main(void) {
    int s, u;
    while (1) {
        scanf("%d", &s);
        if (s == 0) break;
        for (int t = s;;) {
            printf("%d ", t);
            if (t < 10) break;
            u = 1;
            for (int v = t; v; v /= 10) u *= v % 10;
            t = u;
        }
        printf("\n");
    }
    return 0;
}