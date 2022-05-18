#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 200000)개의 정점과 M(M <= 200000)개의 간선으로 이루어진 연결 그래프가 주어질 때,
이 그래프의 모든 정점을 한 번씩 지나면서 인접한 순서의 정점끼리 거리가 3 이하인 방문 순서를 구해 출력한다.

해결 방법 : 이 그래프를 트리로 바꾼 다음, 임의의 점을 루트로 하고, 높이가 홀수번째인 점은 들어가면서,
짝수번째인 점은 나오면서 방문하면 항상 모든 경우 거리 3 이내로 모든 점을 방문이 가능하다.

주요 알고리즘 : 그래프 이론, DFS, 트리

출처 : BAPC 2021 H번 // UKIEPC 2021 H번
*/

int vis0[204800], vis[204800];
vector<int> ed[204800], tred[204800];

void maketree(int x) {
    vis0[x] = 1;
    for (int i : ed[x]) {
        if (!vis0[i]) {
            tred[x].push_back(i);
            maketree(i);
        }
    }
}

void travel(int x, int p, int l) {
    if ((l & 1) && !vis[x]) {
        printf("%d ", x);
        vis[x]++;
    }
    for (int i : tred[x]) {
        if (i == p) continue;
        travel(i, x, l + 1);
    }
    if (!vis[x]) {
        printf("%d ", x);
        vis[x]++;
    }
}

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    maketree(1);
    travel(1, 0, 1);
    return 0;
}