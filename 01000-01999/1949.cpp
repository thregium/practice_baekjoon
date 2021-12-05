#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 10000)개의 정점으로 이루어진 트리에서 각 정점의 가중치(<= 10000)가 주어질 때,
인접한 두 정점을 선택하지 않고, 모든 선택하지 않은 정점은 인접한 정점 가운데 하나 이상을 선택하며
얻을 수 있는 최대 가중치를 구한다.

해결 방법 : 트리DP를 이용해 각 정점마다 해당 정점을 선택했을 때와 선택하지 않았을 때의 서브트리의 최대 가중치를 구한다.
선택했을 때는 모든 자식 노드의 선택하지 않았을 때의 서브트리 가중치 합이고,
선택하지 않았을 때는 모든 자식 노드의 서브트리 가중치 합 가운데 더 큰 것이다.
선택하지 않은 정점의 인접한 정점을 모두 선택하지 않았다면 그 정점을 선택하는 것이 항상 더 이득이므로
최적해가 되는 경우 반드시 해당 조건은 만족시키게 되기 때문에 신경 쓸 필요가 없다.

주요 알고리즘 : DP, 트리DP
*/

int people[10240], mem[10240][2];
vector<int> ed[10240];

int big(int a, int b) {
    return a > b ? a : b;
}

void dp(int x, int par) {
    mem[x][1] = people[x];
    for (int i : ed[x]) {
        if (i == par) continue;
        dp(i, x);
        mem[x][0] += big(mem[i][0], mem[i][1]);
        mem[x][1] += mem[i][0];
    }
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &people[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dp(1, -1);
    printf("%d", big(mem[1][0], mem[1][1]));
    return 0;
}