#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 1000)개의 도시를 M(N <= M <= 1000)일동안 이동하려고 한다.
각 날에는 도시에서 대기하거나 다음 도시로 이동 가능하다. 각 날의 피로도는 그날의 날씨 * 이동 거리이며,
각 날의 날씨와 이동거리는 1000 이하의 자연수이다. 이동하지 않으면 피로도가 쌓이지 않는다.
이때, 모든 도시를 이동하는 방법 가운데 가장 피로도가 낮을 때의 피로도를 구한다.

해결 방법 : 각 날과 도시마다의 피로도 최솟값을 변수로 하여 다이나믹 프로그래밍을 하면 된다.

주요 알고리즘 : DP

출처 : JOI 2015예 4번
*/

int mem[1024][1024], d[1024], c[1024];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        mem[0][i] = INF;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            mem[i][j] = mem[i - 1][j];
            if (j > 0 && mem[i - 1][j - 1] + c[i] * d[j] < mem[i][j]) {
                mem[i][j] = mem[i - 1][j - 1] + c[i] * d[j];
            }
        }
    }
    printf("%d\n", mem[m][n]);
    return 0;
}