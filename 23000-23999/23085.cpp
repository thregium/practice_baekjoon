#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 3000)개의 동전이 있다. K(K <= N)개씩의 동전을 뒤집어 가며
모든 동전을 뒷면으로 하기 위해 필요한 뒤집는 횟수의 최솟값을 구한다. 불가능한 경우 -1을 출력한다.

해결 방법 : N이 작으므로 BFS를 통해 앞면의 개수를 바꿔가며 0이 되는 경우까지의 최단 거리를 구하면 된다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 인하대 2021 I번
*/

char s[3072];
int vis[3072], dist[3072];
queue<int> q;

int main(void) {
    int n, k, head = 0;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'H') head++;
    }
    q.push(head);
    vis[head] = 1;
    while (q.size()) {
        head = q.front();
        q.pop();
        for (int i = 0; i <= k; i++) {
            if (head < i || n - head < k - i) continue;
            if (vis[head + k - i * 2]) continue;
            vis[head + k - i * 2] = 1;
            dist[head + k - i * 2] = dist[head] + 1;
            q.push(head + k - i * 2);
        }
    }

    if (vis[0]) printf("%d", dist[0]);
    else printf("-1");
    return 0;
}