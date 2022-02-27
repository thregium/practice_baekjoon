#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 0 이상 100000 이하의 두 정수 N, M과 2 이상 30 이하의 자연수 A, B가 주어질 때,
N에 다음 연산을 몇 회 해야 M이 되는 지 구한다.
N에 1을 더하거나 빼기, A, B를 더하거나 빼거나 곱하기의 8가지 연산이 가능하다.
단, 중간에 나오는 수가 0 미만 또는 100000 초과가 되어서는 안 된다.

해결 방법 : 중간 수의 범위가 명확히 정해져 있고 크지 않으므로 BFS를 통해
M까지 이동하는 최단 거리를 구하면 된다. 1을 더하거나 빼는 연산이 있으므로 항상 M으로 이동이 가능하다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 전북대 2016 G번
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