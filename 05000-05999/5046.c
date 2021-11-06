#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 200)명이 B(B <= 50000)의 예산 범위 내로 호텔 예약을 해야 한다. 모든 사람은 같은 호텔에
같은 기간에 예약을 해야 한다. H(H <= 18)개의 호텔이 있고 W(W <= 13)주의 기간 내에 예약을 할 수 있다.
각 주에 호텔에 예약 가능한 인원과, 각 호텔의 1인당 투숙 가격이 주어질 때 예약을 할 수 있는지 구하고,
가능하다면 예약을 할 때의 최소 가격을 구한다. 불가능하다면 "stay home"을 출력한다.

해결 방법 : 예약을 할 수 있는 각 호텔에 대해 각 주 가운데 예약 가능 인원수가 N 이상인 주를 찾는다.
그 가운데 가장 싼 호텔에서 예산 범위가 B 이하인지 확인한다. 그렇다면 그때의 예산을 구하면 되고,
B 이하의 범위에서 예약이 불가능하다면 "stay home"을 출력하면 된다.

주요 알고리즘 : 구현

출처 : NCPC 2008 E번
*/

int main(void) {
    int n, b, h, w, price, cap, res = INF;
    scanf("%d %d %d %d", &n, &b, &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%d", &price);
        for (int j = 0; j < w; j++) {
            scanf("%d", &cap);
            if (cap >= n && n * price < res && n * price <= b) res = n * price;
        }
    }
    if (res == INF) printf("stay home");
    else printf("%d", res);
    return 0;
}