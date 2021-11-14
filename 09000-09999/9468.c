#include <stdio.h>

/*
문제 : 15개의 음이 아닌 정수로 이루어진 배열에서 섬의 개수를 구한다. 인접한 수의 차이는 최대 1이다.

해결 방법 : 이전 값과 달라지는 수의 개수를 구한 다음 2로 나누면 된다.

주요 알고리즘 : 구현

출처 : GNY 2013 A번
*/

int main(void) {
    int p, k, r, l, x;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d", &k);
        r = 0;
        scanf("%d", &l);
        for (int i = 1; i < 15; i++) {
            scanf("%d", &x);
            if (x != l) r++;
            l = x;
        }
        if (r & 1) return 1;
        printf("%d %d\n", k, r >> 1);
    }
    return 0;
}