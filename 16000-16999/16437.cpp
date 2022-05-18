#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 123456)개의 섬이 있고, 1번 섬을 제외한 섬들에 늑대 또는 양이 A_i(A_i <= 10^9)마리 있다.
각 섬들은 트리 형태로 연결되어 있다. 이때, 양들이 1번 섬으로 이동하고, 각 늑대는 최대 1마리까지
양을 잡아먹는다면 1번 섬에 도달할 수 있는 양의 수를 구한다.

해결 방법 : 트리 DP를 이용해 각 섬에 온 양과 늑대 수를 센 다음, 그 중 작은 쪽을 줄이고, 그 섬의 양 수를
반환해 나간다. 이를 반복하여 1번 섬의 양 수를 구한다. 오버플로에 유의한다.

주요 알고리즘 : DP, 트리DP

출처 : 경북대 2018 양번
*/

long long isle[131072][2], par[131072];
vector<int> chd[131072];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long dp(int x) {
    for (int i : chd[x]) {
        isle[x][0] += dp(i);
    }
    long long van = small(isle[x][0], isle[x][1]);
    isle[x][0] -= van;
    isle[x][1] -= van;
    return isle[x][0];
}

int main(void) {
    int n, a, p;
    char t;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf(" %c %d %d", &t, &a, &p);
        if (t == 'W') isle[i][1] = a;
        else if (t == 'S') isle[i][0] = a;
        else return 1;
        chd[p].push_back(i);
        par[i] = p;
    }
    printf("%lld", dp(1));
    return 0;
}