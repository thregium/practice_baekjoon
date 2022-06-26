#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 200000)개의 단방향 구간 {a, b}에 대해 (1 <= a < b <= 100000)
각 구간별 승객들이 임의로 자리를 선택하는 경우와 자리를 배정해주는 경우 각각에 대해
필요한 자리의 수를 각각 구한다.

해결 방법 : 마음대로 선택하는 경우를 생각해보면 임의의 구간에 대해 겹치는 모든 구간이 서로 다른 자리로
예매된 경우가 최악의 경우로 그 때 겹치는 구간 수 + 1이 최대 자리 수가 된다.
누적 합을 통해 각 구간에서 왼쪽과 오른쪽 부분을 뺀 나머지를 세는 것으로 겹치는 구간 수 + 1을 셀 수 있고,
그 중 최댓값이 답이 된다.
선택해 주는 경우에는 위치 순서대로 정렬한 다음, 끝점과 현 위치를 비교해가며 자리가 없는 경우에만
새로운 자리를 선택해 나가면 된다. 이 경우 전부 끝난 다음 자리 개수가 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐, 누적 합

출처 : Tsukuba 2017 I번
*/

int pass[204800][2], psums[103000], psume[103000];
priority_queue<int, vector<int>, greater<>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, res1 = 0, res2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pass[i][0], &pass[i][1]);
        psums[pass[i][0]]++;
        psume[pass[i][1]]++;
    }
    for (int i = 1; i <= 100000; i++) {
        psums[i] += psums[i - 1];
        psume[i] += psume[i - 1];
    }
    qsort(pass, n, sizeof(int) * 2, cmp1);
    
    for (int i = 0; i < n; i++) {
        if (psums[pass[i][1] - 1] - psume[pass[i][0]] > res1) {
            res1 = psums[pass[i][1] - 1] - psume[pass[i][0]];
        }
    }
    for (int i = 0; i < n; i++) {
        if (pq.size() == 0 || pq.top() > pass[i][0]) {
            pq.push(pass[i][1]);
        }
        else {
            pq.pop();
            pq.push(pass[i][1]);
        }
    }
    res2 = pq.size();

    printf("%d %d\n", res1, res2);
    return 0;
}