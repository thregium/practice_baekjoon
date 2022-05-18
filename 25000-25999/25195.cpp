#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 DAG의 1번 정점에서
S(S <= N)개의 주어진 정점 가운데 하나도 지나지 않고 더이상 이동 불가능할 때 까지
이동하는 방법이 있는 지 구한다.

해결 방법 : 플러드필을 통해 1번 정점에서 출발하여 결과를 확인하되, 다이나믹 프로그래밍을 이용하여
한 번 방문한 정점의 결과는 빠르게 알아내도록 하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, DP

출처 : 곰곰컵 1회 E번
*/

int fan[103000], mem[103000];
vector<int> ed[103000];

int avoidable(int x) {
    if (fan[x]) return mem[x] = 0;
    if (ed[x].size() == 0) return mem[x] = 1;
    if (mem[x] >= 0) return mem[x];
    int r = 0;
    for (int i : ed[x]) {
        r |= avoidable(i);
    }
    return mem[x] = r;
}

int main(void) {
    int n, m, f, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) mem[i] = -1;
    scanf("%d", &f);
    for (int i = 0; i < f; i++) {
        scanf("%d", &a);
        fan[a] = 1;
    }
    for (int i = 1; i <= 1; i++) {
        r |= avoidable(i);
    }
    printf("%s", r ? "yes" : "Yes");
    return 0;
}