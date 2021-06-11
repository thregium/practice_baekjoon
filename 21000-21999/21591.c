#include <stdio.h>

/*
문제 : 노트북과 스티커의 가로, 세로 길이가 각각 주어질 때 스티커를 돌리지 않고 노트북에 모든 방향으로 1cm 이상 여유를 두며 붙일 수 있는지 구한다.

해결 방법 : 1cm씩 여유를 두기 위해서 노트북은 양쪽으로 1cm씩 2cm 더 커야 한다. 해당 조건이 맞는지 확인해보면 된다.

주요 알고리즘 : 구현

출처 : NADC 2021 G번
*/

int main(void) {
    int wc, hc, ws, hs;
    scanf("%d %d %d %d", &wc, &hc, &ws, &hs);
    printf("%d", (wc >= ws + 2 && hc >= hs + 2));
    return 0;
}