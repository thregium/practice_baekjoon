#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 2000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 그래프에서 특정 정점을 지우면 인접한 모든 정점도
같이 지워진다고 한다. 이때, 지울 정점의 목표들이 주어지면 그렇게 지울 수 있는 지, 그러하다면 지우는 방법을 출력한다.

해결 방법 : 지울 수 있는(인접한 정점 가운데 지우면 안 되는 정점이 없는) 정점들을 모두 지워본 다음,
지워야 할 정점이 모두 지워졌는지 살핀다. 지워지지 않은 정점이 있다면 그렇게 지우는 방법이 없는 것이고,
없다면 그렇게 지우는 방법 중 하나로 지금 지운 방법이 있는 것이다.

주요 알고리즘 : 그래프 이론, 그리디 알고리즘, 구성적

출처 : 인천대 2019 D번
*/

int dtr[2048], vis[2048], res[2048];
vector<int> ed[2048];

int main(void) {
    int n, m, k, u, v, t = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &u);
        dtr[u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!dtr[i]) continue;
        u = 0;
        for (int j : ed[i]) {
            if (!dtr[j]) {
                u = 1;
                break;
            }
        }
        if (!u) {
            res[t++] = i;
            vis[i] = 1;
            for (int j : ed[i]) vis[j] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dtr[i] != vis[i]) t = -1;
    }
    printf("%d\n", t);
    for (int i = 0; i < t; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}