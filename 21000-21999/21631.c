#include <stdio.h>

/*
문제 : 흰색과 검정색 블록의 개수가 각각 주어질 때, 이들을 임의의 순서로 일렬로 이어서 나올 수 있는 검은색 부분의 최대 개수를 구한다.

해결 방법 : 흰색 블록이 검은색 - 1개 이상인 경우 각 블록 사이사이에 흰 블록을 집어넣으면 모든 블록을 각자의 부분으로 만들 수 있다.
그 외의 경우에는 흰색 블록 + 1개까지만 만드는 것이 가능하다.

주요 알고리즘 : 구현

출처 : ROI Team K번
*/

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (b > a + 1) printf("%lld", a + 1);
    else printf("%lld", b);
    return 0;
}