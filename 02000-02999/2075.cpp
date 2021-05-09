#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N * N(N <= 1500)개의 수들이 주어진다. 각 열의 아래 행에 있는 수는 위 행에 있는 수보다 클 때, N번째로 큰 수를 구한다.
단, 메모리 제한은 12MB이다.

해결 방법 : 우선순위 큐를 이용해 구할 수 있다. 최소 힙을 하나 준비한다. 그 다음, 차례로 수들을 하나씩 입력받는다.
입력받았을 때 힙의 크기가 N보다 작다면 그대로 그 수를 넣는다. 힙의 크기가 N보다는 크지만, 힙의 맨 위에 있는 수보다
입력받은 수가 크다면 힙에 그 수를 넣고 맨 위에 있는 수를 빼면 된다. 입력받은 수가 더 작다면 그대로 둔다.
이를 전부 반복한 다음 힙의 맨 위에 있는 수가 N번째로 큰 수일 것이므로 그 수를 출력하면 된다.

주요 알고리즘 : 자료구조, 우선순위 큐
*/

priority_queue<int, vector<int>, greater<int>> q;

int main(void) {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &a);
        if (q.size() < n) q.push(a);
        else if (a > q.top()) {
            q.push(a);
            q.pop();
        }
    }
    printf("%d", q.top());
    return 0;
}