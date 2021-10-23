#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 5000)명의 사원이 있고, 각 사원에 대해 상사가 될 수 있는 사원들이 주어진다.
이때, 사원들간의 관계를 정리해서 트리 형태로 만들고 그때의 봉급을 정해야 한다. 트리에서 모든 노드의 봉급은 자연수여야 하고,
모든 자식 노드(바로 다음 단계 노드)의 봉급의 합보다 커야 한다. 필요한 봉급의 최솟값을 구한다.
단, 항상 트리를 만들 수 있는 경우만 주어진다.

해결 방법 : 어떠한 상태의 트리에서 새로운 노드가 추가될 때의 봉급 변화를 생각해보면 노드가 추가될 때는
그 노드의 레벨만큼 봉급이 더해진다는 사실을 알 수 있다. 따라서, 항상 새로운 노드를 트리의 최대한 높은 곳에
붙이는 것이 이득이 되는데, 이러한 방법으로는 BFS가 있다.

처음에 각 사원들에 대해 부하가 될 수 있는 사원들을 간선으로 연결한 다음,
N명에 대해 한번씩 BFS를 통해 해당 사원을 루트로 하는 트리를 BFS로 만든다.
만약 모든 사원에게 도달할 수 없다면 트리를 만들 수 없으므로 넘어간다.
모든 사원에게 도달 가능하다면 그때의 모든 노드의 차수를(루트 노드가 1) 더한 값을 확인해 결괏값과 비교하다가
최솟값을 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS, 브루트 포스

출처 : BtOI 2016 1번
*/

int level[5120];
vector<int> ed[5120];
queue<int> q;

int bfs(int n, int x) {
    int r = 0;
    level[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!level[i]) {
                level[i] = level[x] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (level[i] == 0) return -1;
        else r += level[i];
    }
    return r;
}

int main(void) {
    int n, k, x, r = INF;
    //freopen("E:\\PS\\Olympiad\\Baltic\\2016\\day1_tests\\bosses\\t.in.6", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            ed[x].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) level[j] = 0;
        x = bfs(n, i);
        if (x < 0) continue;
        else if (x < r) r = x;
    }
    printf("%d", r);
    return 0;
}