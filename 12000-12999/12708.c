#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 점이 공간상에 있다. 각 점의 위치는 절댓값 10^6 이하의 격자점이고,
자연수 가중치 p_i(<= 10^6)를 가진다. 원하는 임의의 지점에서 모든 점까지의 맨해튼 거리 / p_i의
최댓값을 최소로 할 때의 해당 값을 구한다.

해결 방법 : 맨해튼 거리는 각 3차원 대각선으로 4개의 방향에 대해서 독립적으로 계산하고,
그 중 최댓값을 구하는 과정을 통해 계산 가능함을 알 수 있다.
각 방향에 대해 삼분 탐색을 통해 최소 거리를 구한 다음 그 중 최댓값을 구하면 답이 된다.

주요 알고리즘 : 수학, 기하학, 삼분 탐색

출처 : GCJ 2008_2 C2번
*/

int point[1024][4], od[1024][2];
double resd[4];
int dir[4][3] = { {1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1} };

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double getdist(int n, double pos) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        if (fabs(pos - od[i][0]) / od[i][1] > res) res = fabs(pos - od[i][0]) / od[i][1];
    }
    return res;
}

int main(void) {
    int t, n;
    double lo, hi, midl, midh, res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &point[i][j]);
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                od[j][0] = 0;
                od[j][1] = point[j][3];
                for (int k = 0; k < 3; k++) {
                    od[j][0] += point[j][k] * dir[i][k];
                }
            }
            qsort(od, n, sizeof(int) * 2, cmp1);

            lo = od[0][0], hi = od[n - 1][0];
            for (int k = 0; k < 123; k++) {
                midl = (lo * 2 + hi) / 3;
                midh = (lo + hi * 2) / 3;
                if (getdist(n, midl) < getdist(n, midh)) hi = midh;
                else lo = midl;
            }

            resd[i] = getdist(n, lo);
        }

        res = 0.0;
        for (int i = 0; i < 4; i++) {
            if (resd[i] > res) res = resd[i];
        }
        printf("Case #%d: %.9f\n", tt, res);
    }
    return 0;
}