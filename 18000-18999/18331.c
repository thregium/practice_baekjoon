#include <stdio.h>

/*
문제 : N(N <= 30)일간의 Oshloob의 가격(1000 <=, <= 2000, 자연수)이 주어질 때, 최초 소지금 C(0 <= C <= 3000, 정수)로
Oshloob을 사고 판 다음의 최대 소지금을 구한다. 수수료는 없다.

해결 방법 : 다음 날에 오르는 경우 최대한 Oshloob을 사고, 내리는 경우 최대한 파는 것을 반복하면 된다.
마지막 날에는 남은 Oshloob을 모두 팔도록 한다.

주요 알고리즘 : 그리디 알고리즘

출처 : Tehran 2019 B번
*/

int s[64];

int main(void) {
    int n;
    long long w, c = 0;
    scanf("%lld %d", &w, &n);
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