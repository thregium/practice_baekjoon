#include <stdio.h>

/*
문제 : N(N <= 100)명의 사람들이 경주를 한다. 각 사람들은 V_i(1 <= V_i <= 100, 정수)의 속도로
정속으로 움직이며, M(M <= 50)개의 쉬는 지점 각각에서 P_i(0 <= P_i <= 100, 정수)%의 확률로
T_i(0 <= T_i <= 100)만큼의 시간동안 쉰다. 전체 경주 거리가 L(L <= 100000, 정수)이라 할 때,
각 사람이 1위로 들어올 확률을 구한다. 단, 공동 1위인 경우에는 1위로 들어온 것이 아니다.

해결 방법 : 각 사람이 M개의 쉬는 지점에서 0회부터 M회까지 쉴 확률 각각을 다이나믹 프로그래밍을 통해 구한다.
그 다음, 각 사람의 각 쉬는 횟수마다 1위로 들어올 확률을 구하고, 그 합을 각 사람마다 구해서
출력하면 된다. 단, 들어오는 속도를 비교할 때 정수형으로 비교해야 실수 오차가 생기지 않는다.

주요 알고리즘 : DP, 조합론, 확률론

출처 : JAG 2011S3 D번
*/

int runner[128][2];
double rest[128][128], rmem[64][64];

int main(void) {
    int n, m, l, p;
    double r, t, t2;
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p, &runner[i][0], &runner[i][1]);
        rmem[0][0] = 1.0;
        for (int j = 1; j <= m; j++) {
            rmem[j][0] = rmem[j - 1][0] * (100 - p) / 100.0;
            for (int k = 1; k <= j; k++) {
                rmem[j][k] = (rmem[j - 1][k] * (100 - p) + rmem[j - 1][k - 1] * p) / 100.0;
            }
        }
        for (int j = 0; j <= m; j++) rest[i][j] = rmem[m][j];
    }

    for (int i = 0; i < n; i++) {
        r = 0.0;
        for (int j = 0; j <= m; j++) {
            t = 1.0;
            for (int k = 0; k < n; k++) {
                if (i == k) continue;
                t2 = 0;
                for (int ii = 0; ii <= m; ii++) {
                    if (runner[k][1] * (l + runner[i][1] * runner[i][0] * j) <
                        runner[i][1] * (l + runner[k][1] * runner[k][0] * ii)) {
                        t2 += rest[k][ii];
                    }
                }
                t *= t2;
            }
            r += t * rest[i][j];
        }
        printf("%.9f\n", r);
    }
    return 0;
}