#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 10000)개의 정점으로 이루어진 트리에서 각 정점의 가중치(<= 10000, 자연수)가 주어질 때,
최대 독립 집합을 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 현재 정점을 선택했을 때와 선택하지 않았을 때의 최댓값을 변수로 둔 다음 풀면 된다.
이를 다시 역추적하여 최대 독립 집합을 구해야 하는데, 이는 부모 노드의 선택 여부를 이용해 구해나가면 된다.
부모 노드를 선택했다면 그 자식 노드는 반드시 선택하지 않아야 한다. 선택하지 않은 경우에는 부모 노드는 자식 노드의
두 경우 가운데 더 큰 값을 기준으로 선택할 것이다. 따라서, 더 큰 경우를 확인해 그 경우가
선택하는 경우일 때만 독립 집합에 추가하면 된다.

주요 알고리즘 : DP, 트리DP, 역추적
*/

int w[10240], mem[10240][2];
vector<int> ed[10240], group;

int big(int a, int b) {
    return a > b ? a : b;
}

void dp(int x, int p) {
    mem[x][1] = w[x];
    for (int i : ed[x]) {
        if (i == p) continue;
        dp(i, x);
        mem[x][0] += big(mem[i][0], mem[i][1]);
        mem[x][1] += mem[i][0];
    }
}

void track(int x, int p, int s) {
    if (s) {
        for (int i : ed[x]) {
            if (i == p) continue;
            track(i, x, 0);
        }
    }
    else {
        int sum = 0;
        if (mem[x][1] > mem[x][0]) group.push_back(x);
        for (int i : ed[x]) {
            if (i == p) continue;
            track(i, x, mem[x][1] > mem[x][0]);
        }
    }
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dp(1, -1);
    track(1, -1, 0);
    printf("%d\n", big(mem[1][0], mem[1][1]));
    sort(group.begin(), group.end());
    for (int i : group) {
        printf("%d ", i);
    }
    return 0;
}