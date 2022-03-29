#include <stdio.h>
#define INF 1012345678

/*
문제 : N(2 <= N <= 1000)개의 정점으로 이루어진 포레스트의 각 정점에 가중치(<= 1000, 자연수)가 주어진다.
이때, 2개의 리프 정점을 뽑았을 때, 그 정점들과 그들의 부모 정점들의 가중치 합의 최솟값을 구한다.
중복되는 정점은 가중치를 1번씩만 더한다.

해결 방법 : 트리 DP를 이용한다. 각 정점의 수를 1개 뽑을 때와 2개 뽑을 때로 나눈 다음
리프 정점인 경우 1개일 때 정점 값, 2개일 때 무한대를, 그 외의 경우에는 1개일 때
정점 값 + 자식 정점의 1개일 때 답 중 최솟값, 2개일 때에는 정점 값 + 자식 정점의 2개일 때 최솟값
또는 1개일 때 최솟값과 2번째 작은 값 중 작은 것을 답으로 한다.
포레스트 형태지만 가상의 정점 값 0인 정점의 다른 정점의 루트 정점들을 묶어주면 그 정점의 답을 통해
전체의 답을 얻을 수 있다.

주요 알고리즘 : DP, 트리DP

출처 : ECNA 2021 B번
*/

int chd[1024][1024], par[1024], page[1024], mem[1024][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int x, int c) {
    int res11 = INF, res12 = INF, res2 = INF, t;
    if (mem[x][c] <= INF) return mem[x][c];
    if (c == 0) {
        if (chd[x][0] == 0) return mem[x][c] = page[x];
        for (int i = 1; i <= chd[x][0]; i++) {
            res11 = small(res11, dp(chd[x][i], 0));
        }
        return mem[x][c] = res11 + page[x];
    }
    else {
        if (chd[x][0] == 0) return mem[x][c] = INF;
        for (int i = 1; i <= chd[x][0]; i++) {
            t = dp(chd[x][i], 0);
            if (t < res11) {
                res12 = res11;
                res11 = t;
            }
            else if (t < res12) {
                res12 = t;
            }
            res2 = small(res2, dp(chd[x][i], 1));
        }
        return mem[x][c] = small(INF, small(res11 + res12, res2) + page[x]);
    }
}

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &page[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        chd[a][++chd[a][0]] = b;
        par[b] = a;
    }
    for (int i = 1; i <= n; i++) {
        if (par[i] == 0) {
            chd[0][++chd[0][0]] = i;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) mem[i][j] = INF + 1;
    }
    printf("%d", dp(0, 1));
    return 0;
}