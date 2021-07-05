#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : K(K <= 100)개의 소수가 주어질 때, 이 소수들을 곱해서 만들 수 있는 N(N <= 100000)번째로 작은 수를 구한다.
단, 답은 2^31보다 작다.

해결 방법 : 우선순위 큐를 이용해 가장 작은 수부터 차례로 확인한다. 만약 현재 수가 확인하지 않은 수인 경우
K개의 소수에 대해 현재 수에 곱한 결과가 2^31 미만이라면 각각 우선순위 큐에 집어넣는다. 확인한 수인 경우에는 다음 수를 확인한다.
여기서 확인하지 않은 수가 N번째가 되었을 때 본 수를 출력하면 된다.

주요 알고리즘 : 자료구조, 우선순위 큐, 수학, 정수론
*/

int a[128];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    int k, n, last = 0, top = 1;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
        pq.push(a[i]);
    }
    for (int i = 0; i < n; i++) {
        top = pq.top();
        pq.pop();
        if (top == last) {
            i--;
            continue;
        }
        last = top;
        for (int j = 0; j < k; j++) {
            if ((long long)top * a[j] < 2147483648) pq.push(top * a[j]);
        }
    }
    printf("%d", top);
    return 0;
}