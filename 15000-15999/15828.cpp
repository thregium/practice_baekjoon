#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : 크기 N(N <= 100000)의 버퍼를 가진 라우터에서 들어오는 정보와 처리되는 정보가 주어질 때,
라우터에 남는 정보를 구한다.

해결 방법 : 큐를 이용한다. 정보가 들어올 때에는 버퍼 크기가 남는 경우 큐에 추가하고, 정보가 처리될 때에는
큐에서 값을 뺀다. 마지막에 남는 값들을 출력하면 된다.

주요 알고리즘 : 자료 구조, 큐

출처 : 아주대 2018D2 B번
*/

queue<int> q;

int main(void) {
    int n, x;
    scanf("%d", &n);
    while (1) {
        scanf("%d", &x);
        if (x > 0) {
            if (q.size() < n) q.push(x);
        }
        else if (x == 0) {
            if (q.size() == 0) return 1;
            else q.pop();
        }
        else break;
    }
    if (q.size() == 0) printf("empty");
    else {
        while (q.size()) {
            printf("%d ", q.front());
            q.pop();
        }
    }
    return 0;
}