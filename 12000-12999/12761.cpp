#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : 0 �̻� 100000 ������ �� ���� N, M�� 2 �̻� 30 ������ �ڿ��� A, B�� �־��� ��,
N�� ���� ������ �� ȸ �ؾ� M�� �Ǵ� �� ���Ѵ�.
N�� 1�� ���ϰų� ����, A, B�� ���ϰų� ���ų� ���ϱ��� 8���� ������ �����ϴ�.
��, �߰��� ������ ���� 0 �̸� �Ǵ� 100000 �ʰ��� �Ǿ�� �� �ȴ�.

�ذ� ��� : �߰� ���� ������ ��Ȯ�� ������ �ְ� ũ�� �����Ƿ� BFS�� ����
M���� �̵��ϴ� �ִ� �Ÿ��� ���ϸ� �ȴ�. 1�� ���ϰų� ���� ������ �����Ƿ� �׻� M���� �̵��� �����ϴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ���ϴ� 2016 G��
*/

int vis[103000], dist[103000];
queue<int> q;

int isvalid(int x) {
    if (x < 0 || x > 100000) return 0;
    if (vis[x]) return 0;
    return 1;
}

int bfs(int a, int b, int n, int m) {
    q.push(n);
    vis[n] = 1;
    while (q.size()) {
        n = q.front();
        q.pop();
        if (isvalid(n + 1)) {
            q.push(n + 1);
            vis[n + 1] = 1;
            dist[n + 1] = dist[n] + 1;
        }
        if (isvalid(n - 1)) {
            q.push(n - 1);
            vis[n - 1] = 1;
            dist[n - 1] = dist[n] + 1;
        }
        if (isvalid(n + a)) {
            q.push(n + a);
            vis[n + a] = 1;
            dist[n + a] = dist[n] + 1;
        }
        if (isvalid(n - a)) {
            q.push(n - a);
            vis[n - a] = 1;
            dist[n - a] = dist[n] + 1;
        }
        if (isvalid(n + b)) {
            q.push(n + b);
            vis[n + b] = 1;
            dist[n + b] = dist[n] + 1;
        }
        if (isvalid(n - b)) {
            q.push(n - b);
            vis[n - b] = 1;
            dist[n - b] = dist[n] + 1;
        }
        if (isvalid(n * a)) {
            q.push(n * a);
            vis[n * a] = 1;
            dist[n * a] = dist[n] + 1;
        }
        if (isvalid(n * b)) {
            q.push(n * b);
            vis[n * b] = 1;
            dist[n * b] = dist[n] + 1;
        }
    }
    return dist[m];
}

int main(void) {
    int a, b, n, m;
    scanf("%d %d %d %d", &a, &b, &n, &m);
    printf("%d", bfs(a, b, n, m));
    return 0;
}