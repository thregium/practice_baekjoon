#include <stdio.h>
#include <string.h>
#define MOD 1000000007

/*
문제 : 2 * N(N <= 10000) 크기의 격자에 (1 ~ 2 * N) 순열을 쓴다. 이때, 가로로든 세로로든 단조 증가하는 순열의 개수를 구한다. 

해결 방법 : 현재 상태로부터 [위쪽에 남은 칸][아래쪽에 남은 칸]을 변수로 하는 다이나믹 프로그래밍을 한다.
처음에는 N, N에서 시작해서 dp(X, Y) = dp(X - 1, Y) + (X < Y ? dp(X, Y - 1))의 점화식을 통해 들어가면 된다.
어떤 상태든 다음 수는 위쪽 칸에 추가할 수 있지만, X와 Y의 수가 같다면 아래쪽 칸에 추가하면 규칙이 깨지기 때문에 불가능하다.
만약 X가 0까지 내려온 경우 그 때의 값은 1이 된다.
이 값을 보면 카탈란 수와 같기 때문에 카탈란 수를 구해도 된다.

주요 알고리즘 : DP, 카탈란 수

출처 : 숙명여대 1회 F번
*/

int mem[10240][10240];

int dp(int x, int y) {
    if (mem[x][y] >= 0) return mem[x][y];
    if (x == 0) return mem[x][y] = 1;

    int r = dp(x - 1, y);
    if (x < y) r = (r + dp(x, y - 1)) % MOD;
    return mem[x][y] = r;
}

int main(void) {
    int n;
    scanf("%d", &n);
    memset(mem, -1, (n + 1) * 10240 * sizeof(int));
    printf("%d", dp(n, n));
    return 0;
}