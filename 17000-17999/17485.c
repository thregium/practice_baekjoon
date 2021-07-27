#include <stdio.h>
#define INF 1012345678

/*
문제 : N * M(N, M <= 1000) 크기의 격자에서 맨 윗줄에서 맨 아랫줄까지 내려가려고 한다. 각 칸에는 수가 써 있고,
매번 내려갈 때에는 왼쪽 아래, 아래, 오른쪽 아래 중 한 방향으로 내려가며, 직전에 내려간 방향과 같은 방향으로는 내려갈 수 없다.
이때, 내려가는데 드는 비용이 경로 전체에 적힌 수의 합과 같다고 한다면, 가장 비용이 적을 때의 비용을 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 각 칸과 마지막으로 내려간 방향에 대해 최솟값을 저장해둔다.
맨 윗 줄은 모든 방향이 해당 칸에 적힌 값과 같고, 이후 줄들은 존재하는 방향에 대해 각각 이전 위치의 서로 다른 방향 중
더 작은 값 + 해당 칸의 값이 최소 비용이 된다. 맨 아랫줄까지 가면 맨 아랫줄의 모든 값들 중 가장 낮은 것을 고르면 된다.

주요 알고리즘 : DP

출처 : 중앙대 2019C H번
*/

int arr[1024][1024], mem[1024][1024][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, r = INF;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) mem[0][i][j] = arr[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < m - 1) mem[i][j][0] = small(mem[i - 1][j + 1][1], mem[i - 1][j + 1][2]) + arr[i][j];
            else mem[i][j][0] = INF;
            mem[i][j][1] = small(mem[i - 1][j][0], mem[i - 1][j][2]) + arr[i][j];
            if (j > 0) mem[i][j][2] = small(mem[i - 1][j - 1][0], mem[i - 1][j - 1][1]) + arr[i][j];
            else mem[i][j][2] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) r = small(r, mem[n - 1][i][j]);
    }
    printf("%d", r);
    return 0;
}