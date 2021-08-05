#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 14)개의 정점에 대해 길이가 정확히 L(L <= 10^15)인 외판원 순회가 있는지 확인한다.

해결 방법 : N!는 매우 크기 때문에 시간 내로 들어오기 어렵다. 따라서, L을 둘로 나누어 시작 정점에서 각 정점으로 이동하는 거리와,
각 정점에서 시작 정점으로 이동하는 거리들을 각각 저장한다. 이때, 합치는 동안 두 경로가 겹치지 않아야 하기 때문에
경로도 저장해야 한다. 하지만 경로의 순서는 필요하지 않고 거쳐간 정점들만 있으면 된다.
거쳐간 정점들은 비트마스킹을 통해 저장해 두면 된다. 여기서 시작 정점의 반대쪽 끝 정점의 위치는 따로 저장한다.

이제 두 경로의 거리를 합친다. 끝 정점이 같으며 경로가 서로 반대인 정점들들을 각각 확인하며 그 중 둘의 합이 정확히 L이 되는
경로가 있는지 확인한다. 만약 그러한 것이 있다면 정확히 L인 순회가 있는 것이고, 없다면 그런 순회가 없는 것이다.

주요 알고리즘 : 그래프 이론, 양방향 탐색, 밋 인 더 미들

출처 : NWERC 2014 I번
*/

long long dists[16][16];

vector<int> check;
vector<long long> upper[16][16384], lower[16][16384];

int checknum(int n) {
    int r = 0;
    for (int i = 0; i < n; i++) r += check[i] << i;
    return r;
}

void tracku(int n, int u, int r, int x, long long l) {
    if (r == u) {
        upper[x][checknum(n)].push_back(l);
        return;
    }
    for (int i = 1; i < n; i++) {
        if (check[i]) continue;
        check[i] = 1;
        tracku(n, u, r + 1, i, l + dists[x][i]);
        check[i] = 0;
    }
}

void trackd(int n, int d, int r, int x, int s, long long l) {
    if (r == d) {
        check[0] = 0;
        lower[s][checknum(n)].push_back(l + dists[x][0]);
        check[0] = 1;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (!check[i] || i == s) continue;
        check[i] = 0;
        trackd(n, d, r + 1, i, s, l + dists[x][i]);
        check[i] = 1;
    }
}

int main(void) {
    int n, u, r = 0;
    long long l;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2014\\indoorienteering\\data\\secret\\16-small-impossible.in", "r", stdin);
    scanf("%d %lld", &n, &l);
    u = (n >> 1);
    for (int i = 0; i < n; i++) {
        check.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &dists[i][j]);
        }
    }
    tracku(n, u, 0, 0, 0);
    for (int i = 0; i < n; i++) check[i] = 1;
    for (int i = 1; i < n; i++) trackd(n, n - u - 1, 0, i, i, 0);
    for (int i = 1; i < n; i++) {
        for (int u1 = 0; u1 < (1 << n); u1++) {
            for (long long u2 : upper[i][u1]) {
                for (long long d2 : lower[i][u1]) {
                    if (u2 + d2 == l) r = 1;
                }
            }
        }
    }
    if (r) printf("possible");
    else printf("impossible");
    return 0;
}