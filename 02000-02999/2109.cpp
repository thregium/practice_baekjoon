#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 10000)개의 강의 요청이 있다. 각 강의를 D_i(D_i <= 10000)일 내로 하면 P_i(P_i <= 10000)의 강의료를 얻을 수 있다.
이때, 하루에 1개의 강의만 할 수 있다면 얻을 수 있는 가장 많은 강의료를 구한다.

해결 방법 : 마지막 날부터 역순으로 확인하면서 그날 할 수 있는 강의 가운데 가장 강의료가 높은 강의를 찾는다.
강의 요청을 날짜의 역순으로 정렬한 다음, 우선순위 큐에 순서대로 넣어가다가 가장 강의료가 높은 것을 계속 구하면 된다.
이미 한 강의는 우선순위 큐에서 빼둔다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : SEERC 2003 D번
*/

int lec[10240][2];
priority_queue<int> lecm;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, d = 12345, p = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lec[i][1], &lec[i][0]);
    }
    qsort(lec, n, sizeof(int) * 2, cmp1);
    while (d > 0) {
        while (p < n && d <= lec[p][0]) {
            lecm.push(lec[p][1]);
            p++;
        }
        if (lecm.size()) {
            r += lecm.top();
            lecm.pop();
        }
        d--;
    }
    printf("%d", r);
    return 0;
}