#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 자연수들이 있다. 이 자연수들 중 같은 2개의 수를 그 2배인 수로 합치는 작업을 반복할 때,
최종적으로 남게 되는 수를 구한다.

해결 방법 : 각 수들이 자연수들이기 때문에 합치면 반드시 그보다 큰 수가 된다. 따라서, 작은 수부터 순서대로 합쳐나가면
모든 수들을 차례로 합쳐나갈 수 있다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : PA 2002.11 2-1번
*/

priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    int n, x, y, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
    }
    x = pq.top();
    pq.pop();
    while (pq.size()) {
        y = x;
        x = pq.top();
        pq.pop();
        if (x == y) {
            pq.push(x * 2);
            x = pq.top();
            pq.pop();
        }
        else r++;
    }
    printf("%d", r);
    return 0;
}