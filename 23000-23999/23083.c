#include <stdio.h>
#define MOD 1000000007

/*
문제 : N * M(N, M <= 1000) 크기의 벌집이 문제에 주어진 형식으로 있다. 빈 칸의 좌표들이 주어질 때,
(1, 1)에서 (N, M)으로 이동하는 방법의 가짓수를 구한다.

해결 방법 : 열 번호가 줄어드는 방향으로 이동하지 않는 점을 이용해 다이나믹 프로그래밍을 통해 진행한다.
이때 열의 홀짝에 따라 이동 방향이 달라지므로 주의한다.

주요 알고리즘 : DP

출처 : 인하대 2021 K번
*/

char hole[1024][1024];
int mem[1024][1024];

int main(void) {
    int n, m, k, x, y;
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        hole[x][y] = 1;
    }
    mem[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (hole[j][i]) continue;
            mem[j + 1][i] = (mem[j + 1][i] + mem[j][i]) % MOD;
            mem[j][i + 1] = (mem[j][i + 1] + mem[j][i]) % MOD;
            if (i & 1) mem[j - 1][i + 1] = (mem[j - 1][i + 1] + mem[j][i]) % MOD;
            else mem[j + 1][i + 1] = (mem[j + 1][i + 1] + mem[j][i]) % MOD;
        }
    }
    printf("%d", mem[n][m]);
    return 0;
}