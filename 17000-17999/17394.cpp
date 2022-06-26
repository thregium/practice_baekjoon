#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 10^6)에서 시작해 2로 나누거나 3으로 나누거나(나누기는 모두 몫을 취함) 1을 빼거나
1을 더하는 연산을 반복하여 [A, B](A <= B <= 100000) 사이의 소수가 되도록 하는
가장 적은 연산 횟수를 구한다. 그러한 방법이 없다면 -1을 출력한다.

해결 방법 : BFS를 통해 N에서부터 200만 이하의 각 수까지의 최단거리를 구한다.
그 후 A에서 B 사이의 전처리된 소수 가운데 가장 거리가 짧은 것 까지의 거리를 구하면 된다.

주요 알고리즘 : 그래프 이론, BFS, 에라토스테네스

출처 : 숭고한 2019 G번
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