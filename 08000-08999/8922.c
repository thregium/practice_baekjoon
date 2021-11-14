#include <stdio.h>
#include <stdlib.h>

/*
문제 : 주어진 길이 N(N <= 15)의 수열에 대해 인접한 수의 차를 담은 쌍을 새로운 수열로 하는 연산을 반복하면
모든 수가 0이 되거나 일정한 패턴이 반복된다고 한다. 주어진 수열은 어느 쪽이 되는지 구한다.
단, 주어지는 모든 수열은 1000회 안에 둘 중 하나로 수렴한다.

해결 방법 : 1000회동안 해당 연산을 반복한 다음 모든 수가 0인지 확인한다. 0이 된다면 모든 수가 0일 것이다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Seoul 2009 A번
*/

int a[16];

int main(void) {
    int t, n, x;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < 1030; i++) {
            x = a[0];
            for (int j = 0; j < n - 1; j++) {
                a[j] = abs(a[j] - a[j + 1]);
            }
            a[n - 1] = abs(a[n - 1] - x);
        }
        x = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) x = 0;
        }
        printf("%s\n", x ? "ZERO" : "LOOP");
    }
    return 0;
}