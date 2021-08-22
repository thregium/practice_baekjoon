#include <stdio.h>

/*
문제 : N(N <= 2 * 10^9)명이 놀이기구 줄에 서있다. M(M <= 10000)개의 놀이기구가 있고, 각각의 탑승 시간은 30 이하의 정수이다.
각 사람들은 놀이기구가 빌 때 마다 비어있는 놀이기구 가운데 가장 번호가 작은 것을 탄다고 하면, 마지막 사람이 타게 되는
놀이기구의 번호를 구한다.

해결 방법 : 매개 변수 탐색을 통해 놀이기구를 탄 사람이 N명 이상이 되는 첫 시각 T를 고른다.
해당 시각에 놀이기구를 탄 사람의 수는 단순히 해당 시각 / 탑승 시간 + 1을 모든 놀이기구에 대해 더하면 된다.
이때, 최댓값을 600억 이상으로 해야 함에 주의한다. 또한, 시간이 음수가 된 경우에는 놀이기구를 탄 사람의 수는 0이다.
그 다음으로는 T - 1때의 사람 수에서 시작해서 N번째 사람이 탔을 놀이기구의 번호를 찾으면 된다.
이때 비어있는 놀이기구는 해당 시각이 탑승 시간의 배수인 경우이다. T일때 놀이기구를 탄 사람 수를 f(T)라고 한다면
N - f(T - 1)번째 비어있는 놀이기구의 번호를 찾는다.

주요 알고리즘 : 수학, 파라메트릭

출처 : CHCI 2003RS 3번
*/

int mins[10240];

long long get_played(int m, long long x) {
    long long r = 0;
    if (x == -1) return 0;
    for (int i = 0; i < m; i++) {
        r += x / mins[i] + 1;
    }
    return r;
}

int main(void) {
    int n, m;
    long long lo = 0, hi = 123456789012, s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &mins[i]);
    }
    while (lo < hi) {
        if (get_played(m, (lo + hi) >> 1) < n) lo = ((lo + hi) >> 1) + 1;
        else hi = (lo + hi) >> 1;
    }
    s = get_played(m, lo - 1);
    for (int i = 0; i < m; i++) {
        if (lo % mins[i] == 0) s++;
        if (s == n) {
            printf("%d", i + 1);
            return 0;
        }
    }
    return 1;
}
