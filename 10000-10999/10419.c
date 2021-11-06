#include <stdio.h>

/*
문제 : D(D <= 10000)가 주어질 때, t + t^2이 D 이하가 되는 가장 큰 t를 구한다. 이를 T(T <= 100)회 반복한다.

해결 방법 : 0부터 수를 늘려가며 t + t^2이 D보다 커질 때의 값을 구하고, 그 값에서 1을 빼면 답이 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : 서강대 2014M A번
*/

int main(void) {
    int t, d, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &d);
        for (r = 0; r * (r + 1) <= d; r++);
        printf("%d\n", r - 1);
    }
    return 0;
}