#include <stdio.h>
#include <stdlib.h>

/*
문제 : 전체 길이 L(L <= 1000)이 주어지고, N(N <= 10000)개의 길이 1 이상인 구간이 주어질 때, 예산 B(B <= 1000)의
범위 내에서 길이 L을 겹치지 않게 모두 포함하는 구간의 집합 가운데 가장 가치(<= 10^6)의 합이 큰 것을 구한다.
그러한 것이 없는 경우 -1을 출력한다.

해결 방법 : 먼저 각 구간을 시작 점이 빠른 순서대로 정렬한다. 그 다음, 길이 X에서 예산 Y를 사용했을 때의
가치 합 최댓값을 기준으로 DP를 한다. 이때, 0, 0의 값을 제외한 나머지는 -1(그러한 값이 없음)로 초기화해 둔다.
그 후로는 각 구간에 대해 구간의 가능한 모든 예산의 범위([0, B - C_i])에서 mem(X, Y) + F_i가 mem(X + w_i, Y + C_i)보다
더 큰 경우 갱신시키는 것을 반복한다. 단, mem(X, Y)가 -1인 경우는 갱신하지 않고 넘어간다.
이 작업이 끝나면 길이 L에서 모든 예산 범위 중 가장 mem(L, i)의 값이 큰 것을 골라 출력하면 된다.
그러한 값이 없다면 자동으로 -1이 될 것이다.

주요 알고리즘 : DP, 냅색

출처 : USACO 2006D S2번
*/

int roller[10240][4], mem[1024][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, n, b, r = -1;
    scanf("%d %d %d", &l, &n, &b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &roller[i][j]);
        }
    }
    qsort(roller, n, sizeof(int) * 4, cmp1);
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 1024; j++) mem[i][j] = -1;
    }
    mem[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= b - roller[i][3]; j++) {
            if (mem[roller[i][0]][j] < 0) continue;
            else mem[roller[i][0] + roller[i][1]][j + roller[i][3]] = big(mem[roller[i][0] + roller[i][1]][j + roller[i][3]],
                mem[roller[i][0]][j] + roller[i][2]);
        }
    }
    for (int i = 0; i <= b; i++) r = big(r, mem[l][i]);
    printf("%d", r);
    return 0;
}