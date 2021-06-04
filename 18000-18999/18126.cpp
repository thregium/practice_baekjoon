#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 5000)개의 정점이 있는 트리의 1번 노드에서 출발할 때, 가장 먼 거리에 있는 노드의 거리를 구한다.

해결 방법 : 트리의 모든 노드에 대해 거리를 살펴본 다음 가장 그 값이 큰 것을 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 트리

출처 : 가톨릭대 1회D2 3번
*/

long long maxdist = 0;
int vis[5120];
vector<pair<int, int>> v[5120];

void dfs(int x, long long dist) {
    vis[x] = 1;
    if (dist > maxdist) maxdist = dist;
    for (pair<int, int> p : v[x]) {
        if (vis[p.first]) continue;
        else dfs(p.first, dist + p.second);
    }
}

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(pair<int, int>(b, c));
        v[b].push_back(pair<int, int>(a, c));
    }
    dfs(1, 0);
    printf("%lld", maxdist);
    return 0;
}