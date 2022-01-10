#include <stdio.h>
#include <math.h>

/*
문제 : (0, 0)에서 맨해튼 거리가 D(1 <= D <= 100)인 격자점 가운데 거리가 가장 E(1 <= E <= 100)에 가까운 점의
거리의 E와의 차이를 구한다.

해결 방법 : 그러한 격자점들의 좌표는 (i, D - i)인 지점들(과 4방향의 대칭)이다.
각 점들에 대해 피타고라스 정리를 이용해 거리를 구하고, E와의 차이를 구한 다음, 최솟값을 찾으면 된다.

주요 알고리즘 : 기하학, 피타고라스, 브루트 포스

출처 : JAG 2015D A번
*/

int main(void) {
    int d, e;
    double best;
    while (1) {
        scanf("%d %d", &d, &e);
        if (d == 0) break;
        best = 103000.0;
        for (int i = 0; i <= d; i++) {
            if (fabs(sqrt(i * i + (d - i) * (d - i)) - e) < best) best = fabs(sqrt(i * i + (d - i) * (d - i)) - e);
        }
        printf("%f\n", best);
    }
    return 0;
}