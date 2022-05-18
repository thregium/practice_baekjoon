#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� ������ M(M <= 100000)���� ��Ʈ�� �ִ�. �� ��Ʈ�� ������ �־��� ��,
��Ʈ�� ���� ��ġ�� �� ���Ѵ�.

�ذ� ��� : �� ������ ���� ������ ���� ������ ���Ƿ� ���� ����, ���� ��Ʈ�� ���� ����, ���� ��Ʈ��
�ݴ� �������� �Ͽ� �������� ������ ���� ������. �� �������� �ϰ����� �����ٸ� �߸��� ��ġ�̰�,
������ �ʴ´ٸ� ���� ��ġ�̴�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : JPOI 2010 3-0��
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