#include <stdio.h>
#include <vector>
using namespace std;
vector<int> vx[512];
int vis[512], xm[512], ym[512];

/*
문제 : N * N(N <= 500) 크기의 격자의 M(M <= 10000)개의 점을 모두 포함하기 위해서는 행 또는 열이 최소 몇 개 필요한지 구한다.

해결 방법 : 각 행과 열을 정점, 각 점의 위치를 그 점이 위치한 행과 열을 잇는 간선으로 생각한다.
그렇게 되면 해당 점을 포함하기 위해서는 해당 점에 해당하는 간선의 양 끝 중 하나를 가져와야 함을 알 수 있다.
따라서 이는 이분 매칭을 통해 구할 수 있다는 것을 알 수 있다.

주요 알고리즘 : 이분 매칭

출처 : USACO 2005N G1번
*/

int match(int x) {
    vis[x] = 1;
    for (int i = 0; i < vx[x].size(); i++) {
        if (ym[vx[x][i]] == 0 || !vis[ym[vx[x][i]]] && match(ym[vx[x][i]])) {
            xm[x] = vx[x][i];
            ym[vx[x][i]] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, k, x, y, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        vx[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!xm[i]) {
            for (int j = 1; j <= n; j++) vis[j] = 0;
            if (match(i)) r++;
        }
    }
    printf("%d", r);
    return 0;
}