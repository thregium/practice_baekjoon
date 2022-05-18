#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 두 점 N, K(0 <= N, K <= 500000)가 주어진다. N에 있는 점을 +1, -1, *2의 위치로 한 번에 해당 칸씩
움직이는 것이 가능할 때, K에 있는 점을 잡기 위해 필요한 최소 이동 횟수를 구한다.
단, 이동은 0 미만 또는 500000 초과 지점으로 갈 수 없다. 또한, K는 매 번 1, 2, 3, ... 씩 +방향으로 움직인다.

해결 방법 : 각 점에 도달하면 2회 내로 다시 도달 가능하기 때문에(+1, -1) 각 점에 도달하는 거리가
홀수일 때와 짝수일 때를 나누어 BFS를 한다. 그 다음, K가 50만을 넘기 전까지 그 전에 N에서의 도달 시간이
더 빠른 경우가 있는 지 확인한다. 도달 시간은 홀짝성을 맞춰준다. 더 빠른 경우가 있다면 그때의 이동 횟수를
출력한다.

주요 알고리즘 : 그래프 이론, BFS, 수학
*/

int dist[524288][2];
char vis[524288][2];
queue<pair<int, int>> q;

void bfs(int x) {
    int p = 0;
    vis[x][p] = 1;
    q.push({ x, p });
    while (q.size()) {
        x = q.front().first;
        p = q.front().second;
        q.pop();
        if (x > 0 && !vis[x - 1][!p]) {
            vis[x - 1][!p] = 1;
            dist[x - 1][!p] = dist[x][p] + 1;
            q.push({ x - 1, !p });
        }
        if (x < 500000 && !vis[x + 1][!p]) {
            vis[x + 1][!p] = 1;
            dist[x + 1][!p] = dist[x][p] + 1;
            q.push({ x + 1, !p });
        }
        if (x * 2 <= 500000 && !vis[x * 2][!p]) {
            vis[x * 2][!p] = 1;
            dist[x * 2][!p] = dist[x][p] + 1;
            q.push({ x * 2, !p });
        }
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    bfs(n);
    for (int i = 0; k <= 500000; i++) {
        if (dist[k][i & 1] <= i) {
            printf("%d", i);
            return 0;
        }
        k += i + 1;
    }
    printf("-1");
    return 0;
}