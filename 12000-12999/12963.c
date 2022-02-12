#include <stdio.h>
#define MOD 1000000007

/*
문제 : N(N <= 2000)개의 정점과 M(M <= 2000)개의 간선으로 이루어진 양방향 그래프에서
각 주어지는 i번째의 간선은 3^(i - 1)의 용량을 갖는다. 이때, 0번 정점에서 N - 1번 정점으로 흐를 수 있는
최대 유량을 구한다.

해결 방법 : 수와 그래프가 지나치게 크기 때문에 최대 유량을 직접 구하기는 어렵다.
그런데, 여기서 0번째 간선부터 p - 1번째 간선까지의 용량 합이 p번째 용량보다 작다는 것을 알 수 있으므로
큰 용량부터 유량을 구해나가는 것이 가능하다. M - 1번 간선부터 역순으로 해당 간선 이후로 나온 간선들만
갖고 플러드필을 통해 0번에서 N - 1번으로 이동 가능한 지 확인한다. 가능한 경우 해당 간선을 지우고
답에 해당 간선의 용량을 더해나간다. 이를 반복하면 모든 유량이 최대한으로 흐르는 간선의
유량 합을 구할 수 있고, 이것이 답이 된다.

주요 알고리즘 : 그래프 이론, 그리디 알고리즘, 플러드필, 플로우
*/

int edc[2048], ed[2048][2048][2], vis[2048], b3[2048];

int dfs(int x, int l, int n) {
    vis[x] = 1;
    if (x == n - 1) {
        return 1;
    }
    int r = 0;
    for (int i = 0; i < edc[x]; i++) {
        if (ed[x][i][1] < l || vis[ed[x][i][0]]) continue;
        else r |= dfs(ed[x][i][0], l, n);
    }
    return r;
}

int main(void) {
    int n, m, a, b, r = 0;
    b3[0] = 1;
    for (int i = 1; i <= 2000; i++) b3[i] = (b3[i - 1] * 3LL) % MOD;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a][edc[a]][0] = b;
        ed[a][edc[a]++][1] = i;
        ed[b][edc[b]][0] = a;
        ed[b][edc[b]++][1] = i;
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) vis[j] = 0;
        if (dfs(0, i, n)) {
            r = (r + b3[i]) % MOD;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < edc[j]; k++) {
                    if (ed[j][k][1] == i) ed[j][k][1] = -1;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}