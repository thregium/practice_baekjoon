#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)개의 선분과 M(M <= 100000)개의 점이 주어진다. 모든 좌표는 10^9 이하의 자연수이다.
각 선분의 시작점과 끝점, 주어진 점들은 모두 다르다.
이때, 각 선분을 중간에 지나는 점들로 끊었을 때 홀수 번째의 구간만 남긴다면
남은 구간 길이의 합을 구한다.

해결 방법 : 각 점들을 정렬한 다음, 각 선분마다 해당 구간에 포함되는 점들의 시작점과 끝점을 구한다.
그 다음 누적 합을 통해 해당 구간의 남은 구간 길이를 구한다. 누적 합은 홀수와 짝수인 경우를
따로따로 구해둔다. 시작점의 방향에 따라 경우를 다르게 나누어야 함에 유의한다.
마지막으로 시작점과 방향에 따라 남은 실의 길이를 더해나가면 각 선분에 대한 남은 구간의 길이를
빠르게 구할 수 있고, 이를 반복하여 남은 구간 길이의 합을 구할 수 있다.

주요 알고리즘 : 이분 탐색, 누적 합

출처 : JAG 2011D4 H번
*/

int line[103000][2], cut[103000], osum[103000], esum[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, lo, hi, mid, lt, rt;
    long long res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &line[i][0], &line[i][1]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &cut[i]);
    }
    cut[m + 1] = INF;
    qsort(cut + 1, m, sizeof(int), cmp1);
    for (int i = 1; i <= m + 1; i++) {
        osum[i] = osum[i - 1];
        esum[i] = esum[i - 1];
        if (i & 1) osum[i] += cut[i] - cut[i - 1];
        else esum[i] += cut[i] - cut[i - 1];
    }
    osum[m + 1] = INF;
    esum[m + 1] = INF;
    for (int i = 0; i < n; i++) {
        lo = 0, hi = m + 1;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (cut[mid] >= small(line[i][0], line[i][1])) hi = mid;
            else lo = mid + 1;
        }
        lt = lo;
        lo = 0, hi = m + 1;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (cut[mid] <= big(line[i][0], line[i][1])) lo = mid;
            else hi = mid - 1;
        }
        rt = hi;
        if (lt > rt) {
            res += big(line[i][0], line[i][1]) - small(line[i][0], line[i][1]);
            continue;
        }
        if (line[i][0] == line[i][1]) return 1;
        else if (line[i][0] < line[i][1]) {
            res += cut[lt] - line[i][0];
            if (lt & 1) res += osum[rt] - osum[lt];
            else res += esum[rt] - esum[lt];
            if ((rt - lt) & 1) res += line[i][1] - cut[rt];
        }
        else {
            res += line[i][0] - cut[rt];
            if (rt & 1) res += esum[rt] - esum[lt];
            else res += osum[rt] - osum[lt];
            if ((rt - lt) & 1) res += cut[lt] - line[i][1];
        }
    }
    printf("%lld\n", res);
    return 0;
}