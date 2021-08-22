#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 5000)개의 쿼리가 주어질 때, 쿼리에 응답한다.
A(A <= 100)의 값이 0인 경우 현재 집합에 있는 값 가운데 가장 큰 수를 출력하고 그 수를 집합에서 제거한다. 없는 경우 -1을 출력한다.
0이 아니라면 집합에 주어진 A개의 수를 추가한다. 주어진 수는 100000 이하의 자연수이다.

해결 방법 : 우선순위 큐를 이용한다.

주요 알고리즘 : 자료 구조, 우선순위 큐
*/

priority_queue<int> pq;

int main(void) {
    int n, a, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 0) {
            if (pq.size()) {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else printf("-1\n");
        }
        else {
            for (int j = 0; j < a; j++) {
                scanf("%d", &x);
                pq.push(x);
            }
        }
    }
    return 0;
}