#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 'O'가 그려진 카드와 'X'가 그려진 카드가 각각 N(N <= 5)개씩 주어진 순서대로 놓여 있다.
이때, 맨 위에서부터 홀수 번째 카드와 짝수 번째 카드 중 홀수 번째 카드에 'X'가 더 많도록 하기 위해서
임의의 위치에 있는 카드를 맨 위로 올리는 작업을 최소 몇 회 해야 하는 지 구한다.

해결 방법 : 각 번째의 카드를 비트로 저장한 다음, 각 카드의 움직임을 확인해 나가면서
BFS를 한다. 그리고 다시 방문한 상태 가운데 조건에 맞는 상태이고 그 중 작업 횟수가 최소인 것을 고르면 된다.
문제 조건 상 불가능한 경우는 나올 수 없다.

주요 알고리즘 : 그래프 이론, BFS, 비트마스킹

출처 : 서강대 2021 C번
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