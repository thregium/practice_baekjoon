#include <stdio.h>

/*
문제 : N(N <= 15)일간 비트코인의 가격(1 <=, <= 50)이 주어질 때, 초기 현금 W(W <= 100000)에서 마지막 날의
현금을 최대로 하려고 할 때, 그 날의 현금을 구한다. 단, 분할 매수는 불가능하고 수수료는 없다.

해결 방법 : 매일 다음 날의 가격을 비교하며 다음 날 가격이 오른다면 최대한 매수하고,
내린다면 전량 매도한다. 마지막 날에는 전량 매도해야 한다. 그러면 마지막 날의 현금이 최대가 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : Seoul 2019I C번
*/

int s[64];

int main(void) {
    int n;
    long long w, c = 0;
    scanf("%d %lld", &n, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] < s[i + 1]) {
            c += w / s[i];
            w -= w / s[i] * s[i];
        }
        else {
            w += c * s[i];
            c = 0;
        }
    }
    printf("%lld", w);
    return 0;
}