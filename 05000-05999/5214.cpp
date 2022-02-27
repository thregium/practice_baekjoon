#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� ���� ���� M(M <= 1000)���� ���� �ִ� K(K <= 1000)���� �뼱�� �ִ�.
�̶�, 1�� ������ N�� ������ �� �� �ִ� �� Ȯ���ϰ�, �� �� �ִٸ� ������ �ϴ� ���� �ּ� ������ ���Ѵ�.

�ذ� ��� : �� �뼱�� ��������, ȯ�� ������ �뼱�� ���� ���踦 �������� �����.
�̴� �� ������ ������ �뼱���� ���� �迭�� �����ϸ鼭 ������ �뼱�鿡 ������ ���� ������
�׷����� ���� �� �ִ�. �׷� ����, 1�� ���� ������ ��� �뼱���� ����Ͽ�
N�� ���� ������ ��� �뼱������ ȯ�� Ƚ�� ��� �ּڰ� + 2�� ���ϸ� �ȴ�.
��, N�� 1�� ���� ���� 1�ӿ� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : COCI 12/13#5 4��
*/

int vis[1024], dist[1024];
vector<int> sta[103000], ed[1024];
queue<int> q;

int main(void) {
    int n, k, m, x, r = 103000;
    scanf("%d %d %d", &n, &k, &m);
    if (n == 1) {
        printf("1");
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            for (int ii : sta[x]) {
                ed[ii].push_back(i);
                ed[i].push_back(ii);
            }
            sta[x].push_back(i);
        }
    }
    for (int i : sta[1]) {
        q.push(i);
        vis[i] = 1, dist[i] = 2;
    }
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
                dist[i] = dist[x] + 1;
            }
        }
    }
    for (int i : sta[n]) {
        if (vis[i] && dist[i] < r) r = dist[i];
    }
    printf("%d", r == 103000 ? -1 : r);
    return 0;
}