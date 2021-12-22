#include <stdio.h>

/*
문제 : D(D <= 100000)만큼의 시간동안 비행을 한다. 기내식은 M(M <= 1000)번 나오며, 시간 순으로 0부터 D 이전까지 나온다.
이때, 기내식이 나오지 않는 동안 잔다면 T(T <= 100000)만큼의 시간동안 연속으로 잘 수 있는지 구한다.

해결 방법 : 최근 기내식이 나온 시각과 현재 시각을 비교해서 그 가운데 가장 긴 것을 고르면 된다.
이때, 처음과 끝에도 비교해야 함에 유의한다.

주요 알고리즘 : 구현?

출처 : Brasil 2021 K번
*/

int main(void) {
    int t, d, m, y, last = 0, best = 0;
    scanf("%d %d %d", &t, &d, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &y);
        if (y - last > best) best = y - last;
        last = y;
    }
    if (d - last > best) best = d - last;
    printf("%c", best >= t ? 'Y' : 'N');
    return 0;
}