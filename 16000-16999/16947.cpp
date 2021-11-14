#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : ���� N(N <= 3000)���� ����Ŭ�� 1�� �ִ� �׷����� �־�����. �� �������� ����Ŭ������ �Ÿ��� ���Ѵ�.

�ذ� ��� : DFS�� ���� ����Ŭ�� ���ϴ� �������� ã�Ƴ� ����, �� ������� BFS�� �Ͽ� ����Ŭ������ �Ÿ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, DFS, BFS, Ʈ��
*/

int cy = 0, chk[3200], vis[3200], dist[3200];
vector<int> ed[3200];
queue<int> q;

void track(int x, int l) {
    chk[x] = 1;
    for (int i : ed[x]) {
        if (i == l) continue; //���� ������ ��� ����
        if (chk[i]) {
            cy = i; //����Ŭ�� ���� Ȯ��, 0���� ó������ �ʴ� ����
            return;
        }
        track(i, x);
        if (cy) {
            if (x == cy) cy = 0; //����Ŭ�� ���� Ȯ��, ���ķδ� 0���� ó��
            return;
        }
    }
    chk[x] = 0;
}

void bfs(void) {
    int x;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            dist[i] = dist[x] + 1;
            q.push(i);
        }
    }
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    track(1, -1);
    for (int i = 1; i <= n; i++) {
        if (chk[i]) {
            q.push(i);
            vis[i] = 1;
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    return 0;
}