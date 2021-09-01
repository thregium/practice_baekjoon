#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 구간이 주어질 때, 가장 많은 구간이 겹치게 되는 지점의 겹치는 구간 수를 구한다.
단, 시작점 또는 끝점인 경우도 겹치는 구간에 들어가고 시작점과 끝점이 같은 경우는 없다.

해결 방법 : 스위핑을 통해 해결 가능하다. 각 구간들의 시작점과 끝점들을 미리 저장해둔 다음 오름차순으로 정렬한다.
이때 정렬하며 같은 수인 경우 시작점이 먼저 오도록 정렬해야 한다. 그 다음으로는 가장 작은 수부터 차례로 올라가며
시작점이 나오면 1을 더하고 끝점이 나오면 1을 빼는 방식으로 해당 위치의 겹치는 구간을 구할 수 있다.
따라서, 이 값들 가운데 가장 큰 값을 구하면 답이 된다.

주요 알고리즘 : 스위핑, 정렬

출처 : PA 2002.05 1-2번
*/

int tra[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, b, r = 0, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        tra[i * 2][0] = a;
        tra[i * 2 + 1][0] = b;
        tra[i * 2 + 1][1] = 1;
    }
    qsort(tra, n * 2, sizeof(int) * 2, cmp1);
    for (int i = 0; i < 2 * n; i++) {
        if (tra[i][1]) c--;
        else c++;
        if (c > r) r = c;
    }
    printf("%d", r);
    return 0;
}