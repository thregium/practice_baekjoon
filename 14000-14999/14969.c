#include <stdio.h>

/*
문제 : N(N <= 1000)개의 자연수(<= 10^6) 가운데 두 자연수로 이루어진 쌍의 합이 M(2 <= M <= 2 * 10^6) 이하인 것
가운데 가장 합이 큰 것의 합을 구한다. 그러한 것이 하나도 없다면 NONE을 출력한다.

해결 방법 : 2중 for문을 통해 모든 쌍을 확인한다. 그러한 것이 없는 지 여부는 시작 값을 음수로 하면 알 수 있다.

주요 알고리즘 : 브루트 포스

출처 : JDC 2017 A번
*/

int a[1024];

int main(void) {
    int n, m, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        r = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] + a[j] <= m && a[i] + a[j] > r) r = a[i] + a[j];
            }
        }
        if (r < 0) printf("NONE\n");
        else printf("%d\n", r);
    }
    return 0;
}