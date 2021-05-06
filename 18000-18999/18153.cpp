#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� ������ �׷����� �ִ�. �� �׷����� �������� 2���� ������ ĥ�ؼ� 1�� �������� N�� ��������
�̵��ϸ� � ��θ� �����ϴ��� ���� �����ϴ� Ƚ���� �ִ������� �Ѵٸ�, �̶��� �� ���� Ƚ���� ���Ѵ�.

�ذ� ��� : �̶��� �� ���� Ƚ���� 1���� N������ �ִܰ���� ���̿��� 1�� �� �Ͱ� ����.
�ִ� ��ο��� ������ ���ư��� ��ε��� �����ϴ��� �ִ� ����� ���� �����ؼ� ĥ�ع����� �ִ� ����� �� ���� Ƚ�� �̻����� �� ���� Ƚ���� �þ�� �����̴�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : PacNW 2019 C��/P��
*/

int vis[103000], dist[103000];
vector<int> edge[103000];
queue<int> q;

int bfs(int a, int b) {
    q.push(a);
    vis[a] = 1;
    while (q.size()) {
        a = q.front();
        q.pop();
        for (int i = 0; i < edge[a].size(); i++) {
            if (vis[edge[a][i]]) continue;
            q.push(edge[a][i]);
            dist[edge[a][i]] = dist[a] + 1;
            vis[edge[a][i]] = 1;
        }
    }
    return dist[b];
}

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    printf("%d", bfs(1, n) - 1);
    return 0;
}