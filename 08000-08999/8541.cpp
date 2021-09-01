#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : 높이가 M(M <= 500000) 이하의 자연수인 N(N <= 10^6)개의 막대가 있다. 이 막대들은 각각 1000 이하의 고유한 가치를 갖고 있다.
이때, 각 막대들을 운반하려고 하는데, 운반할 때에는 M개의 홈에 끼워 막대를 운반 가능하다. 그런데, 각 홈에는 최대
각각 1, 2, ..., M의 높이를 갖는 막대만 운반 가능하다. 이때, 한번에 운반 가능한 막대의 가치 합을 구한다.

해결 방법 : 우선, 높이 제한이 낮은 홈에는 들어갈 수 있는 막대가 한정적이라는 점을 이용한다.
따라서, 각 막대들을 먼저 높이 오름차순으로 정렬한다. 그 다음으로는 해당하는 막대들 가운데 가장 가치가 높은 것을 뽑아오는 것이
가장 좋다는 것을 알 수 있다. 이는 우선순위 큐를 통해 가치가 큰 순으로 가치들을 집어넣는 방법으로 구할 수 있다.
매 홈마다 해당하는 홈의 높이 이하이며 아직 우선순위 큐에 집어넣지 않은 막대의 가치들을 모두 우선순위 큐에 집어넣고
우선순위 큐에서 가장 가치가 높은 막대의 가치를 우선순위 큐에서 꺼내서 결괏값에 더한다.
만약 우선순위 큐가 비었다면 다음 높이로 넘어간다. 이를 M까지 반복하면 답을 얻을 수 있다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : PA 2002.05 2-2번
*/

int plates[1048576][2];
priority_queue<int> pq;

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int m, n, pos = 0, r = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &plates[i][0], &plates[i][1]);
    }
    plates[n][1] = INF;
    qsort(plates, n, sizeof(int) * 2, cmp1);
    for (int i = 1; i <= m; i++) {
        while (plates[pos][1] <= i) {
            pq.push(plates[pos][0]);
            pos++;
        }
        if (pq.empty()) continue;
        else {
            r += pq.top();
            pq.pop();
        }
    }
    printf("%d", r);
    return 0;
}