#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 무향 무가중치 그래프가 주어질 때,
이 그래프의 정점 S부터 T까지의 경로 가운데 길이가 소수인 것이 있는 지 찾고,
있다면 그 중 가장 작은 소수를 찾는다. S에서 T까지의 경로는 항상 존재한다.
경로 중간에 같은 간선을 여러 번 이용할 수 있다.

해결 방법 : 홀수 사이클을 이용하지 않는 이상 어떤 정점에서 그 정점으로 돌아오는 경로는
항상 길이가 짝수가 된다. 임의의 경로를 왔다 가면 길이 2이므로
2 이상의 모든 짝수 거리를 더할 수 있는 것이다.

이를 이용하면 S에서 T까지의 경로 길이가 홀수인 경우와 짝수인 경우를 나누고 둘 중 소수가 나올 수 있는
경우를 찾아나가면 된다. 짝수에서 소수가 나올 수 있는 경우는 2일 때 뿐이고,
홀수에서는 무한정 많다. (물론 경로의 길이가 N * 2이므로 N * 2보다 큰 가장 작은 소수 값 까지만 보면 된다.)
홀수일 때의 경로와 짝수일 때의 경로는 정점을 홀수, 짝수 거리 2개로 나누어 BFS하면 된다.

최종적으로 T로 가는 최단 거리가 2 이하인 짝수 경로가 있는 경우 답은 2,
홀수 경로가 있는 경우 답은 홀수 경로의 길이 이상인 가장 작은 소수, 둘 다 없는 경우 그러한 경로는 없다.

주요 알고리즘 : 그래프 이론, BFS, 정수론, 소수 판정

출처 : JAG 2018S3 J번
*/

char sieve[103000 * 2];
int vis[103000][2], dist[103000][2];
vector<int> ed[103000];
queue<int> q;

void bfs(int x) {
    int r = 1, y;
    vis[x][0] = 1;
    q.push(x * 2);
    while (q.size()) {
        x = q.front() >> 1;
        y = (q.front() & 1);
        q.pop();
        for (int i : ed[x]) {
            if (vis[i][!y]) continue;
            vis[i][!y] = 1;
            dist[i][!y] = dist[x][y] + 1;
            q.push((i << 1) + (!y));
        }
    }
}

int main(void) {
    int n, m, s, t, u, v, r;
    sieve[0] = 1, sieve[1] = 1;
    for (int i = 2; i < 103000 * 2; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j < 103000 * 2; j += i) sieve[j] = 1;
    }
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    bfs(s);
    if (vis[t][0] && dist[t][0] <= 2) printf("2\n");
    else if (vis[t][1]) {
        r = dist[t][1];
        for (int i = r;; i += 2) {
            if (!sieve[i]) {
                printf("%d\n", i);
                break;
            }
        }
    }
    else printf("-1\n");
    return 0;
}