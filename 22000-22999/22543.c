#include <stdio.h>
#define INF 0x7A35090F

/*
문제 : N(N <= 10000)개의 샘플과 M(M <= 16)개의 증감표가 있다. 128에서 시작하여 증감표를 통해
각 샘플의 다음 값을 정할 때, 원래 샘플과의 최소 오차(원래 값과 만들어진 값의 차이^2의 합)를 구한다.
증감표는 절댓값이 255 이하인 정수이고, 각 샘플의 값과 만들어진 값은 255 이하의 음이 아닌 정수이다.
만들어진 값이 범위를 벗어나는 경우 가장 가까운 값으로 클램핑된다.

해결 방법 : 먼저 표 전체를 무한대로 초기화한다. 그 이후로는 0번째 샘플의 값을 128로 두고
각 샘플의 각 값마다 해당 값에서 만들 수 있는 다음 샘플들의 값 별 최소 오차를 갱신해 나간다.
이것이 모두 끝나면 N번째 샘플의 최소 오차 가운데 최솟값을 찾아서 출력하면 된다.

주요 알고리즘 : DP

출처 : JAG 2010D C번
*/

int c[32], x[20480], mem[20480][256];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, y, best;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 256; j++) mem[i][j] = INF;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &c[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x[i]);
        }

        mem[0][128] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 256; j++) {
                for (int k = 0; k < m; k++) {
                    y = j + c[k];
                    if (y < 0) y = 0;
                    if (y > 255) y = 255;
                    mem[i + 1][y] = small(mem[i + 1][y], mem[i][j] + (y - x[i + 1]) * (y - x[i + 1]));
                }
            }
        }
        best = INF;
        for (int i = 0; i < 256; i++) {
            best = small(best, mem[n][i]);
        }
        printf("%d\n", best);
    }
    return 0;
}