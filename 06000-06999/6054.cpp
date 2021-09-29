#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 1000)명이 이어달리기를 한다. 각 사람이 한 바퀴를 도는데 걸리는 시간은 L_i(L_i <= 1000)이고,
각 사람은 M_i명의 다른 사람에게 바톤을 넘겨준다. 단, 이미 한 번 뛴 사람은 다시 뛰지 않는다.
1번 사람부터 출발할 때, 모든 사람이 도착하는데 걸리는 시간을 구한다. 모든 사람이 한 번씩은 뜀이 보장된다.

해결 방법 : 1번 사람부터 뛴 다음, 다른 사람들에게 바톤을 넘겨주는 과정을 우선순위 큐를 이용해 구현한다.
한 바퀴 돈 사람이 도착한 시각을 우선순위 큐에 넣은 다음, 가장 빨리 도착하는 사람부터 차례로 바톤을 넘긴다.
바톤을 넘겨받은 사람은 받을 수 있는 가장 빠른 시각에 바톤을 받게 된다. 그러면 한 바퀴 돈 다음,
바톤을 다시 넘겨주는 것을 반복한다.
모든 사람이 바톤을 받으면 도착한 시각 가운데 가장 늦은 것을 찾아 출력하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, 우선순위 큐

출처 : USACO 2010O B3번
*/

int finished[1024], lap[1024], sign[1024][1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, x, t, res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &lap[i], &sign[i][0]);
        for (int j = 1; j <= sign[i][0]; j++) {
            scanf("%d", &sign[i][j]);
        }
        finished[i] = INF;
    }

    pq.push(pair<int, int>(0, 1));
    while (pq.size()) {
        x = pq.top().second;
        t = pq.top().first;
        pq.pop();
        if (x > 1 && t + lap[x] >= finished[x]) continue;
        else finished[x] = t + lap[x];
        for (int i = 1; i <= sign[x][0]; i++) {
            if (finished[sign[x][i]] > t + lap[x]) {
                pq.push(pair<int, int>(t + lap[x], sign[x][i]));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (finished[i] > res) res = finished[i];
    }
    printf("%d", res);
    return 0;
}