#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 10000)가지 백신을 접종받아야 한다. M(M <= 100000)개의 선행 관계가 주어질 때,
모든 접종을 맞기 위해 필요한 날 수를 구한다. 각 백신의 선행 관계 사이에는 최소 대기 기간이 있고,
7일의 유효 기간이 있다. 유효 기간이 지나면 이전 백신을 재접종해야 한다.

해결 방법 : 위상 정렬을 하면서 그 순서대로 각 정점의 도달 시간을 구해 준다.
단, 이 과정에서 7일이 넘는 간선의 경우 1을 더해주어야 한다. 최종적으로 전체 정점 가운데 가장 늦게
끝나는 정점의 일 수를 구하면 된다.

주요 알고리즘 : 그래프 이론, 위상 정렬

출처 : 가톨릭대 4회 D번
*/

int ins[10240], vis[10240], mem[10240];
vector<pair<int, int>> ed[10240];
queue<int> q;

int main(void) {
    int n, m, s, e, w, res = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &s, &e, &w);
        ed[s].push_back({ e, w });
        ins[e]++;
    }
    for (int i = 1; i <= n; i++) {
        mem[i] = 0;
        if (!ins[i]) {
            q.push(i);
            vis[i] = 1;
            mem[i] = 1;
        }
    }
    while (q.size()) {
        s = q.front();
        q.pop();
        for (auto& i : ed[s]) {
            ins[i.first]--;
            if (mem[s] + i.second + (i.second >= 7) > mem[i.first]) {
                mem[i.first] = mem[s] + i.second + (i.second >= 7);
            }
            if (!ins[i.first] && !vis[i.first]) {
                q.push(i.first);
                vis[i.first] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mem[i] > res) res = mem[i];
    }
    if (res < 0) return 1;
    printf("%d", res);
    return 0;
}