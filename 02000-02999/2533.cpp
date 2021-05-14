#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : 트리에서 몇 개의 정점을 뽑아서 모든 정점이 뽑은 정점이거나 뽑은 정점과 인접하도록 할 때, 뽑아야 할 정점의 최소 개수를 구한다.

해결 방법 : 각 정점을 뽑은 경우와 뽑지 않은 경우로 나누어 생각한다. 해당 정점을 뽑은 경우에는 모든 자식노드에 대해
뽑은 경우와 뽑지 않은 경우 중 더 작은 값을 마음대로 선택해서 합하면 되고, 뽑지 않은 경우에는 모든 자식노드에 대해 뽑은 경우의 합을 구한다.
이를 반복해 루트 노드까지 합을 구한 다음 루트 노드에서 둘 중 더 작은 값을 구하면 된다.

주요 알고리즘 : DP, 트리DP

출처 : 정올 2012지 중4번
*/

int parents[1048576], early[1048576], notearly[1048576];
vector<int> edge[1048576];

int small(int a, int b) {
    return a < b ? a : b;
}

void dfs(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        if (edge[x][i] == parents[x]) continue;
        parents[edge[x][i]] = x;
        dfs(edge[x][i]);
    }
}

void earlyneed(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        if (edge[x][i] == parents[x]) continue;
        earlyneed(edge[x][i]);
    }
    int e = 1;
    int ne = 0;
    for (int i = 0; i < edge[x].size(); i++) {
        if (edge[x][i] == parents[x]) continue;
        e += small(early[edge[x][i]], notearly[edge[x][i]]);
        ne += early[edge[x][i]];
    }
    early[x] = e;
    notearly[x] = ne;
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1);
    earlyneed(1);
    printf("%d", small(early[1], notearly[1]));
    return 0;
}