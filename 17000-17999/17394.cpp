#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 10^6)���� ������ 2�� �����ų� 3���� �����ų�(������� ��� ���� ����) 1�� ���ų�
1�� ���ϴ� ������ �ݺ��Ͽ� [A, B](A <= B <= 100000) ������ �Ҽ��� �ǵ��� �ϴ�
���� ���� ���� Ƚ���� ���Ѵ�. �׷��� ����� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : BFS�� ���� N�������� 200�� ������ �� �������� �ִܰŸ��� ���Ѵ�.
�� �� A���� B ������ ��ó���� �Ҽ� ��� ���� �Ÿ��� ª�� �� ������ �Ÿ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �����佺�׳׽�

��ó : ������ 2019 G��
*/

int dist[2097152];
char vis[2097152], sieve[103000];
queue<int> q;

void bfs(int n) {
    q.push(n);
    vis[n] = 1;
    while (q.size()) {
        n = q.front();
        q.pop();
        if (!vis[n >> 1]) {
            vis[n >> 1] = 1;
            dist[n >> 1] = dist[n] + 1;
            q.push(n >> 1);
        }
        if (!vis[n / 3]) {
            vis[n / 3] = 1;
            dist[n / 3] = dist[n] + 1;
            q.push(n / 3);
        }
        if (n - 1 >= 0 && !vis[n - 1]) {
            vis[n - 1] = 1;
            dist[n - 1] = dist[n] + 1;
            q.push(n - 1);
        }
        if (n + 1 <= 2000000 && !vis[n + 1]) {
            vis[n + 1] = 1;
            dist[n + 1] = dist[n] + 1;
            q.push(n + 1);
        }
    }
}

int main(void) {
    int t, n, a, b, res;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 100000; j += i) sieve[j] = 1;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &n, &a, &b);
        bfs(n);
        res = 1030000;
        for (int i = a; i <= b; i++) {
            if (sieve[i]) continue;
            if (vis[i] && dist[i] < res) res = dist[i];
        }
        if (res == 1030000) printf("-1\n");
        else printf("%d\n", res);
        
        for (int i = 0; i < 2097152; i++) {
            dist[i] = 0;
            vis[i] = 0;
        }
    }
    return 0;
}