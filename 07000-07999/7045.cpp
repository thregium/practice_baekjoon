#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 10000)개의 정점으로 이루어진 트리가 주어질 때, 이 트리에서 정점을 제거하여 분해되는 트리 가운데
가장 큰 것의 크기가 N / 2 이하가 되는 정점을 오름차순으로 출력한다. 없으면 NONE을 출력한다.

해결 방법 : 먼저 DFS로 각 트리를 루트가 1인 트리로 만든 다음, 트리 DP를 통해 각 정점의 서브트리에 있는
정점의 수를 구한다. 각 정점에서 해당 정점의 자식의 서브트리 가운데 가장 큰 것과 해당 정점의 서브트리를 제외한
나머지 정점 중 더 큰 것의 크기가 N / 2 이하가 되는 정점의 목록을 저장한다.
그 정점들을 정렬한 다음 출력하면 된다.

주요 알고리즘 : DP, 트리 DP

출처 : USACO 2004D S3번
*/

int mem[10240], vis[10240], res[10240];
int rcnt = 0;
vector<int> ed[10240], child[10240];

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void dfs(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (vis[i]) continue;
        child[x].push_back(i);
        dfs(i);
    }
}

void dp(int n, int x) {
    int best = -1;
    mem[x] = 1;
    for (int i : child[x]) {
        dp(n, i);
        mem[x] += mem[i];
        best = big(best, mem[i]);
    }
    best = big(best, n - mem[x]);
    if (best * 2 <= n) res[rcnt++] = x;
}

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    dfs(1);
    dp(n, 1);
    qsort(res, rcnt, sizeof(int), cmp1);
    if (rcnt == 0) printf("NONE");
    else {
        for (int i = 0; i < rcnt; i++) {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}