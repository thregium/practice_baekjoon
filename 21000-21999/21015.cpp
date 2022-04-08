#include <stdio.h>
#include <vector>
#define MOD 998244353LL
using namespace std;

/*
문제 : N(N <= 10000)개의 정점을 가진 트리가 있다. 각 간선마다 이동해야 하는 횟수(<= 200, 짝수)가 주어질 때,
1번 정점에서 출발해서 모든 간선들을 정확히 해당 횟수만큼 이동하고 돌아오는 경로의 가짓수를 구한다.

해결 방법 : 트리를 사용한 DP로 답을 구한다. 각 정점에서 출발하고 돌아오는 경로의 개수를 저장하고
계산해 나간다. 우선, 각 정점에서 모든 자식 정점의 경로 개수의 곱을 계산한다.
그 다음, (남은 자식 정점으로 연결된 간선의 합)C(현재 자식 정점으로 연결된 간선)을 계산하여 전부 곱한다.
이는 각 자식 간선으로 방문하는 순서를 계산하기 위함이다. 이항 계수를 계산할 때에는 빠르게 하기 위해
페르마의 소정리를 통한 계산을 한다.
마지막으로, 각 자식 정점에 대해 그 정점의 자식 정점들로 방문하는 순서를 정하기 위해 중복조합을 사용해
그 값을 곱해준다. 이는 (자식 정점의 모든 자식 간선의 합 + 자식 간선으로의 합 - 1)C(자식 정점의
모든 자식 간선의 합)과 같다.
이 값을 재귀적으로 계산해 1번 정점에서의 답을 구한 후 출력하면 된다.

주요 알고리즘 : DP, 트리DP, 조합론

출처 : INC 2020 G번
*/

int mem[10240], fact[1048576], csum[10240];
vector<pair<int, int>> ed[10240], chd[10240];

long long powe(long long x, long long y, long long m) {
    if (y == 0) return 1;
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

long long comb(long long n, long long k) {
    return fact[n] * powe(fact[k] * (long long)fact[n - k] % MOD, MOD - 2, MOD) % MOD;
}

void mktree(int x, int p) {
    mem[x] = -1;
    for (auto& i : ed[x]) {
        if (i.first == p) continue;
        chd[x].push_back(i);
        csum[x] += i.second;
        mktree(i.first, x);
    }
}

int dp(int x) {
    if (mem[x] >= 0) return mem[x];
    long long r = 1, sum = 0;
    for (auto& i : chd[x]) {
        r = (r * dp(i.first)) % MOD;
        r = (r * comb(i.second + csum[i.first] - 1, csum[i.first])) % MOD;
        sum += i.second;
    }
    for (auto& i : chd[x]) {
        r = (r * comb(sum, i.second)) % MOD;
        sum -= i.second;
    }
    return r;
}

int main(void) {
    int n, a, b, c;
    fact[0] = 1;
    for (long long i = 1; i < 1048576; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (c & 1) return 1;
        c >>= 1;
        ed[a].push_back({ b, c });
        ed[b].push_back({ a, c });
    }
    mktree(1, -1);
    printf("%d", dp(1));
    return 0;
}