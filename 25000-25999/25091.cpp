#include <stdio.h>
#include <vector>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 트리가 있다. 트리의 각 정점에 대해 부모 정점은
그 정점보다 번호가 작다. 이때 잎 정점에서 출발하여 아직 방문하지 않은 상위의 모든 정점으로 이동하는
과정에서 나온 최댓값의 합의 최댓값을 구한다.

해결 방법 : 뒤쪽부터 살피면서 각 정점의 최댓값을 저장해 나간다. 각 정점의 하위 정점 가운데
가장 최댓값이 적은 값을 선택하고 선택하지 않은 하위 값들은 모두 결괏값에 더한다.
부모 정점이 없는 값들은 모두 그대로 더한다.

주요 알고리즘 : DP, 트리DP, 그리디 알고리즘?

출처 : GCJ 2022Q D번
*/

int f[103000], p[103000], mem[103000];
vector<int> c[103000];

int main(void) {
    int t, n, best;
    long long res = 0, sum;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &f[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            c[p[i]].push_back(i);
        }

        res = 0;
        for (int i = n; i >= 1; i--) {
            mem[i] = f[i];
            if (c[i].size() == 0) continue;
            best = INF, sum = 0;
            for (int j : c[i]) {
                if (mem[j] < best) best = mem[j];
                sum += mem[j];
            }
            res += sum - best;
            if (best > mem[i]) mem[i] = best;
        }
        for (int i : c[0]) res += mem[i];

        printf("Case #%d: %lld\n", tt, res);
        for (int i = 0; i <= n; i++) c[i].clear();
    }
    return 0;
}