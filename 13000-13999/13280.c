#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 음이 아닌 정수(<= 10^6)로 이루어진 배열이 주어질 때, 배열의 두 값 가운데
서로 가장 차이가 적은 쌍의 차이를 구한다.

해결 방법 : 2중 for문으로 모든 값 쌍 가운데 가장 차이가 적은 것을 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : JDC 2016 A번
*/

int a[1024];

int main(void) {
    int n, best;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        best = 1048576;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(a[i] - a[j]) < best) best = abs(a[i] - a[j]);
            }
        }
        printf("%d\n", best);
    }
    return 0;
}