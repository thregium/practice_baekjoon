#include <stdio.h>
#define INF 1012345678

/*
문제 : R * C(R, C <= 100) 크기의 지형이 있고, 각 지형의 높이가 주어진다. 이 지형에 대해 N(N <= 20000)회 다음 행동을 한 다음,
높이 E(E <= 5000)을 수면의 높이로 하는 호수로 지형을 채우려고 한다. 채워지는 물의 양 * 72 * 72를 구한다.
각 행동때마다 RS, CS, D가 주어지고, (RS, CS)를 왼쪽 위 꼭짓점으로 한 3 * 3 영역에 대해 가장 높은 지형 - D 높이의 지형을
기준점으로 잡을 때, 해당 높이 이상의 지형을 기준 높이로 바꾼다.

해결 방법 : 각 지형의 높이를 입력받아 저장한 다음, N개의 행동을 시뮬레이션한다. 3 * 3 크기의 영역에 대해 가장 높은
지점을 찾은 다음, 그 지점 - D의 높이로 평탄화시켜준다. 모든 행동이 끝나면 E보다 낮은 모든 지형에 대해
E와의 차이를 결과에 더하고, 마지막에 결괏값에 72 * 72를 곱한 값을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2008M B2번
*/

int elev[128][128];

int main(void) {
    int r, c, e, n, hst, rs, cs, ds;
    long long res = 0;
    scanf("%d %d %d %d", &r, &c, &e, &n);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &elev[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &rs, &cs, &ds);
        hst = -INF;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (elev[rs + j][cs + k] > hst) hst = elev[rs + j][cs + k];
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (hst - ds <= elev[rs + j][cs + k]) elev[rs + j][cs + k] = hst - ds;
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            elev[i][j] -= e;
            if (elev[i][j] < 0) res -= elev[i][j];
        }
    }
    printf("%lld", res * 5184);
    return 0;
}