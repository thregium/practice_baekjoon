#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 300000)개의 세력과 M(M <= 300000)개의 같은 동맹이 될 수 없는 세력 쌍들이 주어질 때,
세력을 두 동맹으로 나눌 수 있는 지 여부를 구한다.

해결 방법 : 이분 그래프 여부를 묻는 문제이다. 따라서, BFS를 통해 세력을 나누어 가며 모순되는 경우가 없다면 YES를,
모순되는 경우가 있다면 NO를 출력하면 된다. 이때, 그래프가 연결그래프가 아닐 수 있음에 유의한다.

주요 알고리즘 : 그래프 이론, BFS, 이분 그래프
*/

int color[327680];
vector<int> ed[327680];
queue<int> q;

int bfs(int x) {
    color[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (color[i] == color[x]) return 0;
            if (color[i] == 0) {
                color[i] = (!(color[x] - 1)) + 1;
                q.push(i);
            }
        }
    }
    return 1;
}

int main(void) {
    int t, n, m, x, y, res;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        res = 1;
        for (int i = 1; i <= n; i++) {
            if (!color[i]) res &= bfs(i);
        }
        printf("%s\n", res ? "YES" : "NO");
        for (int i = 1; i <= n; i++) {
            ed[i].clear();
            color[i] = 0;
        }
        while (q.size()) q.pop();
    }
    return 0;
}