#include <stdio.h>

/*
문제 : N(N <= 100)개의 자연수(<= 100)가 주어질 때, 앞 수 까지의 누적 합을 P(P <= 4)로 나눈 나머지가
0이 되도록 하는 수의 개수를 최대로 한다면 그 개수를 구한다.

해결 방법 : P의 값에 따라 경우를 나누어 생각한다. 우선 P의 배수들을 맨 앞에 배치하고,
P가 2인 경우에는 나머지가 1인 값들을 그 뒤에 배치하면 된다.
3인 경우에는 나머지가 1과 2인 값들을 교대로 배치한 후 남은 값들을 그 뒤에 배치한다.
4인 경우에는 나머지가 1과 3인 값들을 교대로 배치하고 2인 값들을 최대한 배치한 다음,
남은 값들을 그 뒤에 배치하면 된다.

주요 알고리즘 : 수학, 정수론, 그리디 알고리즘, 케이스 워크

출처 : GCJ 2017R2 A2번
*/

int g[128], cnt[4];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int t, n, p, r, m;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &p);
        for (int i = 0; i < n; i++) {
            scanf("%d", &g[i]);
            cnt[g[i] % p]++;
        }
        r = cnt[0];
        if (p == 2) {
            r += (cnt[1] + 1) >> 1;
        }
        else if (p == 3) {
            m = small(cnt[1], cnt[2]);
            r += m;
            cnt[1] -= m;
            cnt[2] -= m;
            r += (cnt[1] + cnt[2] + 2) / 3;
        }
        else if (p == 4) {
            m = small(cnt[1], cnt[3]);
            r += m;
            cnt[1] -= m;
            cnt[3] -= m;
            r += cnt[2] >> 1;
            cnt[2] &= 1;
            if (cnt[2]) r += (cnt[1] + cnt[3] + 5) >> 2;
            else r += (cnt[1] + cnt[3] + 3) >> 2;
        }
        else return 1;

        for (int i = 0; i < p; i++) cnt[i] = 0;
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}