#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 10000)개의 정점으로 이루어진 트리가 주어지고, 두 정점이 주어지면
두 정점 사이 트리의 공통 조상 가운데 가장 낮은 곳에 있는 것을 구한다.

해결 방법 : 우선 각 정점의 부모 노드를 구한다. 그 다음, 트리의 임의의 노드에서 출발해
더이상 부모 노드가 없는 루트 노드에 도착하면 해당 루트에서 시작해서 각 정점의 차수를 구한다.
차수를 구한 다음, 두 정점 가운데 차수가 높은 정점에서 부모 노드로 돌아가며 차수가 낮은 정점의 차수와 맞춘다.
그리고 양쪽 노드가 같아질 때 까지 두 정점의 부모로 가는 것을 반복한다.

두 노드가 같아질 때의 노드가 최소 공통 조상이다.
초기화에 유의한다.

주요 알고리즘 : 그래프 이론, DFS, 트리, LCA

출처 : Daejeon 2002 A번
*/

int par[10240], level[10240];
vector<int> child[10240];

void dfs(int x, int lv) {
    level[x] = lv;
    for (int i : child[x]) {
        if (!level[i]) dfs(i, lv + 1);
    }
}

int main(void) {
    int t, n, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            child[a].push_back(b);
            par[b] = a;
        }
        a = 1;
        while (par[a]) a = par[a];
        dfs(a, 1);
        scanf("%d %d", &a, &b);
        while (level[b] > level[a]) b = par[b];
        while (level[a] > level[b]) a = par[a];
        while (a != b) {
            a = par[a];
            b = par[b];
        }
        printf("%d\n", a);

        for (int i = 1; i <= n; i++) {
            par[i] = 0;
            level[i] = 0;
            child[i].clear();
        }
    }
    return 0;
}