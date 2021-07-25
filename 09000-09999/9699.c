#include <stdio.h>

/*
문제 : 주어진 자연수 5개 중 최댓값을 찾는다.

해결 방법 : 최댓값을 0으로 맞춘 후, 최댓값보다 큰 수가 나오면 최댓값을 갱신시켜 찾으면 된다.

주요 알고리즘 : 구현

출처 : Khawa 2013 G번
*/

int main(void) {
    int t, x, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        r = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &x);
            if (x > r) r = x;
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}