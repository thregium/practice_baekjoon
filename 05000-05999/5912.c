#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^6, N은 짝수)개의 0이 쓰인 칸이 있다. 이 칸들에서 K(K <= 25000)회 특정한 구간의 값을 1 올린다.
K개의 행동이 끝나고 N개의 칸들 중 중앙값을 구한다.

해결 방법 : 누적 합을 이용해 각 구간을 변화량으로 바꾸고, K개의 변화량의 합을 구한다.
각 변화량은 구간의 시작에서 +1이고, 끝에서 -1이다. 그 다음, 변화량을 누적 합을 이용해 합으로 다시 원래대로 바꾸어 준다.
이제 이들이 N개의 칸에 있던 값들이므로 이들을 정렬해 중앙값을 구해주면 된다.

주요 알고리즘 : 누적 합

출처 : USACO 2012J B2번
*/

int diffs[1048576], hays[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, a, b;
    //freopen("E:\\PS\\Olympiad\\USA\\Bronze\\2012_01\\stacking\\9.in", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        diffs[a] += 1;
        diffs[b + 1] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        hays[i] = hays[i - 1] + diffs[i];
    }
    qsort(hays + 1, n, sizeof(int), cmp1);
    printf("%d", hays[(n + 1) >> 1]);
    return 0;
}