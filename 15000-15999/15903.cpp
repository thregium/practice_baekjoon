#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 100만 이하의 자연수가 적힌 N(N <= 1000)개의 카드에 대해 다음 연산을 M(M <= 15 * N)회 시행한 후 모든 카드에 적힌의 합의 최솟값을 구한다.
두 카드에 적힌 수를 두 카드의 합으로 바꿔놓는다.

해결 방법 : 합쳐야 하는 모든 수가 자연수이기 때문에 고를 두 카드는 가장 작은 두 수가 되는 것이 좋다. 이 가장 작은 수는 계속해서 변하기 때문에
우선순위 큐를 이용해 가장 작은 두 수를 얻는다. 그 다음 얻은 두 수를 합쳐서 다시 우선순위 큐에 집어넣는다.
M회의 위 연산이 끝나면 우선순위 큐의 모든 값을 꺼내서 합한 것이 정답이 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : UCPC 2018예 B번
*/

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(void) {
    int n, m;
    long long x, y, sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        pq.push(x);
    }
    for (int i = 0; i < m; i++) {
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        pq.push(x + y);
        pq.push(x + y);
    }
    while (pq.size()) {
        sum += pq.top();
        pq.pop();
    }
    printf("%lld", sum);
    return 0;
}