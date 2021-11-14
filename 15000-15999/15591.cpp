#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 5000)개의 정점을 가진 트리에서 각 간선별로 가중치(<= 10^9)가 주어진다. 이때, 두 정점 사이의 가중치가
최단 경로의 가중치 가운데 최소 가중치로 정의된다면 정점 v와의 가중치가 K(K <= 10^9) 이상인 정점의 개수를 Q(Q <= 5000)번 구한다.

해결 방법 : V에서 DFS를 하면서 가중치가 K 이상인 간선만을 지나며 갈 수 있는 정점의 개수를 구하면 된다.
매번 방문 체크를 재설정 해줘야 함에 유의한다.

주요 알고리즘 : 그래프 이론, DFS, 트리

출처 : USACO 2018J S3번
*/

int vis[5120];
vector<pair<int, int>> ed[5120];

int dfs(int k, int x) {
    int r = 1;
    vis[x] = 1;
    for (auto i : ed[x]) {
        if (vis[i.first] || i.second < k) continue;
        r += dfs(k, i.first);
    }
    return r;
}

int main(void) {
    int n, q, a, b, c;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back(pair<int, int>(b, c));
        ed[b].push_back(pair<int, int>(a, c));
    }
    for (int qq = 0; qq < q; qq++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", dfs(a, b) - 1);
        for (int i = 1; i <= n; i++) vis[i] = 0;
    }
    return 0;
}