#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 트리에서 임의의 정점 R이 루트이다. 이때, Q(Q <= 100000)개의 쿼리에 응답한다.
정점 U를 루트로 하는 서브트리에 속하는 정점의 수를 구한다.

해결 방법 : 간단한 트리DP를 통해 답을 구할 수 있다. 해당 노드의 모든 자식 노드의 결과에 1을 더한 값이 각 정점의 값이 된다.
모든 정점의 값을 저장하고 쿼리가 들어올 때 마다 쿼리에 응답하면 된다.

주요 알고리즘 : DP, 트리DP

출처 : 연세대 2018 PC번
*/

int mem[103000], vis[103000];
vector<int> ed[103000];

int dp(int x) {
    int r = 1;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (vis[i]) continue;
        r += dp(i);
    }
    return mem[x] = r;
}

int main(void) {
    int n, r, q, u, v;
    scanf("%d %d %d", &n, &r, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    dp(r);
    for (int i = 0; i < q; i++) {
        scanf("%d", &u);
        printf("%d\n", mem[u]);
    }
    return 0;
}