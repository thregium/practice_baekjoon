#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 200000)가지 물약이 존재하고, 그 물약들 중 전부 혹은 일부에 대한 레시피가 M(M <= 200000)가지 존재한다.
각 레시피는 K(K < N)가지 서로 다른 물약을 조합해 어떤 재료에 쓰이지 않은 물약 R을 만들며,
모든 레시피에 들어가는 물약의 수는 최대 400000개이다. 처음 있는 물약의 목록이 겹치지 않게 주어질 때, 만들 수 있는 모든
물약의 종류를 구한다. 단, 처음에 있던 물약은 무한대로 쓸 수 있으며, 같은 종류의 물약에 대한 레시피가 여러 개 있을 수 있다.

해결 방법 : 각 물약에서 레시피를 향한 간선을 이어 물약의 생성 관계에 대한 그래프를 만든다.
이때 같은 종류의 물약에 대한 레시피가 여러 개 있을 수 있으므로 물약이 아닌 레시피를 향해야 한다. 각 레시피의 결과물은
배열에 저장해 놓으면 된다. 그래프를 만든 다음에는 처음에 있던 물약들을 큐에 넣은 다음, 위상정렬 순서로 BFS를 돌리면 된다.
현재 확인중인 물약으로 만들 수 있는 모든 레시피들에 대해 진입차수를 1 감소시킨 후 진입차수가 0이 된 레시피들을 확인하며
만약 확인하지 않은 물약의 레시피라면 큐에 다시 집어넣는다. 이를 큐가 빌 때 까지 반복한 다음
지금까지 확인했던 물약들을 오름차순으로 다시 출력하면 된다.

주요 알고리즘 : 그래프 이론, BFS, 위상 정렬

출처 : 경북대 2020 H번
*/

int x[204800], ins[204800], vis[204800], dest[204800];
vector<int> make[204800], res;
unordered_set<int> us[204800];
queue<int> q;

int main(void) {
    int n, m, k, r, p;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x[j]);
        }
        scanf("%d", &r);
        dest[i] = r;
        for (int j = 0; j < k; j++) {
            if (us[x[j]].find(i) != us[x[j]].end()) continue;
            make[x[j]].push_back(i);
            us[x[j]].insert(i);
            ins[i]++;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &p);
        if (us[0].find(p) != us[0].end()) continue;
        us[0].insert(p);
        q.push(p);
        vis[p] = 1;
    }
    while (q.size()) {
        p = q.front();
        res.push_back(p);
        q.pop();
        for (int i : make[p]) {
            ins[i]--;
            if (ins[i] == 0 && !vis[dest[i]]) {
                q.push(dest[i]);
                vis[dest[i]] = 1;
            }
        }
    }
    printf("%d\n", res.size());
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
        if (i > 0 && res[i] == res[i - 1]) return 1;
    }
    return 0;
}