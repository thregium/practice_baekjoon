#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : 'O'�� �׷��� ī��� 'X'�� �׷��� ī�尡 ���� N(N <= 5)���� �־��� ������� ���� �ִ�.
�̶�, �� ���������� Ȧ�� ��° ī��� ¦�� ��° ī�� �� Ȧ�� ��° ī�忡 'X'�� �� ������ �ϱ� ���ؼ�
������ ��ġ�� �ִ� ī�带 �� ���� �ø��� �۾��� �ּ� �� ȸ �ؾ� �ϴ� �� ���Ѵ�.

�ذ� ��� : �� ��°�� ī�带 ��Ʈ�� ������ ����, �� ī���� �������� Ȯ���� �����鼭
BFS�� �Ѵ�. �׸��� �ٽ� �湮�� ���� ��� ���ǿ� �´� �����̰� �� �� �۾� Ƚ���� �ּ��� ���� ���� �ȴ�.
���� ���� �� �Ұ����� ���� ���� �� ����.

�ֿ� �˰��� : �׷��� �̷�, BFS, ��Ʈ����ŷ

��ó : ������ 2021 C��
*/

int vis[1024], dist[1024], tmp[16];
queue<int> q;

void bfs(int n, int x) {
    int t;
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 1; i < n * 2; i++) {
            t = ((x >> i) & 1) + ((x << 1) & ((2 << i) - 1)) + ((x >> (i + 1)) << (i + 1));
            if (!vis[t]) {
                vis[t] = 1;
                dist[t] = dist[x] + 1;
                q.push(t);
            }
        }
    }
}

int main(void) {
    int n, x = 0, r = 103000;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf(" %c", &c);
        x += (1 << i) * (c == 'O');
    }
    bfs(n, x);
    for (int i = 0; i < (1 << (n * 2)); i++) {
        if (!vis[i]) continue;
        x = 0;
        for (int j = 0; j < n * 2; j += 2) x += ((i >> j) & 1);
        if (x > (n >> 1) && dist[i] < r) r = dist[i];
    }
    if (r == 103000) return 1;
    printf("%d", r);
    return 0;
}