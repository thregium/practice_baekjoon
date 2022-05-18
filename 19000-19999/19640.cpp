#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)명의 사람들이 M(M < N)개의 줄에 서있다. 각 줄의 첫 사람 가운데 우선순위를 계산해
가장 우선순위가 높은 사람부터 차례로 들어간다고 할 때, K + 1번째 사람은 몇 번째로 들어가게 되는 지 구한다.

해결 방법 : 우선순위 큐를 이용한다. 여러 수를 이용해 우선순위를 계산하면 된다.

주요 알고리즘 : 자료 구조, 우선순위 큐

출처 : SSC 2020B E번
*/

int lend[103000];
vector<pair<int, int>> line[103000];
priority_queue<pair<pair<int, int>, int>> pq;

int main(void) {
    int n, m, k, ln, targ, x, r = 0;
    pair<int, int> p;
    scanf("%d %d %d", &n, &m, &k);
    ln = k % m;
    targ = k / m;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p.first, &p.second);
        line[i % m].push_back(p);
        if (i < m) pq.push({ p, -i });
    }
    while (1) {
        x = -(pq.top().second);
        pq.pop();
        if (x == ln && lend[x] == targ) break;
        if ((lend[x] + 1) * m + x < n) {
            pq.push({ line[x][lend[x] + 1], -x });
            lend[x]++;
        }
        r++;
    }
    printf("%d", r);
    return 0;
}