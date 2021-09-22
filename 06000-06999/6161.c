#include <stdio.h>

/*
문제 : N(N <= 1000)개의 곡이 있고, 처음에 각 곡들을 각각의 점수를 갖는다. 매번 곡을 틀 때 마다 가장 점수가 높은 곡 가운데
가장 앞쪽에 있는 곡을 선택하고 선택한 곡은 점수를 0점으로 초기화한다.
그 점수는 나머지 N - 1개의 곡들이 나눠갖되, N - 1로 나누어 떨어지지 않는 점수는 앞쪽 곡들이 1점씩 나누어 갖는다.
이를 반복할 때, T(T <= 1000)번의 선곡 순서를 구한다.

해결 방법 : 위 내용을 시뮬레이션하면 된다. 매번 가장 점수가 높은 곡을 찾은 다음, 그 곡의 점수를 N - 1로 나눈 수를
다른 곡들에 나누어준 다음, 나머지 점수는 맨 앞 곡부터 차례로 나누어 준다. 찾은 곡들마다 출력을 하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2008J B3번
*/

int rating[1024];

int main(void) {
    int n, t, b = 0, d;
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &rating[i]);
    }
    for (int i = 0; i < t; i++) {
        b = 0;
        for (int j = 1; j <= n; j++) {
            if (rating[j] > rating[b]) b = j;
        }
        if (b == 0) return 1;
        printf("%d\n", b);
        d = rating[b] / (n - 1);
        rating[b] -= d * (n - 1);
        for (int j = 1; j <= n; j++) {
            if (j == b) continue;
            if (rating[b]) {
                rating[j]++;
                rating[b]--;
            }
            rating[j] += d;
        }
    }
    return 0;
}