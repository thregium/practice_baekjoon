#include <stdio.h>

/*
문제 : 허리와 목의 높이가 주어지고, P(P <= 100)개의 펀치의 높이가 주어질 때, 허리와 목 사이에 들어간 펀치의 수를 구한다.

해결 방법 : 각 펀치마다 허리 높이 이상이며 목 높이 이하인지 확인하고 맞다면 그러한 펀치들을 세면 된다.

주요 알고리즘 : 구현

출처 : Latin 2014 PA번
*/

int main(void) {
    int w, n, p, x, r = 0;
    scanf("%d %d %d", &w, &n, &p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &x);
        if (x >= w && x <= n) r++;
    }
    printf("%d", r);
    return 0;
}