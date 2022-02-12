#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 강의 시작과 끝 시각(<= 10^9)이 주어질 때, 모든 강의를 강의실에서 하기 위해
필요한 강의실 최소 개수를 구한다. 끝 시각은 시작 시각보다 이후고, 강의실 사용이 끝나자 마자
다음 강의를 하는 것은 가능하다.

해결 방법 : 강의들을 시작 시간 순서대로 정렬한 다음, 우선순위 큐에 사용이 끝난 강의실들의
끝 시각을 작은 순서대로 저장해둔다. 그 시각이 현재 강의의 시작 시간 이전인 경우
그 강의실을 사용하고, 이후라면 새로운 강의실에서 강의를 하면 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐
*/

int lect[103000][2];
priority_queue<int, vector<int>, greater<int>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &lect[i][0], &lect[i][1]);
    }
    qsort(lect, n, sizeof(int) * 2, cmp1);

    for (int i = 0; i < n; i++) {
        if (pq.size() == 0 || pq.top() > lect[i][0]) {
            pq.push(lect[i][1]);
            r++;
        }
        else {
            pq.pop();
            pq.push(lect[i][1]);
        }
    }
    printf("%d", r);
    return 0;
}