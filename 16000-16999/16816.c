#include <stdio.h>

/*
문제 : D(D <= 100000)일간의 체중 변화량(|| <= 100000)이 주어진다. 최초 체중이 S(1 <= S <= 100000)이고,
목표 체중이 T(1 <= T < S)일 때, 목표 체중 이하가 될 수 있는 지 구하고, 가능하다면
목표 체중 이하가 되는 첫 날을 구한다. 불가능한 경우 -1을 출력한다. D일이 지나면 다시 첫 날의 변화량으로
돌아온 다음 이 변화량들을 반복한다.

해결 방법 : 먼저 첫 D일간의 변화를 살핀다. 중간에 T 이하의 체중이 되는 날이 나오면 그 날을 출력하면 되고,
그 외에는 전체 날동안 변화량과 최소 체중인 날의 체중을 구한다.
ceil((최대 체중 - T) / sum(변화량))번 D일의 변화를 반복하더라도
중간에 체중이 T 이하가 되는 날은 없을 것이다. 따라서 그만큼을 스킵한 다음 다시 D일동안 돌리면서
체중이 T 이하가 되는 첫 날을 구해서 출력하면 된다.

주요 알고리즘 : 수학, 구현, 시뮬레이션

출처 : JAG 2017S3 B번
*/

int w[103000];

int main(void) {
    int s, t, d;
    long long tot = 0, now, lw, r = 0;
    scanf("%d %d %d", &s, &t, &d);
    now = s, lw = s;
    for (int i = 0; i < d; i++) {
        scanf("%d", &w[i]);
        tot += w[i];
        now += w[i];
        if (now < lw) lw = now;
        if (now <= t) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    if (tot >= 0) {
        printf("-1\n");
        return 0;
    }
    r = (lw - t - tot - 1LL) / -tot;
    s += r * tot;
    now = s;
    for (int i = 0; i < d; i++) {
        now += w[i];
        if (now <= t) {
            printf("%lld\n", r * d + i + 1);
            return 0;
        }
    }
    return 1;
}