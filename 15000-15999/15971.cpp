#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� Ʈ������ (�� ���� ������ ����� �Ÿ�) - (�� ��ο��� ���� �� ������ ����)�� ���� ���Ѵ�.

�ذ� ��� : �� ���� ������ �Ÿ��� �÷������� ���� ���� ����(Ʈ���̹Ƿ� ���ͽ�Ʈ�� ���� �ʿ� ����), �������� ����
���� ���� ��θ� Ȯ���ϸ� ���� �� ������ ���̸� ���Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ������

��ó : ���� 2018 ��3/��2��
*/

int vis[103000], dist[103000];
vector<pair<int, int>> ed[103000];
queue<int> q;

int bfs(int x, int y) {
    int s = x, e = y, longest = 0;
    q.push(x);
    vis[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < ed[x].size(); i++) {
            if (vis[ed[x][i].first]) continue;
            vis[ed[x][i].first] = 1;
            dist[ed[x][i].first] = dist[x] + ed[x][i].second;
            q.push(ed[x][i].first);
        }
    }

    while (y != s) {
        for (int i = 0; i < ed[y].size(); i++) {
            if (dist[ed[y][i].first] == dist[y] - ed[y][i].second) {
                if (ed[y][i].second > longest) longest = ed[y][i].second;
                y = ed[y][i].first;
                break;
            }
        }
    }
    return dist[e] - longest;
}

int main(void) {
    int n, x, y, a, b, l;
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &l);
        ed[a].push_back(pair<int, int>(b, l));
        ed[b].push_back(pair<int, int>(a, l));
    }
    printf("%d", bfs(x, y));
    return 0;
}