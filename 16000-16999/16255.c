#include <stdio.h>

/*
문제 :K(K <<= 100)점 이상이며 상대보다 2점 이상 앞서면 이기는 배구 경기가 있다. 현재 두 팀의 점수
X : Y(X, Y <= 100)가 주어질 때, 승부가 나기 위해서 최소한 몇 게임이 추가로 필요한 지 구한다.
이를 T(T <= 5000)번 반복한다.

해결 방법 : 더 점수가 높은 팀(같다면 아무 팀)이 나머지 모든 게임을 이겨야 빨리 승부가 날 것이다.
두 조건이 모두 충족되어야 하므로 K점까지의 점수 또는 상대보다 2점 더 내는 점수 중 더 큰 것을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : RCC 2017Q1 A번
*/

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, k, x, y;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &k, &x, &y);
        if (x > y) printf("%d\n", big(k - x, y + 2 - x));
        else printf("%d\n", big(k - y, x + 2 - y));
    }
    return 0;
}