#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 300000)���� ���°� M(M <= 300000)���� ���� ������ �� �� ���� ���� �ֵ��� �־��� ��,
������ �� �������� ���� �� �ִ� �� ���θ� ���Ѵ�.

�ذ� ��� : �̺� �׷��� ���θ� ���� �����̴�. ����, BFS�� ���� ������ ������ ���� ����Ǵ� ��찡 ���ٸ� YES��,
����Ǵ� ��찡 �ִٸ� NO�� ����ϸ� �ȴ�. �̶�, �׷����� ����׷����� �ƴ� �� ������ �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �̺� �׷���
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