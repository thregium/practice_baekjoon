#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*
문제 : N(N <= 8) 이하의 자연수로 이루어진 순열이 있다. 이 순열에서 K(K <= N)개씩 수열을 뒤집어 나갈 때,
순열을 정렬하기 위해 뒤집어야 하는 최소 횟수를 구한다.

해결 방법 : 순열의 가짓수가 적으므로 모든 순열의 경우에 대해 BFS로 거리를 구하면 된다.
순열의 거리는 맵에 넣어 저장한다.

주요 알고리즘 : 그래프 이론, BFS, 맵

출처 : SRM 297 D1 1번 / D2 2번
*/

map<vector<int>, int> dist;
queue<vector<int>> q;

int main(void) {
    int n, k, x;
    vector<int> v, w;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    dist.insert({ v, 0 });
    q.push(v);
    while (q.size()) {
        v = q.front();
        q.pop();
        for (int i = 0; i <= n - k; i++) {
            w = v;
            for (int is = i, ie = i + k - 1; is < ie; is++, ie--) {
                x = w[is];
                w[is] = w[ie];
                w[ie] = x;
            }
            if (dist.find(w) == dist.end()) {
                dist.insert({ w, dist[v] + 1 });
                q.push(w);
            }
        }
    }
    v.clear();
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
    }
    if (dist.find(v) == dist.end()) printf("-1");
    else printf("%d", dist[v]);
    return 0;
}
