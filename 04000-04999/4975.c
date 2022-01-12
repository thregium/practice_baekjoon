#include <stdio.h>

/*
문제 : N(N <= 1000)대의 컴퓨터와 M(M <= 10000)명의 사용자가 있다. R(R <= 1000)개의 로그에 어떤 사용자가
언제 어떤 컴퓨터에 접속/종료했는 지 주어지면, 다음 쿼리에 응답한다.
T_s - T_e 시간동안 사용자 M_i라는 사용자가 접속해 있던 시간을 구한다.
한 사람이 여러 컴퓨터에 접속 가능하며,
그때도 시간을 2배 하는 등의 일 없이 단순히 접속해 있는 것으로 생각한다. 또한, 로그는 시간에 대해
오름차순으로 작성되어 있으며, 주어지는 모든 시각은 540 이상 1260 이하의 자연수이다.

해결 방법 : 로그를 확인할 때 마다 그때의 사용자별 컴퓨터 사용 여부와 사용중인 컴퓨터의 대수를 갱신한다.
그리고 쿼리가 주어질 때 마다 그 시간동안 사용 중이었던 시각의 개수를 구하면 쿼리의 답이 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JDC 2007 B번
*/

char usage[10240][1280];
int user[10240];

int main(void) {
    int n, m, r, q, ts, te, ni, mi, s;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        scanf("%d", &r);
        ts = 540;
        for (int i = 0; i < r; i++) {
            scanf("%d %d %d %d", &te, &ni, &mi, &s);
            while (ts < te) {
                for (int j = 1; j <= m; j++) usage[j][ts] = !!user[j];
                ts++;
            }
            if (s) user[mi]++;
            else user[mi]--;
        }
        while (ts < 1260) {
            for (int j = 1; j <= m; j++) usage[j][ts] = !!user[j];
            ts++;
        }
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d %d %d", &ts, &te, &mi);
            r = 0;
            for (int j = ts; j < te; j++) r += usage[mi][j];
            printf("%d\n", r);
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 540; j < 1260; j++) {
                usage[i][j] = 0;
            }
            user[i] = 0;
        }
    }
    return 0;
}