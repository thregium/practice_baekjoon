#include <stdio.h>
#include <queue>
#include <unordered_map>
using namespace std;

/*
문제 : 수직선상에 N(N <= 100000)개의 정수 점이 있다. 각 K(K <= 100000)개의 정수 점을
N개의 점과 겹치지 않고 서로도 겹치지 않게 하면서 N개의 점과 거리 합이 최소가 되도록 배치할 때,
N개의 점과의 거리 합을 구한다.

해결 방법 : N개의 점에서 BFS를 해 나가며 거리의 합을 구하면 된다. 단, BFS 과정에서 일반 배열로는
거리 배열을 저장하기 어려우므로 해시맵을 사용한다.

주요 알고리즘 : 그래프 이론, BFS, 해시맵
*/

unordered_map<int, int> dist;
queue<int> q;

int main(void) {
    int n, k, x;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        q.push(x);
        dist.insert({ x, 0 });
    }
    while (k > 0) {
        x = q.front();
        q.pop();
        if (dist.find(x + 1) == dist.end()) {
            k--;
            r += dist[x] + 1;
            dist.insert({ x + 1, dist[x] + 1 });
            q.push(x + 1);
        }
        if (k <= 0) break;
        if (dist.find(x - 1) == dist.end()) {
            k--;
            r += dist[x] + 1;
            dist.insert({ x - 1, dist[x] + 1 });
            q.push(x - 1);
        }
    }
    printf("%lld", r);
    return 0;
}