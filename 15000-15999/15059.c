#include <stdio.h>

/*
문제 : 3가지 메뉴의 재고와 필요량이 주어진다. 부족한 메뉴가 총 몇 인분인지 구한다.

해결 방법 : 재고량보다 필요량이 많은 경우 필요량과 재고의 차만큼을 결괏값에 더한다. 이를 3번 하면 그 값이 부족한 양이다.

주요 알고리즘 : 구현

출처 : Latin 2017 H번
*/

int main(void) {
    int ca, ba, pa, cr, br, pr, res = 0;
    scanf("%d %d %d%d %d %d", &ca, &ba, &pa, &cr, &br, &pr);
    if (cr > ca) res += cr - ca;
    if (br > ba) res += br - ba;
    if (pr > pa) res += pr - pa;
    printf("%d", res);
    return 0;
}