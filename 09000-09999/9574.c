#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 20000)마리의 소들이 있고, 각각의 소들은 각자의 온도 영역이 있다. 그 영역 내에 있다면 그 소는 Y만큼의
우유를 생산하고, 그 미만이라면 X, 그를 초과한다면 Z만큼의 우유를 생산한다. 가장 우유를 많이 생산할 때의 우유의 양을 구한다.
온도의 범위는 10^9 이하의 자연수이고, X, Y, Z는 0 이상 1000 미만의 정수이다.

해결 방법 : 모든 소들의 온도 영역의 시작점과 끝점 + 1(Z만큼 생산하기 시작되는 시점)을 정렬한다.
그 다음, 우유 생산량을 X * N으로 놓은 다음 낮은 온도부터 영역들을 확인하기 시작한다. 온도 영역의 시작점이 나오면
Y - X(X에서 Y로 변환)를 더하고, 끝점이 나오면 Z - Y(Y에서 Z로 변환)를 더한다.
같은 온도의 마지막마다 우유의 양을 최댓값과 비교해 최댓값을 갱신하고 나온 최댓값을 구하면 된다.

주요 알고리즘 : 정렬, 스위핑

출처 : USACO 2013N B2번
*/

int tst[40960][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("milktemp.in", "r");
        fo = fopen("milktemp.out", "w");
    }
    int n, x, y, z, res = 0, milk;
    scanf("%d %d %d %d", &n, &x, &y, &z);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tst[i * 2][0], &tst[i * 2 + 1][0]);
        tst[i * 2 + 1][0]++;
        tst[i * 2 + 1][1] = 1;
    }
    tst[n * 2][0] = -1;
    qsort(tst, n * 2, sizeof(int) * 2, cmp1);

    milk = x * n;
    for (int i = 0; i < n * 2; i++) {
        if (tst[i][1]) milk += z - y;
        else milk += y - x;
        if (tst[i][0] != tst[i + 1][0] && milk > res) res = milk;
    }
    printf("%d", res);
    return 0;
}