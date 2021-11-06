#include <stdio.h>
#include <stdlib.h>

/*
문제 : M(M <= 1000)개의 구간에 대해 해당 구간의 시작점과 끝점(<= N)이 주어지고, 각 구간의 가치(<= 10^6)가 주어진다.
N은 10^6 이하의 자연수이다. 구간마다 R(R < N)만큼의 여유를 두고 구간들을 겹치지 않게 선택했을 때
가치의 합의 최댓값을 구한다.

해결 방법 : 각 구간들을 시작점 순으로 정렬한다. 그리고 dp(x)를 시각 x에서 합의 최댓값으로 정의하고 다이나믹 프로그래밍을 한다.
먼저, dp(0)은 0으로 두고, 이후로는 dp(x)는 dp(x - 1)과 dp(x) 가운데 더 큰 값으로 정의한다.
매번 x로 시작하는 구간들마다 dp(e + r)을 dp(x) + h와 비교해 큰 값으로 갱신한다.(e는 해당 구간의 끝점, h는 가치)
이를 반복한 후 dp(n + r)의 값을 구하면 답이 된다.

주요 알고리즘 : DP, 정렬

출처 : USACO 2007N S2번
*/

int milk[1024][3], mem[2097152];

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, r, p = 0;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &milk[i][0], &milk[i][1], &milk[i][2]);
    }
    qsort(milk, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i <= n + r; i++) {
        if (i > 0) mem[i] = big(mem[i - 1], mem[i]);
        while (p < m && milk[p][0] == i) {
            mem[milk[p][1] + r] = big(mem[milk[p][1] + r], mem[i] + milk[p][2]);
            p++;
        }
    }
    printf("%d", mem[n + r]);
    return 0;
}