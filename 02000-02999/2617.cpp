#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : 무게가 서로 다른 N(N < 100, 홀수)개의 구슬과 M회의 비교가 주어질 때, 무게가 중앙값이 될 수 없는 구슬의 개수를 구한다.

해결 방법 : 각 구슬에 대해 확실히 더 무거운 구슬의 수와 가벼운 구슬의 수를 각각 구한다. 둘 중 한 가지라도 N / 2보다
큰 값이 나온다면 그 구슬은 중앙값인 구슬이 아니다. 확실히 무거운 구슬은 각 구슬에 대해 더 무거운 구슬의 방향만으로
DFS를 하면 방문하게 되는 구슬들이다. 가벼운 구슬은 그의 반대로 하면 구할 수 있다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : 정올 2003 중1번
*/

vector<int> v1[512], v2[512];
int vis[512];

int dfs1(int a) {
    int r = 1;
    vis[a] = 1;
    for (int i = 0; i < v1[a].size(); i++) {
        if (!vis[v1[a][i]]) r += dfs1(v1[a][i]);
    }
    return r;
}

int dfs2(int a) {
    int r = 1;
    vis[a] = 1;
    for (int i = 0; i < v2[a].size(); i++) {
        if (!vis[v2[a][i]]) r += dfs2(v2[a][i]);
    }
    return r;
}

int main(void) {
    int n, m, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (dfs1(i) - 1 > (n >> 1) || dfs2(i) - 1 > (n >> 1)) r++;
        for (int j = 0; j <= n; j++) vis[j] = 0;
    }
    printf("%d", r);
    return 0;
}