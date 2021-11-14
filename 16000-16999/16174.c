#include <stdio.h>

/*
문제 : N * N(N <= 64) 크기의 배열에서 각 칸마다 오른쪽 또는 아래쪽으로 이동 가능한 칸 수가 주어질 때,
가장 오른쪽 아래 칸으로 이동 가능한지 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 각 칸마다 이동 가능한 칸들을 늘려 가며 확인하면 된다.

주요 알고리즘 : DP

출처 : 숭실/중앙 2018 J번
*/

int game[64][64], mem[64][64];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &game[i][j]);
        }
    }
    if (game[n - 1][n - 1] >= 0) return 1;
    mem[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + game[i][j] < n) mem[i + game[i][j]][j] |= mem[i][j];
            if (j + game[i][j] < n) mem[i][j + game[i][j]] |= mem[i][j];
        }
    }
    printf("%s", mem[n - 1][n - 1] ? "HaruHaru" : "Hing");
    return 0;
}