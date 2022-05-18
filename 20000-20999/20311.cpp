#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 300000)개의 K(K <= N)종류 화학 물질들이 있다. 각 종류 별 물질이 담긴 병의 수가 주어질 때,
인접한 병에는 서로 다른 물질이 담기도록 배치하는 방법이 있는 지 확인하고, 있다면 그러한 방법을 출력한다.

해결 방법 : 우선순위 큐를 통해 현재 가장 많이 남은 2가지 화학 물질 가운데 최근 놓지 않은
물질이 담긴 병을 놓는 것을 반복하면 된다. 그 과정에서 남은 물질이 없게 되면
배치할 수 있는 방법이 없는 것이다. 있다면 배치한 순서를 출력한다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐, 구성적

출처 : UNIST 2회 C번
*/

int res[327680];
priority_queue<pair<int, int>> pq;

int main(void) {
    int n, k, x, last = -1;
    pair<int, int> px, py;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &x);
        pq.push({ x, i });
    }
    for (int i = 0; i < n; i++) {
        if (pq.size() == 0) {
            printf("-1");
            return 0;
        }
        px = pq.top();
        pq.pop();
        if (px.second != last) {
            res[i] = px.second;
            last = px.second;
            px.first--;
            if (px.first > 0) pq.push(px);
            continue;
        }

        if (pq.size() == 0) {
            printf("-1");
            return 0;
        }
        py = pq.top();
        pq.pop();
        if (py.second != last) {
            res[i] = py.second;
            last = py.second;
            py.first--;
            pq.push(px);
            if (py.first > 0) pq.push(py);
            continue;
        }
        else return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}