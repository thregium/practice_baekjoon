#include <stdio.h>
#include <tuple>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100)개의 정점으로 된 그래프를 칠해야 한다. 칠해야 하는 간선은 삼원색을 통해 칠할 수 있다.
정점 위의 삼원색을 각각 움직여가며 칠할 수 있지만, 칠하지 않고 지나갈 수는 없다.
또한, 혼합된 색인 경우에는 삼원색이 동시에 같은 방향으로 움직여야만 칠할 수 있다고 할 때, 모든 간선을 원하는대로 칠할 수 있는지 구한다.

해결 방법 : 그래프 위의 삼원색의 위치를 정점으로 보고 삼원색이 움직이는 것을 간선으로 본다.
삼원색 각각을 움직일 수 있는 간선으로 움직여가며 전체를 칠해본 다음, 색칠해야 하는 모든 간선이 칠해졌으면 칠할 수 있는 것이고,
칠해지지 않은 간선이 있다면 칠할 수 없는 것이다. 여기서 혼합색인 경우에는 두 정점이 같은 위치에 있는 경우 동시에 움직여야 하고,
간선의 정보를 확인하기 때문에 간선에 간선 번호 등을 추가하는 것이 좋다.

주요 알고리즘 : 그래프 이론, DFS

출처 : PacNW 2020 C/T번 // MidC 2020 E번 // MidA 2020 G번
*/

char vis[128][128][128], evis[10240];
vector<tuple<int, int, char>> cor[128];
vector<int> goal;

void dfs(int r, int y, int b, int c) {
    if (c >= 0) evis[c] = 1;
    if (vis[r][y][b]) return;
    vis[r][y][b] = 1;
    char ch;
    for (int i : vector<int>({ r, y, b })) {
        for (auto j : cor[i]) {
            ch = get<2>(j);
            if ((ch == 'R' || ch == 'X') && i == r) dfs(get<1>(j), y, b, get<0>(j));
            else if ((ch == 'Y' || ch == 'X') && i == y) dfs(r, get<1>(j), b, get<0>(j));
            else if ((ch == 'B' || ch == 'X') && i == b) dfs(r, y, get<1>(j), get<0>(j));
            else if (ch == 'O' && i == r && i == y) dfs(get<1>(j), get<1>(j), b, get<0>(j));
            else if (ch == 'P' && i == r && i == b) dfs(get<1>(j), y, get<1>(j), get<0>(j));
            else if (ch == 'G' && i == y && i == b) dfs(r, get<1>(j), get<1>(j), get<0>(j));
        }
    }
}

int main(void) {
    int n, m, r, b, y, xi, xj, res = 1;
    char c;
    scanf("%d %d %d %d %d", &n, &m, &r, &b, &y);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &xi, &xj, &c);
        cor[xi].push_back(make_tuple(i, xj, c));
        cor[xj].push_back(make_tuple(i, xi, c));
        if (c != 'X') goal.push_back(i);
    }
    dfs(r, y, b, -1);
    for (int i : goal) {
        if (!evis[i]) res = 0;
    }
    printf("%d", res);
    return 0;
}