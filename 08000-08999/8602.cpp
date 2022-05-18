#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 바퀴와 M(M <= 100000)개의 벨트가 있다. 각 벨트의 방향이 주어질 때,
벨트가 옳은 배치인 지 구한다.

해결 방법 : 한 바퀴에 대해 바퀴가 도는 방향을 임의로 정한 다음, 곧은 벨트는 같은 방향, 꼬인 벨트는
반대 방향으로 하여 바퀴들의 방향을 정해 나간다. 이 과정에서 일관성이 깨진다면 잘못된 배치이고,
깨지지 않는다면 옳은 배치이다.

주요 알고리즘 : 그래프 이론, BFS

출처 : JPOI 2010 3-0번
*/

int color[103000];
vector<pair<int, int>> ed[103000];
queue<pair<int, int>> q;

int bfs(int x, int c) {
    int r = 1;
    color[x] = c;
    q.push({ x, c });
    while (q.size()) {
        x = q.front().first;
        c = q.front().second;
        q.pop();
        for (auto& i : ed[x]) {
            if (color[i.first] >= 0) {
                if ((c ^ i.second) != color[i.first]) r = 0;
            }
            else {
                color[i.first] = (c ^ i.second);
                q.push({ i.first, color[i.first] });
            }
        }
    }
    return r;
}

int main(void) {
    int t, n, m, a, b, r;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %c", &a, &b, &c);
            ed[a].push_back({ b, c - 'A' });
            ed[b].push_back({ a, c - 'A' });
        }
        r = 1;
        for (int i = 1; i <= n; i++) color[i] = -1;
        for (int i = 1; i <= n; i++) {
            if (color[i] >= 0) continue;
            r &= bfs(i, 0);
        }
        printf("%s\n", r ? "TAK" : "NIE");

        for (int i = 1; i <= n; i++) {
            ed[i].clear();
        }
    }
    return 0;
}