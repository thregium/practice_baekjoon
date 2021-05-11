#include <stdio.h>

/*
문제 : S와 T(S < T <= 100)가 주어질 때, S를 T로 만드는데 다음 연산들을 최소 몇 번 써야 하는지 구한다.
1. S에 2를 곱하고 T에 3을 더한다. / 2. S에 1을 더한다.

해결 방법 : S가 T보다 커지는 경우 다음 경우들을 (2, 1)인 경우를 제외하면 S를 T로 만들 수 없음을 알 수 있다.
그런데, 그러한 경우가 나올 일은 없고, S와 T의 제한이 작아 백트래킹을 하더라도 시간 내에 충분히 풀 수 있다.

주요 알고리즘 : 백트래킹

출처 : 중앙대 2017R B번
*/

int best;

void track(int x, int y, int c) {
    if (x == y) {
        if (c < best) best = c;
        return;
    }
    else if (x > y) return;
    track(x * 2, y + 3, c + 1);
    track(x + 1, y, c + 1);
}

int main(void) {
    int n, s, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &t);
        best = 999;
        track(s, t, 0);
        printf("%d\n", best);
    }
    return 0;
}