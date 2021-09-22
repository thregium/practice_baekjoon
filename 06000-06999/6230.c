#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 고품질 짚과 M(M <= 10000)개의 저품질 짚이 있다. 고품질 짚을 사면 그 짚의 크기보다 작은
저품질 짚을 덤으로 준다고 하면 고품질 짚만 샀을 때 최대 몇 개의 저품질 짚을 얻을 수 있는지 구한다.

해결 방법 : 짚을 비싼 것 부터 산다 했을 때, 그 짚보다는 작지만 그러한 짚 가운데 가장 큰 것을 고르는 것이 가장 좋음을
알 수 있다.(더 작은 짚들은 더 작은 짚의 덤으로도 얻을 수 있으므로)
따라서, 이러한 짚을 빠르게 찾으면 문제를 풀 수 있다. 그러기 위해서는 고품질 짚과 저품질 짚을 각각 크기 순으로 정렬한 후,
마지막으로 얻은 저품질 짚을 저장하는 방식을 이용하면 된다. 이렇게 하면 최대 O(N+M)번만의 연산을 통해
모든 고품질 짚에서 덤으로 얻을 짚들을 찾을 수 있고, 덤으로 얻은 짚의 수에 고품질 짚의 수를 더하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 투 포인터

출처 : USACO 2007F B3번
*/

int high[10240], low[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, h = 0, l = 0, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &high[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &low[i]);
    }
    qsort(high, n, sizeof(int), cmp1);
    qsort(low, m, sizeof(int), cmp1);

    while (h < n) {
        while (low[l] >= high[h] && l < m) l++;
        if (l < m) {
            r++;
            l++;
        }
        r++;
        h++;
    }
    printf("%d", r);
    return 0;
}