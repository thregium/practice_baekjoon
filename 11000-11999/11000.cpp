#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 200000)개의 일정이 있다. 각 일정은 S에서 시작해서 T(S < T <= 10^9)에서 끝난다. 이때 각 일정마다 방 1개씩을
다른 일정과 겹치지 않게 써야 한다면 필요한 일정의 수를 구한다. 이때, 한 일정이 끝남과 동시에 같은 방에서 다른 일정을 시작할 수 있다.

해결 방법 : 각 일정을 시작 시각으로 정렬한 다음 각 일정이 시작할 때 마다 들어갈 수 있는 방을 찾아본다.
그 순간에 들어갈 수 없는 방이라면 다른 일정을 아무리 진행하더라도 여전히 들어갈 수 없는 방이기 때문에 일정 순으로만 보면 된다.

그런데, 이 과정에서 일반적인 탐색으로는 모든 강의실이 차 있는 경우 탐색 시간이 지나치게 길어지므로 우선순위 큐를 사용해
끝나는 시각이 가장 빠른 방의 끝나는 시각을 저장한다. 당연히 그 당시 끝나는 시각이 가장 빠른 방에 들어갈 수 없다면
다른 방들도 들어갈 수 없을 것이므로 시간을 절약할 수 있다. 들어갈 수 있다면 해당 값을 제거하고 새 값으로 바꾸면 되고,
들어갈 수 없다면 우선순위 큐에 값을 추가하면 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐
*/

int schedule[204800][2];
priority_queue<int, vector<int>, greater<int>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &schedule[i][0], &schedule[i][1]);
    }
    qsort(schedule, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (pq.size() && pq.top() <= schedule[i][0]) {
            pq.pop();
        }
        pq.push(schedule[i][1]);
    }
    printf("%d", pq.size());
    return 0;
}