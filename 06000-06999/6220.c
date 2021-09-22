#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 10)가지의 동전을 사용해서 C(C <= 1000)원을 만들려고 한다. 동전을 가장 적게 사용하여 만들었을 때
사용한 동전의 개수를 구한다. 단, 항상 C원을 만들 수 있는 경우만 주어진다.

해결 방법 : 동전을 사용해 C원을 만드는 경우를 백트래킹을 이용하여 해결한다. 이때, 이전에 C원을 만들었을 때의
사용한 동전 개수 최소량보다 많은 동전을 사용했다면 중간에 탐색을 종료해 좀더 빠르게 탐색하도록 한다.
또한, 마지막 동전의 경우 C원을 만들 수 없거나 최소량보다 많이 사용한다면 바로 종료하여 속도를 더 높일 수 있다.

주요 알고리즘 : 백트래킹

출처 : USACO 2007J B2번
*/

int coins[16];
int res = INF;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

void track(int n, int x, int m, int y, int z) {
    if (x == n) {
        if (m == y && z < res) res = z;
        return;
    }
    if (x == n - 1) {
        if ((m - y) % coins[x] || (m - y) / coins[x] >= res) return;
        else track(n, x + 1, m, m, z + (m - y) / coins[x]);
    }
    for (int i = 0; y + i * coins[x] <= m && z + i < res; i++) {
        track(n, x + 1, m, y + i * coins[x], z + i);
    }
}

int main(void) {
    int c, n;
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    qsort(coins, n, sizeof(int), cmp1);
    track(n, 0, c, 0, 0);
    printf("%d", res);
    return 0;
}