#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 계란이 있고, M(M <= 1000)명의 사려는 사람이 있다. 각 사람들에게 계란을 최대 1개까지만 팔 수 있고,
사람들은 P_i(P_i <= 10^6) 이하의 가격이라면 계란을 산다고 한다. 이때, 이익을 최대로 하기 위해서는
가격을 얼마로 해야 하는지 구하고, 그때의 이익을 구한다. 단, 이익이 같은 경우 더 낮은 가격을 우선한다.

해결 방법 : P_i를 큰 순으로 정렬한 다음, 계란의 가격을 P_i에 해당하는 값으로 설정했을 때의 이익을 확인하고,
그 값들 가운데 가장 큰 것을 고른다. 이때의 이익은 i번째에 대해 i * P_i이다. 단, 계란이 N개이므로 N과 M중 작은 것까지만
확인해야 한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2008N B3번
*/

int eggs[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, best = 0, price = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &eggs[i]);
    }
    qsort(eggs, m, sizeof(int), cmp1);
    for (int i = 0; i < n && i < m; i++) {
        if (eggs[i] * (i + 1) >= best) {
            best = eggs[i] * (i + 1);
            price = eggs[i];
        }
    }
    printf("%d %d", price, best);
    return 0;
}