#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 3000)개의 정점으로 이루어진 그래프에서 모든 간선과 모든 정점을 지나되
같은 간선은 여러 번 지나지 않는 경로가 있는지 구한다.

해결 방법 : 한붓그리기가 가능한지 묻는 문제이다. 이어진 간선의 개수가 홀수인 정점이 2개 이하인 경우 가능하다.
단, 모든 정점들이 같은 연결 요소에 있어야 한다.

주요 알고리즘 : 그래프 이론, 오일러 회로

출처 : 숭실대/중앙대 2018 D번
*/

char vis[3072];
vector<int> ed[3072];

void dfs(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) dfs(i);
    }
}

int main(void) {
    int v, e, va, vb, o = 0;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &va, &vb);
        ed[va].push_back(vb);
        ed[vb].push_back(va);
    }
    for (int i = 1; i <= v; i++) {
        o += (ed[i].size() & 1);
    }
    if (o > 2) {
        printf("NO");
        return 0;
    }
    dfs(1);
    for (int i = 1; i <= v; i++) {
        if (!vis[i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}