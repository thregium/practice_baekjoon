#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 선물들을 X(X <= 10^9)라는 시간 제한 내에 만들어야 한다.
각 선물의 생산 시간(<= X, 자연수)이 주어질 때, 모든 선물을 시간 제한 내에 만들기 위해 필요한 공정 라인의 수를 구한다.
선물은 앞의 선물들을 만들고 남은 소요 시간이 가장 짧은 라인에 배치된다.

해결 방법 : 우선순위 큐를 이용해 각 공정 라인마다 소요 시간을 체크하며
공정 라인 수가 특정된 경우 전체 소요 시간을 확인할 수 있다.
또한, 문제에 주어진 전략대로 생산하는 경우 공정 라인이 늘어나는 경우 절대 소요 시간이 늘어나는 경우는 존재하지 않는다.
따라서, 매개 변수 탐색을 통해 답을 찾아나가면 된다.

주요 알고리즘 : 자료 구조, 우선순위 큐, 파라메트릭

출처 : 류호석 3회 4번
*/

int a[103000];
priority_queue<long long, vector<long long>, greater<long long>> pq;

long long makingtime(int n, int u) {
    long long x;
    while (pq.size()) pq.pop();
    for (int i = 0; i < u; i++) pq.push(0);
    for (int i = 0; i < n; i++) {
        x = pq.top();
        pq.pop();
        pq.push(x + a[i]);
    }
    while (pq.size() > 1) pq.pop();
    return pq.top();
}

int main(void) {
    int n, x, l, h, m;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    l = 1, h = n;
    while (l < h) {
        m = (l + h) >> 1;
        if (makingtime(n, m) <= x) h = m;
        else l = m + 1;
    }
    printf("%d", l);
    return 0;
}