#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 2의 거듭제곱이 주어진다. 이때, 이 수들을 두 그룹으로 나누어 각각 더해서 2의 거듭제곱 2개로
나타낼 수 있는 지 구한다. 주어지는 수는 2^100000 이내이다.

해결 방법 : 2의 거듭제곱의 특성상 원래 있던 하나의 이진수(더 작은 수)와 나머지의 합(더 큰 수)으로 나눌 수 있게 된다.
나머지의 합이 2의 거듭제곱이 되는지 보기 위해서는 우선순위 큐로 작은 수부터 찾아나가면 된다.
이때, 가장 작은 2개의 값이 같다면 두 수의 합(두 수의 값 + 1)을 우선순위 큐에 넣고,
다르다면 한 번은 기다린 뒤(해당 수가 작은 이진수일 수 있으므로)
또 다른 경우가 나온다면 2의 거듭제곱으로 나타낼 수 없다 하면 된다.

한 번 기다린 다음 우선순위 큐의 값이 1개가 되었거나, 기다린 적 없이 우선순위 큐의 값이 2개가 되었다면 우선순위 큐를 나간다.
기다린 횟수와 우선순위 큐의 크기 합이 2인 경우 나타낼 수 있고, 그 외에는 나타낼 수 없다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : Latin 2020 D번
*/

priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    int n, x, y, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
    }
    while (pq.size() >= 2) {
        if (r == 0 && pq.size() == 2) break;
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        if (x == y) pq.push(x + 1);
        else {
            pq.push(x);
            pq.push(y);
            if (r) break;
            pq.pop();
            r = 1;
        }
    }
    if (pq.size() + r == 2) printf("Y");
    else printf("N");
    return 0;
}