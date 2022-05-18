#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 300)개의 문제를 푸는 데 걸리는 시간(<= 10^6)이 주어지면, 다음 전략으로
문제를 풀 때 총 페널티의 값을 구한다.
첫 K(1 <= K <= N)개의 문제를 확인한다. 이 과정에는 시간이 걸리지 않는다.
확인한 문제들 가운데 풀지 않은 가장 빨리 풀 수 있는 문제를 푼다.
남은 다음 문제를 확인한다. 이 과정도 시간이 걸리지 않는다.
이를 모든 문제를 풀 때 까지 반복한다.

해결 방법 : 문제에 주어진 내용을 시뮬레이션 해 나간다. 최솟값을 뽑는 데 우선순위 큐를 쓰는 것이 좋다.

주요 알고리즘 : 자료 구조, 우선순위 큐

출처 : PacNW 2016 Q번
*/

int a[384];
priority_queue<int, vector<int>, greater<>> pq;

int main(void) {
    int n, k, t = 0;
    long long r = 0;
    scanf("%d %d", &n, &k);
    while (k <= 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i < k) pq.push(a[i]);
    }
    if (pq.size() == 0) return 1;
    for (int i = k; i < n; i++) {
        t += pq.top();
        r += t;
        pq.pop();
        pq.push(a[i]);
    }
    while (pq.size()) {
        t += pq.top();
        r += t;
        pq.pop();
    }
    printf("%lld", r);
    return 0;
}