#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : T(T <= 10^6)의 시간동안 N(N <= 100000)개의 프로세스가 실행되는 순서를 구한다.
현재 실행 시간이 남은 프로세스 가운데 우선순위가 가장 높은, 그 중 id가 가장 낮은 프로세스가 선택되고,
선택된 프로세스는 1만큼 남은 시간이 줄어든 후 나머지 프로세스의 우선순위가 1씩 올라가고 이를 반복한다.
각 id, 남은 실행 시간, 우선순위는 10^6 이하의 자연수이다.

해결 방법 : 우선순위 큐에 문제의 우선순위대로 프로세스들을 넣고 하나씩 꺼내서 작업을 반복한다.
단, 나머지 프로세스의 우선순위를 올리는 대신 그 프로세스의 우선순위를 내리는 방식을 사용해야
시간 초과를 내지 않을 수 있다.

주요 알고리즘 : 자료 구조, 우선순위 큐, 수학

출처 : 가희 1회 3번
*/

int remtm[1048576];
priority_queue<pair<int, int>> pq;

int main(void) {
    int t, n, a, b, c;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        remtm[a] = b;
        pq.push({ c, -a });
    }
    for (int i = 0; i < t; i++) {
        a = -(pq.top().second);
        c = pq.top().first;
        pq.pop();
        printf("%d\n", a);
        remtm[a]--;
        if (remtm[a] > 0) pq.push({ c - 1, -a });
    }
    return 0;
}