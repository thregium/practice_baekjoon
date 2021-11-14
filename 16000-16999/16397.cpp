#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 5자리 이하의 음이 아닌 정수 N, T, G가 주어질 때, N에서 1을 더하거나(99999 이하에서), 2를 곱하고
0이 아닌 가장 앞자리에서 1을 빼는(50000 이하에서) 연산을 T회 이내로 하여 G를 만들 수 있는지 구한다.

해결 방법 : BFS를 통해 두 연산을 하여 나오는 최단거리를 구한 후, G가 방문되었고, T회 이내인지 확인하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 홍익대 2018 D번
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