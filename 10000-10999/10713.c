#include <stdio.h>

/*
문제 : 일렬로 이루어진 N(N <= 100000)개의 도시를 M(M <= 100000)일동안 이동하려고 한다.
각 날의 이동 일정과 각 구간별 운임이 주어질 때, 전체 구간의 운임을 구한다.
각 구간의 운임은 카드를 살 때와 티켓을 살 때로 나누어진다. 카드를 살 때의 운임은 티켓의 운임보다 싸지만,
그 구간의 카드를 따로 사야 한다. 각 운임은 모두 100000 이하의 자연수이다.

해결 방법 : 각 구간을 이동하는 횟수를 누적 합을 통해 구한 다음, 각 구간별로 티켓과 카드 가운데
더 싼 것을 찾아 각각의 운임 합을 구해나가면 된다.

주요 알고리즘 : 그리디 알고리즘, 누적 합

출처 : JOI 2015 1번
*/

int cnt[103000];

int big(int a, int b) {
    return a > b ? a : b;
}

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, p, a, b, c, l = 0;
    long long r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p);
        if (i > 0) {
            cnt[big(p, l)]--;
            cnt[small(p, l)]++;
        }
        l = p;
    }
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
        scanf("%d %d %d", &a, &b, &c);
        r += small((long long)b * cnt[i] + c, (long long)a * cnt[i]);
    }
    printf("%lld\n", r);
    return 0;
}