#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

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
    qsort(back, k, sizeof(int), cmp1);
    for (int i = 0; i < k; i++) {
        for (int j = l; j < n; j++) {
            if (gem[j][0] > back[i]) break;
            l = j + 1;
            pq.push(pair<int, int>(gem[j][1], gem[j][0]));
        }
        if (pq.top().second <= back[i]) {
            r += pq.top().first;
            pq.pop();
        }
    }
    printf("%d", r);
    return 0;
}