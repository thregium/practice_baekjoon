#include <stdio.h>

/*
문제 : N(N <= 10000)개의 콘도가 있을 때, 상위호환(바다까지의 거리가 더 가깝거나 같고, 값이 더 싸거나 같은 곳)이
없는 콘도의 개수를 구한다.

해결 방법 : N이 약간 크기는 하지만 모든 쌍을 비교하면서 상위호환 여부를 체크하더라도 시간 내에 풀 수 있다.

주요 알고리즘 : 브루트 포스

출처 : Beijing 2005 E번
*/

int condo[10240][2];

int main(void) {
    int n, ok, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &condo[i][0], &condo[i][1]);
    }
    for (int i = 0; i < n; i++) {
        ok = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if ((condo[j][0] <= condo[i][0] && condo[j][1] <= condo[i][1])) {
                ok = 0;
                break;
            }
        }
        r += ok;
    }
    printf("%d", r);
    return 0;
}