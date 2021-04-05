#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100000)개의 노드를 가진 트리의 간선에 가중치가 주어질 때, 트리에서 거리가 가장 먼 두 지점의 거리를 출력한다.

해결 방법 : 먼저, 임의의 노드를 루트노드르 잡는다. 그 다음 리프노드부터 재귀적으로 해당 노드의 자식 노드들 가운데
가장 거리가 먼 지점과 두 번째로 먼 지점들을 지정한다. 이를 루트 노드까지 반복하면서 둘의 합이 가장 큰 것을 찾으면 된다.

주요 알고리즘 : 다이나믹 프로그래밍, 트리 DP, 트리
*/

vector<pair<int, int>> v[103000];
int p[103000], tree[103000][2];

void dfs1(int a) {
    for (int i = 0; i < v[a].size(); i++) {
        if (v[a][i].first == p[a]) continue;
        p[v[a][i].first] = a;
        dfs1(v[a][i].first);
    }
}

void dfs2(int a) {
    int mx = 0, sc = 0;
    for (int i = 0; i < v[a].size(); i++) {
        if (v[a][i].first == p[a]) continue;
        dfs2(v[a][i].first);
        if (tree[v[a][i].first][0] + v[a][i].second > mx) {
            sc = mx;
            mx = tree[v[a][i].first][0] + v[a][i].second;
        }
        else if (tree[v[a][i].first][0] + v[a][i].second > sc) sc = tree[v[a][i].first][0] + v[a][i].second;
    }
    tree[a][0] = mx;
    tree[a][1] = mx + sc;
}

int main(void) {
    int n, a, b, c, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        while (1) {
            scanf("%d", &b);
            if (b < 0) break;
            scanf("%d", &c);
            v[a].push_back(pair<int, int>(b, c));
        }
    }
    dfs1(1); //1번 노드를 루트노드로 잡음
    dfs2(1);
    for (int i = 0; i <= n; i++) {
        if (tree[i][1] > mx) mx = tree[i][1];
    }
    printf("%d", mx);
    return 0;
}