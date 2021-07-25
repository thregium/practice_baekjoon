#include <stdio.h>

/*
문제 : N(N <= 100000)쪽의 책을 읽는데 T분동안 1분에 S쪽의 속도로 책을 읽고 R(T, S, R <= 100)분동안 쉰다고 한다.
책을 전부 읽는데 걸리는 시간을 구한다.

해결 방법 : 책을 읽는 시간동안 직접 책 페이지를 넘겨가며 N 이상이 될 때 까지의 시간을 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2007N B2번
*/

int main(void) {
    int n, k, s, t, r, p, tr;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &s, &t, &r);
        p = 0, tr = 0;
        while (p < n) {
            for (int i = 0; i < t; i++) {
                tr++;
                p += s;
                if (p >= n) break;
            }
            if (p >= n) break;
            tr += r;
        }
        printf("%d\n", tr);
    }
    return 0;
}