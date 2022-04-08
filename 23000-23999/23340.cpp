#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 200000)개의 정점으로 이루어진 트리가 있다. 트리의 각 간선에 값(<= 10^9)이 주어지면
값이 올라가는 순서대로 이동하는 경로의 개수를 구한다. 단, 간선을 1개 이상 지나야 한다.
또한, 연속하여 값이 같아서도 안 된다.

해결 방법 : 각 정점마다 해당 정점을 출발지로 하는 내려가는 경로와 도착지로 하는 올라오는 경로의
개수를 매번 저장해둔다. 단, 이 개수는 더 위로 올라올 수 있는 경로만 포함해야 한다.
각 정점에서 올라오는 경로는 모든 아래 정점의 올라오는 경로 수 + 1이 된다. 이 과정에서 부모 정점으로
올라가는 간선의 값보다 작은 값으로 올라오는 경로만을 이번 정점의 경로에 추가한다.
내려가는 경로도 비슷한 방식으로 구할 수 있다. 대신 부모 간선보다 큰 값으로 내려가는 경로만을 추가한다.
또한, 각 정점마다 해당 정점을 지나서 내려가는 경로들도 구한다.
이는 각 아래 정점들마다 더 작은 간선에서 올라와서 더 큰 간선으로 내려가는 간선의 경로 개수 곱의 합을
구하는 방식으로 풀 수 있다. 이는 간선의 값을 오름차순으로 정렬한 다음 누적 합을 이용하는 방식으로
계산하면 O(N)에 모든 정점에 대해 구할 수 있다. 단, 이 과정에서 같은 값인 간선에 유의한다.

주요 알고리즘 : DP, 트리DP, 정렬

출처 : TOPC 2021 G번
*/

int mem[204800][2];
vector<pair<int, int>> ed[204800], chd[204800];
pair<int, int> par[204800];
long long res = 0;

void mktree(int x, int p) {
    for (auto& i : ed[x]) {
        if (i.second == p) continue;
        chd[x].push_back(i);
        par[i.second] = { i.first, x };
        mktree(i.second, x);
    }
}

void dp(int x) {
    long long up = 0, down = 0, last = -1;
    for (auto& i : chd[x]) {
        dp(i.second);
        up += mem[i.second][0] + 1;
        if (x != 1 && i.first < par[x].first) mem[x][0] += mem[i.second][0] + 1;
        down += mem[i.second][1] + 1;
        if (x != 1 && i.first > par[x].first) mem[x][1] += mem[i.second][1] + 1;
    }
    res += up + down;
    up = 0;
    for (auto& i : chd[x]) {
        if (i.first != last) {
            res += up * down;
            up = 0;
        }
        up += mem[i.second][0] + 1;
        down -= mem[i.second][1] + 1;
        last = i.first;
    }
}

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back({ c, b });
        ed[b].push_back({ c, a });
    }
    mktree(1, -1);
    for (int i = 1; i <= n; i++) {
        sort(chd[i].begin(), chd[i].end());
    }

    dp(1);
    printf("%lld", res);
    return 0;
}