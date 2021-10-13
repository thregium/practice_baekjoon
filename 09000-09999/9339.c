#include <stdio.h>

/*
문제 : K(K <= 100)명의 수강생의 번호가 주어진다. 번호는 10^6 이하의 자연수이다. 이때, N(N <= 1000)명의 번호와
마라톤 기록이 주어질 때, 6시간 내로 완주한 수강생의 수와 가장 빠른 수강생의 번호를 구한다.
단, 6시간 내로 완주한 수강생은 반드시 1명 이상 주어진다. 또한, 기록이 음수인 경우는 완주하지 못한 것이다.

해결 방법 : 먼저 수강생의 목록을 저장한다. 그 다음, 기록을 확인해 완주했는 지 확인한다. 완주하지 못했다면 넘어간다.
완주했다면 수강생 중 하나인지 확인한다. 수강생이 아닌 경우에도 넘어간다. 완주한 수강생 가운데 가장 빠른 수강생의
번호를 확인하고 6시간 내로 완주한 수강생의 수를 세면 된다.

주요 알고리즘 : 구현

출처 : Thai 2013N A번
*/

int att[128];

int main(void) {
    int t, k, n, x, h, m, best, bx, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &att[i]);
        }
        scanf("%d", &n);
        best = 1440, bx = -1, cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &h, &m);
            m += 60 * h;
            h = 0;
            if (m < 0) continue;
            for (int j = 0; j < k; j++) {
                if (att[j] == x) h = 1;
            }
            if (!h) continue;
            if (m < best) {
                best = m;
                bx = x;
            }
            if (m <= 360) cnt++;
        }
        if (cnt == 0) return 1;
        printf("%d %d\n", bx, cnt);
    }
    return 0;
}