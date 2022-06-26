#include <stdio.h>
#define INF 1012345678

/*
문제 : E(E <= 100)개의 운동을 하기 위해 각 운동마다 W(W <= 100)가지 원반을 X_ij(X_ij <= 100)개씩
놓으려고 한다. 이때, 모든 운동을 순서대로 하기 위해 원반을 옮기는 횟수의 최솟값을 구한다.
원반은 1개씩만 옮길 수 있으며, 모든 운동에는 반드시 정확히 해당 개수의 원반들만 있어야 한다.

해결 방법 : 다이나믹 프로그래밍을 이용한다.
모든 구간에 대해 겹치는 원반의 개수를 센 다음, 운동 구간의 범위를 넓혀가면서
전체에 대해 겹치지 않는 원반들을 전부 적용하기 위해 옮겨야 하는 횟수를 구해나간다.
범위 넓이가 1인 경우 0이고, 그 이상에 대해서는 모든 가능한 분할에 대해 양쪽의 기억된 값 합 +
각 범위에서 겹치는 원반 수의 합(해당 구간 전체에 겹치는 원반은 제외) * 2를 저장한다.
최종적으로 구하고자 하는 값은 전체 범위의 저장된 값에 전체 범위에서 겹치는 원반의 개수 * 2를 하면 나온다.

주요 알고리즘 : DP

출처 : GCJ 2022A 3번
*/

int x[128][128], ovlt[128], ovl[128][128], mem[128][128];

int main(void) {
    int t, e, w;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &e, &w);
        for (int i = 1; i <= e; i++) {
            for (int j = 1; j <= w; j++) {
                scanf("%d", &x[i][j]);
            }
        }
        for (int i = 1; i <= e; i++) {
            for (int j = 1; j <= w; j++) ovlt[j] = INF;
            for (int j = i; j <= e; j++) {
                ovl[i][j] = 0;
                for (int k = 1; k <= w; k++) {
                    if (x[j][k] < ovlt[k]) ovlt[k] = x[j][k];
                    ovl[i][j] += ovlt[k];
                }
            }
        }

        for (int i = 1; i <= e; i++) mem[i][i] = 0;
        for (int i = 1; i < e; i++) {
            for (int j = 1; j <= e - i; j++) {
                mem[j][i + j] = INF;
                for (int k = j + 1; k <= j + i; k++) {
                    if ((ovl[j][k - 1] + ovl[k][j + i] - ovl[j][j + i] * 2) * 2
                        + mem[j][k - 1] + mem[k][j + i] < mem[j][i + j]) {
                        mem[j][i + j] = (ovl[j][k - 1] + ovl[k][j + i] - ovl[j][j + i] * 2) * 2
                            + mem[j][k - 1] + mem[k][j + i];
                    }
                }
            }
        }

        printf("Case #%d: %d\n", tt, mem[1][e] + ovl[1][e] * 2);
    }
    return 0;
}