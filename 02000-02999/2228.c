#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100)개의 수로 이루어진 배열이 있다. 서로 인접하거나 겹치지 않은 M(M <= N / 2)개의 배열을 선택하여
더했을 때의 구간 내 수의 합 중 최댓값을 구한다. 배열의 수는 절댓값이 32767 이하인 정수이고,
반드시 M개의 배열을 선택해야 한다.

해결 방법 : 각 배열의 수마다 선택한 배열의 수와 마지막으로 선택하였는지 여부를 변수로 두고 DP를 진행한다.
배열의 수는 마지막으로 선택하지 않은 상태에서 선택하면 늘어난다. 각 값에는 최댓값이 들어가야 한다.
답은 N번째 수에서 M개의 배열을 선택하였을 때 마지막으로 선택한 것과 선택하지 않은 것 가운데 더 큰 것을 선택하면 된다.

주요 알고리즘 : DP
*/

int a[128], mem[128][64][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            mem[i][j][0] = -INF;
            mem[i][j][1] = -INF;
        }
    }
    mem[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            mem[i][j][0] = big(mem[i - 1][j][0], mem[i - 1][j][1]);
            if (j > 0) mem[i][j][1] = big(mem[i - 1][j - 1][0] + a[i], mem[i - 1][j][1] + a[i]);
        }
    }
    printf("%d", big(mem[n][m][0], mem[n][m][1]));
    return 0;
}