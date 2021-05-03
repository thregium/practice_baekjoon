#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : L(L <= 10^6)미터의 거리를 이동하는데 베시는 1미터를 rb초에 이동 가능하고, 존은 1미터를 rf초에 이동 가능하다.(rb < rf <= 10^6)
이때, N(N <= 100000)개의 쉼터가 있고, 각 쉼터는 고유한 행복도 ci(ci <= 10^6)가 존재한다.
베시가 이 쉼터에서 쉴 때의 행복도는 쉬는 시간 * 그 쉼터의 행복도와 같다. 베시가 존보다 뒤처지지 않아야 할 때, 베시가 얻을 수 있는 최대 행복도를 구한다.

해결 방법 : 베시는 가장 행복도가 높은 쉼터에서 최대한 오래 쉬는 것이 좋다. 따라서, 모든 쉼터들을 행복도 순으로 정렬한다.
그 다음, 맨 앞부터 시작해 현재 위치까지 해당 쉼터에서 최대한 쉬었을 때의 행복도를 추가하고,
다음부터는 그 위치 이후에 있는 쉼터 가운데 행복도가 가장 높은 쉼터를 조사한다. 이를 반복하면 모든 쉼터에서 가능한 오래 쉬며 최대한의 행복도를 얻을 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2018F S1번
*/

int rest[103000][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("reststops.in", "r");
        fo = fopen("reststops.out", "w");
    }
    int l, n, rf, rb, last = 0;
    long long result = 0;
    scanf("%d %d %d %d", &l, &n, &rf, &rb);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &rest[i][1], &rest[i][0]);
    }
    qsort(rest, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (rest[i][1] > last) {
            result += (rest[i][1] - last) * (long long)rest[i][0] * (rf - rb);
            last = rest[i][1];
        }
    }
    printf("%lld", result);
    return 0;
}