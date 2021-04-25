#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : 보석들의 가격과 무게가 주어지고, 각 가방에 담을 수 있는 최대 무게가 주어질 때, 가져갈 수 있는 가장 많은 가치를 출력한다. (N <= 300000)

해결 방법 : 각 가방에는 넣을 수 있는 보석 가운데 가장 비싼 것을 넣는 것이 가장 좋다. 이를 위해서는
보석과 가방을 무게 오름차순으로 정렬한 다음, 각 가방마다 순서대로 넣을 수 있는 보석들을 우선순위 큐에 집어넣는다.
우선순위 큐는 가격 내림차순으로 정렬해야 한다. 그 다음, 우선순위 큐가 비어있지 않았다면 우선순위 큐에서 값을 꺼내서 결과에 더한다.
이를 모든 가방에 대해 반복하면 가장 많은 가치를 갖게 보석을 담을 수 있다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : COCI 2013-2014 #1 4번
*/

int gem[327680][2], back[327680];
priority_queue<pair<int, int>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, l = 0;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &gem[i][0], &gem[i][1]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &back[i]);
    }
    qsort(gem, n, sizeof(int) * 2, cmp1);
    qsort(back, k, sizeof(int), cmp1); //보석과 가방을 무게 오름차순 정렬
    for (int i = 0; i < k; i++) {
        for (int j = l; j < n; j++) {
            if (gem[j][0] > back[i]) break; //현재 보석이 더 무거운 경우
            l = j + 1; //다음에 볼 보석
            pq.push(pair<int, int>(gem[j][1], gem[j][0])); //우선순위 큐에 삽입
        }
        if (pq.top().second <= back[i]) {
            r += pq.top().first;
            pq.pop();
        }
    }
    printf("%d", r);
    return 0;
}