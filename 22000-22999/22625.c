#include <stdio.h>
#define INF 1012345678

/*
문제 : T(T <= 30)일마다 반복되는 수면 패턴을 갖는 사람이 있다. N(N <= 100)개의 일정이 있고,
각 일정의 날짜 D_i(D_i <= 100)일에는 M(1 <= M <= 23)시간 이내로 자야 한다.
수면 패턴의 첫 날은 반드시 1시간만 자고 모든 날에는 1 ~ 23시간 이내로 자며, 마지막 날 다음 날에는
첫 날로 돌아온다. 카페인 약을 먹으면 수면 패턴을 첫 날로 되돌릴 수 있다면,
모든 일정을 소화하기 위해 먹어야 하는 카페인 약의 개수를 구한다.

해결 방법 : 1일차부터 해당 날을 1일차로 하는 수면 패턴에서 소화할 수 있는 일정의 마지막 날까지 확인한다.
각 날마다 그 날 다음 날에 카페인 약을 먹으면 다음 날 이전까지의 모든 일정을 소화 가능한 것이므로,
각 날마다 해당 날이 첫 날의 수면 패턴일 때의 먹어야 하는 카페인 약의 최소 개수로 변수를 잡고
다이나믹 프로그래밍을 진행하면 된다. 마지막 날까지 소화 가능한 시작 수면 패턴일의 먹어야 하는
카페인 약의 최소 개수가 답이 된다.

주요 알고리즘 : DP

출처 : JAG 2009S3 B번
*/

int cyc[32], ivw[128], mem[128];

int main(void) {
    int t, n, d, m, r;
    for (int tt = 0; tt == 0; tt++) {
        scanf("%d", &t);
        if (t == 0) break;
        for (int i = 0; i < t; i++) {
            scanf("%d", &cyc[i]);
        }
        for (int i = 1; i <= 100; i++) {
            mem[i] = INF;
            ivw[i] = 24;
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &d, &m);
            if (m < ivw[d]) ivw[d] = m;
        }
        r = INF;
        mem[1] = 0;
        for (int i = 1; i <= 100; i++) {
            for (int j = i; j <= 100; j++) {
                if (cyc[(j - i) % t] > ivw[j]) break;
                if (mem[i] + 1 < mem[j + 1]) mem[j + 1] = mem[i] + 1;
                if (j == 100 && mem[i] < r) r = mem[i];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}