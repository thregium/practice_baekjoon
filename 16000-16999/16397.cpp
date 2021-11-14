#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : 5�ڸ� ������ ���� �ƴ� ���� N, T, G�� �־��� ��, N���� 1�� ���ϰų�(99999 ���Ͽ���), 2�� ���ϰ�
0�� �ƴ� ���� ���ڸ����� 1�� ����(50000 ���Ͽ���) ������ Tȸ �̳��� �Ͽ� G�� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : BFS�� ���� �� ������ �Ͽ� ������ �ִܰŸ��� ���� ��, G�� �湮�Ǿ���, Tȸ �̳����� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ȫ�ʹ� 2018 D��
*/

int vis[103000], dist[103000];
queue<int> q;

void bfs(int x) {
    int y;
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        if (x < 99999) {
            if (!vis[x + 1]) {
                q.push(x + 1);
                dist[x + 1] = dist[x] + 1;
                vis[x + 1] = 1;
            }
        }
        if (x < 50000) {
            y = x * 2;
            if (y >= 10000) y -= 10000;
            else if (y >= 1000) y -= 1000;
            else if (y >= 100) y -= 100;
            else if (y >= 10) y -= 10;
            else if (y >= 1) y--;
            if (!vis[y]) {
                q.push(y);
                dist[y] = dist[x] + 1;
                vis[y] = 1;
            }
        }
    }
}

int main(void) {
    int n, t, g;
    scanf("%d %d %d", &n, &t, &g);
    bfs(n);
    if (!vis[g] || dist[g] > t) printf("ANG");
    else printf("%d", dist[g]);
    return 0;
}