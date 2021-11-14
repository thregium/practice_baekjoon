#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100)일간 가운데 M(M <= N)일을 제외한 모든 날에 리조트를 가기 위해 필요한 최소 경비를 구한다.
리조트는 1일권, 3일권, 5일권이 있고 각각 10000원, 25000원, 37000원이다. 3일권과 5일권은 쿠폰을 각각 1장, 2장 준다.
쿠폰을 3장 모으면 1일권으로 교환 가능하다. 일부 날이 리조트가 열지 않는 날이라도 3일권 또는 5일 권을 구매 가능하다.

해결 방법 : dp(날 수, 쿠폰 수)로 다이나믹 프로그래밍을 한다. 열지 않는 날이면 이전 날의 경비 그대로로 갈 수 있고,
그 외에는 1일권을 추가해야 한다. 3일권, 5일권, 쿠폰 사용은 각각 조건을 확인해 조건에 맞으면 비교해서
가장 작은 값을 찾는다. N일째의 모든 쿠폰 수 가운데 가장 작은 경비인 곳이 답이 된다.

주요 알고리즘 : DP

출처 : 정올 2016 초3/고1번
*/

int dis[128], mem[128][128];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, x, r = INF;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        dis[x] = 1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n + 3; j++) mem[i][j] = INF;
    }
    mem[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dis[i]) mem[i][j] = mem[i - 1][j];
            else mem[i][j] = mem[i - 1][j] + 10000;
            mem[i][j] = small(mem[i][j], mem[i - 1][j + 3]);
            if (i >= 3 && j >= 1) mem[i][j] = small(mem[i][j], mem[i - 3][j - 1] + 25000);
            if (i >= 5 && j >= 2) mem[i][j] = small(mem[i][j], mem[i - 5][j - 2] + 37000);

            if (i == n) r = small(r, mem[i][j]);
        }
    }
    printf("%d", r);
    return 0;
}