#include <stdio.h>

/*
문제 : 현재 키가 K이고 키를 W(W > K) 이상으로 키우려고 한다. 한번에 키를 M씩 키울 수 있다면 최소 몇 회 키를 키워야 목표에 도달하는지 구한다.

해결 방법 : W - K 를 M으로 나눈 값을 올림하면 된다.

주요 알고리즘 : 수학

출처 : ILOCAMP 2010 B1-1번
*/

int main(void) {
    int k, w, m;
    scanf("%d %d %d", &k, &w, &m);
    printf("%d", (w - k + m - 1) / m);
    return 0;
}