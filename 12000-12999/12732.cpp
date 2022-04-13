#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : A역과 B역 사이를 열차가 시간표에 맞춰 이동한다. 회차 시간이 T(T <= 60)분이고,
A역에서 출발하는 일정이 NA(NA <= 100)개, B역에서 출발하는 일정이 NB(NB <= 100)개일 때,
시간표에 맞추기 위해 각 역에서 출발 새로 출발해야 하는 열차의 수를 각각 구한다.
각 일정은 도착시각이 출발시각보다 늦으며, 1일 내에 모든 일정이 들어간다.

해결 방법 : 각 일정들을 출발 시각 순으로 정렬한 다음, 각 역에서 대기하고 있는 열차의 목록을
최소 힙으로 양쪽 역에 대해 각각 넣어둔다. 각 일정마다 힙이 비었거나 가장 빠른 열차가
현재 출발시각보다 늦게 출발 가능한 경우에는 그 역에서 출발해야 하는 열차 수를 1 늘인다.
시간 내 출발 가능하다면 그 열차를 힙에서 제거한다. 그 다음, 반대 역에 도착시각 + T의 시각으로
다음 열차를 우선순위 큐에 넣어둔다. 이를 반복한 다음, 양쪽의 출발하는 열차 수를 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 우선순위 큐

출처 : GCJ 2008Q B2번
*/

int train[256][3];
priority_queue<int, vector<int>, greater<>> pqa, pqb;

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, tn, na, nb, hs, ms, he, me, ra, rb;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &tn);
        scanf("%d %d", &na, &nb);
        for (int i = 0; i < na + nb; i++) {
            scanf("%d:%d %d:%d", &hs, &ms, &he, &me);
            train[i][0] = (i >= na);
            train[i][1] = hs * 60 + ms;
            train[i][2] = he * 60 + me;
        }
        qsort(train, na + nb, sizeof(int) * 3, cmp1);

        ra = 0, rb = 0;
        for (int i = 0; i < na + nb; i++) {
            if (train[i][0] == 0) {
                if (pqa.size() > 0 && pqa.top() <= train[i][1]) pqa.pop();
                else ra++;
                pqb.push(train[i][2] + tn);
            }
            else {
                if (pqb.size() > 0 && pqb.top() <= train[i][1]) pqb.pop();
                else rb++;
                pqa.push(train[i][2] + tn);
            }
        }

        printf("Case #%d: %d %d\n", tt, ra, rb);
        while (pqa.size()) pqa.pop();
        while (pqb.size()) pqb.pop();
    }
    return 0;
}