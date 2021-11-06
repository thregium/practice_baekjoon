#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : 값이 모두 다른 N(N <= 100)개의 값에 대해 상대적인 값 비교를 M(M <= 4500)회 했다.
이 비교들로 몇 번째로 큰 값인지 알 수 있는 값의 개수를 구한다.

해결 방법 : 각 값들에서 더 큰 값을 찾고 그 값보다 큰 값, 그것보다 큰 값, ... 방식으로 찾아나가면
해당 값보다 확실히 큰 값들을 알 수 있다. 반대로 더 작은 값을 찾고 반복해서 작은 값들을 찾아나가면
확실히 작은 값들을 알 수 있다. 이를 반복해 이 두 경우로 모든 값을 알 수 있다면 더 큰 값들과 더 작은 값들을
알 수 있는 것이므로 몇 번째로 큰 값인지 알 수 있는 것이다.

따라서, 이를 N개의 값에 대해 반복해 몇 번째 값인지 알 수 있는 값들을 세면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : USACO 2008J S1번
*/

vector<int> v1[512], v2[512];
int vis[512];

void dfs1(int a) {
    vis[a] = 1;
    for (int i = 0; i < v1[a].size(); i++) {
        if (!vis[v1[a][i]]) dfs1(v1[a][i]);
    }
}

void dfs2(int a) {
    vis[a] = 1;
    for (int i = 0; i < v2[a].size(); i++) {
        if (!vis[v2[a][i]]) dfs2(v2[a][i]);
    }
}

int main(void) {
    int n, m, a, b, t, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        dfs1(i);
        dfs2(i);
        t = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) t = 0;
            vis[j] = 0;
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}