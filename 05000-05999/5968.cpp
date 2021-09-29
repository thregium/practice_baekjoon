#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

/*
���� : �� ���� K(K <= 50)�� ������ ���·� �������� �ִ�. �� �������� ���� �Ʒ����� �� -> ���������� �ö󰡸� ��ȣ�� �ٴ´�.
�̶�, H���� �������� �Ÿ��� L�� ������ ������������ ����Ѵ�.

�ذ� ��� : ��� �����鿡 ���� ������ �������� ����� ���� �������ش�. (�ڼ��� ������ �ڵ� ����)
�� ����, H�� �������� BFS�� ���� ��, �Ÿ��� L�� �������� ��� ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ����

��ó : USACO 2011F B3��
*/

int vis[8192], dist[8192];
vector<int> adj[8192], res;
queue<int> q;

void bfs(int x) {
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : adj[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                dist[i] = dist[x] + 1;
                q.push(i);
            }
        }
    }
}

int main(void) {
    int k, h, l, x = 1;
    scanf("%d %d %d", &k, &h, &l);
    //���� �ٵ��� ���� �߰�
    for (int i = k; i < k * 2 - 1; i++) {
        //x�� �̹� ���� ù ��
        for (int j = x; j < x + i; j++) {
            if (j > x) {
                adj[j].push_back(j - 1); // |����
                adj[j - 1].push_back(j);
            }
            adj[j].push_back(j + i); // /����
            adj[j + i].push_back(j);
            adj[j].push_back(j + i + 1); // \����
            adj[j + i + 1].push_back(j);
        }
        x += i;
    }

    //������ �ٵ��� ���� �߰�
    x = k * (k - 1) * 3 + 1;
    for (int i = k; i < k * 2 - 1; i++) {
        //x�� �̹� ���� ������ ��
        for (int j = x; j > x - i; j--) {
            if (j < x) {
                adj[j].push_back(j + 1); // |����
                adj[j + 1].push_back(j);
            }
            adj[j].push_back(j - i); // /����
            adj[j - i].push_back(j);
            adj[j].push_back(j - i - 1); // \����
            adj[j - i - 1].push_back(j);
        }
        x -= i;
    }

    //��� �� ���� �߰�
    for (int i = 2; i < k * 2; i++) {
        adj[x - 1].push_back(x); // |����
        adj[x].push_back(x - 1);
        x--;
    }

    //BFS�� ��� Ȯ��
    bfs(h);
    for (int i = 1; i <= (k * (k - 1) * 3 + 1); i++) {
        if (dist[i] == l) res.push_back(i);
    }
    printf("%d\n", res.size());
    for (int i : res) {
        printf("%d\n", i);
    }
    return 0;
}