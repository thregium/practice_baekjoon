#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 200000)개의 정점을 가진 1번 정점이 루트인 트리가 있다. 각 트리의 정점을 원하는 색으로
색칠하려 할 때, 칠하고자 하는 색들이 주어지면 색칠하기 위해 칠해야 하는 최소 횟수를 구한다.
한 정점을 칠하면 그 정점과 모든 자손 정점들이 같은 색으로 칠해진다. 또한, 모든 정점은 처음에
0번 색이고 0번 색으로 이후에 칠할 수는 없다. 항상 칠할 수 있는 경우만 주어진다.

해결 방법 : 루트에서부터 DFS를 통해 트리를 순회하며 색이 달라지는 점마다 그 색으로 색칠하면 된다.
색이 달라지는 곳의 개수를 센 다음 루트 정점(1번)이 색이 있다면 1을 더하면 답이 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 트리

출처 : shake! 2021 C번
*/

int col[204800], vis[204800];
vector<int> ed[204800];

int dfs(int x) {
    int r = 0;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) {
            if (col[i] != col[x]) r++;
            r += dfs(i);
        }
    }
    return r;
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &col[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    printf("%d", dfs(1) + (!!col[1]));
    return 0;
}
