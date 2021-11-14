#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 200000)개의 간선으로 이루어진 그래프가 있다. 1개의 간선은 가중치가 1이고,
나머지 간선은 전부 가중치가 0이라면 모든 정점간의 최단거리 합을 구한다. 단, 그래프는 반드시 연결 그래프로 주어진다.

해결 방법 : 가중치가 1인 간선을 제거했을 때 여전히 연결 그래프인 경우에는 돌아가면 되므로 최단거리 합은 0이다.
연결이 끊어지는 경우에는 양쪽 그룹의 곱과 같다. 따라서, 한 지점에서 연결 요소의 크기를 구하고,
N - 크기와 곱한 값이 답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : 홍익대 2021 E번
*/

char vis[103000];
vector<int> ed[103000];

int dfs(int x) {
    int r = 1;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) r += dfs(i);
    }
    return r;
}

int main(void) {
    int n, m, k, u, v;
    long long r;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        if (i == k) continue;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    r = dfs(1);
    printf("%lld", r * (n - r));
    return 0;
}