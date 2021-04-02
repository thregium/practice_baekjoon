#include <stdio.h>
#include <vector>
using namespace std;

vector<pair<int, int>> v[10240];
int tree[10240][2];

void dfs(int a) {
    int mx = 0, sc = 0;
    for (int i = 0; i < v[a].size(); i++) {
        dfs(v[a][i].first);
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
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(pair<int, int>(b, c));
    }
    dfs(1);
    for (int i = 0; i <= n; i++) {
        if (tree[i][1] > mx) mx = tree[i][1];
    }
    printf("%d", mx);
    return 0;
}