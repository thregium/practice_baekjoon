#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 트리가 주어진다. 각 정점에는 에너지 e_i(e_i <= 100000)인
개미들이 있다. 트리의 각 간선은 10000 이하의 길이이고, 간선을 움직일 때 드는 에너지는 간선의 길이와 같다.
이때, 모든 개미들이 에너지를 최대한 사용해 1번 정점으로 최단거리로 이동한다면
각 개미들이 멈추는 정점의 번호를 각각 출력한다.

해결 방법 : 희소 배열을 이용해 해결 가능하다. 각 지점에서 2^i개 위의 지점과 거기까지의 거리를
저장한 다음, 역순으로 에너지가 되는 대로 올라가면서 올라간 지점을 찾아 출력하면 된다.

주요 알고리즘 : 그래프 이론, 자료 구조, 희소 배열

출처 : 서강대 2017M H번
*/

int eng[103000], par[24][103000];
long long cost[24][103000];
vector<pair<int, int>> ed[103000];

void dfs(int x, int p) {
    for (auto& i : ed[x]) {
        if (i.first == p) continue;
        par[0][i.first] = x;
        cost[0][i.first] = i.second;
        dfs(i.first, x);
    }
}

int main(void) {
    int n, a, b, c, pos;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &eng[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back({ b, c });
        ed[b].push_back({ a, c });
    }
    dfs(1, -1);
    par[0][1] = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (!par[i - 1][j]) par[i][j] = 0;
            else {
                par[i][j] = par[i - 1][par[i - 1][j]];
                cost[i][j] = cost[i - 1][par[i - 1][j]] + cost[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        pos = i;
        for (int j = 20; j >= 0; j--) {
            if (!par[j][pos]) continue;
            if (eng[i] >= cost[j][pos]) {
                eng[i] -= cost[j][pos];
                pos = par[j][pos];
            }
        }
        printf("%d\n", pos);
    }
    return 0;
}