#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : 정점의 수가 N(N <= 500000)개인 루트가 1인 트리에서 모든 잎 정점에 말들이 놓여 있다.
각 턴마다 임의의 말을 골라 1칸 위로 올리는 것을 두 명이 반복하고, 더이상 말을 움직일 수 없는 사람이 진다면
선공이 이길 수 있는 지 구한다.

해결 방법 : 항상 1단계 전의 정점으로만 이동하기 때문에 이동할 수 없을 때 까지 턴의 수는
모든 잎 정점의 차수(뿌리 정점의 차수가 0일 때)와 같다.
따라서, 이 값을 플러드필을 통해 구한 다음, 홀수인 경우 이기고 짝수인 경우 진다고 하면 된다.

주요 알고리즘 : 그래프 이론, 트리, 플러드필, 게임 이론?

출처 : UCPC 2018예 D번
*/

vector<int> ed[524288];

long long dfs(int x, int d, int p) {
    int c = 0;
    long long r = 0;
    for (int i : ed[x]) {
        if (i == p) continue;
        r += dfs(i, d + 1, x);
        c++;
    }
    if (c == 0) return d;
    else return r;
}

int main(void) {
    int n, a, b;
    long long r;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    r = dfs(1, 0, -1);
    if (r & 1) printf("Yes");
    else printf("No");
    return 0;
}