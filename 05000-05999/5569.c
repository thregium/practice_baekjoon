#include <stdio.h>
#define MOD 100000

/*
문제 : W * H(W, H <= 100) 크기의 격자의 한쪽 끝에서 반대쪽 끝까지 연속해서 회전하지 않고 최단거리로 이동하는 방법의 가짓수를 구한다.

해결 방법 : 위치와 마지막으로 회전했는지 여부, 마지막 이동 방향을 변수로 두고 DP를 한다.

주요 알고리즘 : DP

출처 : JOI 2010예 5번
*/

int mem[128][128][2][3];

int main(void) {
    int w, h;
    mem[0][0][0][0] = 1;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            mem[i + 1][j][0][1] = (mem[i + 1][j][0][1] + mem[i][j][1][1] + mem[i][j][0][1] + mem[i][j][0][0]) % MOD;
            mem[i][j + 1][0][2] = (mem[i][j + 1][0][2] + mem[i][j][1][2] + mem[i][j][0][2] + mem[i][j][0][0]) % MOD;
            mem[i + 1][j][1][1] = (mem[i + 1][j][1][1] + mem[i][j][0][2]) % MOD;
            mem[i][j + 1][1][2] = (mem[i][j + 1][1][2] + mem[i][j][0][1]) % MOD;
        }
    }
    printf("%d", (mem[w - 1][h - 1][0][1] + mem[w - 1][h - 1][0][2] + mem[w - 1][h - 1][1][1] + mem[w - 1][h - 1][1][2]) % MOD);
    return 0;
}