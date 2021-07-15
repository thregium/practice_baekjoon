#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 그래프가 있다. 이 그래프에서 Q개의 정점에서 정보가 출발해 1일째에는
근처 K칸, 2일째에는 정보가 있는 정점의 근처 2 * K칸... i일째에는 근처 i * K칸까지 퍼져나간다고 한다.
각 정점에 정보가 도달하는 날을 구한다.

해결 방법 : 먼저 BFS로 정보가 있는 정점에서 각 지점까지의 거리를 구한 다음 N 이하의 거리에 대해 해당 정점에
정보가 도달하는 시간을 구하고 각 지점의 거리에 대해 도달하는 시간을 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : COCI 19/20#6 2번
*/

int vis[103000], dist[103000], conv[103000];
vector<int> ed[103000];
queue<int> qe;

void bfs(void) {
    int x;
    while (qe.size()) {
        x = qe.front();
        qe.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            dist[i] = dist[x] + 1;
            qe.push(i);
        }
    }
}

int main(void) {
    int n, m, q, k, a, b;
    scanf("%d %d %d %d", &n, &m, &q, &k);
    for (int i = 0; i < q; i++) {
        scanf("%d", &a);
        qe.push(a);
        vis[a] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    bfs();

    for (int i = 1, x = 1; i <= n;) {
        for (int j = 0; j < x * k && i <= n; j++) {
            conv[i++] = x;
        }
        x++;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", conv[dist[i]]);
    }
    return 0;
}