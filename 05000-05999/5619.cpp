#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(3 <= N <= 10^8)개의 서로 다른 자연수(<= 10000)가 주어질 때,
서로 다른 두 수를 붙여 만들 수 있는 수 가운데 세 번째로 작은 수를 구한다.
이때, 값이 같더라도 원래의 두 수가 다르면 다른 수이다. 원래의 두 수까지 같더라도 순서가 다르면 다른 수이다.

해결 방법 : 비둘기집 원리에 의해 N은 10000 이하가 된다. 따라서, O(N)에 답을 구할 수 있다면 시간 내에 풀 수 있다.
그런데, 세 번째로 작은 수는 가장 작은 4개의 수만을 이용해도 만들 수 있다는 것을 알 수 있다.
따라서, 우선순위 큐를 이용해 가장 작은 4개의 수만을 추린 후
(최대 힙을 이용하고, 크기가 4를 넘을 때 마다 가장 큰 수를 빼내면 된다.), 만들 수 있는 모든 조합을 구한다.
그리고 그 수들을 정렬하고 3번째로 작은 수를 찾으면 된다. 이때, N이 3인 경우에 유의한다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐, 비둘기집 원리

출처 : JOI 2006모1 3번
*/

priority_queue<int> pq;
int a[4], res[16];
char buff[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getconcat(int a, int b) {
    sprintf(buff, "%d%d", a, b);
    return strtoll(buff, NULL, 10);
}

int main(void) {
    int n, x, p;
    scanf("%d", &n);
    if (n > 8000) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
        if (pq.size() > 4) pq.pop();
    }
    x = 0;
    while (pq.size()) {
        a[x++] = pq.top();
        pq.pop();
    }
    p = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (i == j) continue;
            res[p++] = getconcat(a[i], a[j]);
        }
    }
    qsort(res, p, sizeof(int), cmp1);
    printf("%d", res[2]);
    return 0;
}