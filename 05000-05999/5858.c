#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)번 좌우로 이동한 기록이 주어질 때, 2번 이상 이동한 구간의 길이를 구한다.
출발지에서 멀어도 10^9 이내로만 이동하였다.

해결 방법 : 스위핑을 통해 해결 가능하다. 각 구간의 시작점과 끝점을 각각 배열에 넣고 위치 순으로 정렬한 다음,
시작점이 나올 때 마다 값을 늘리고 끝점이 나올 때 마다 값을 줄이다가 1에서 2로 올라가면 해당 위치를 기록하고
2에서 1로 내려가면 기록한 위치와의 차이를 구하는 결괏값에 더하는 방식이다.

주요 알고리즘 : 정렬, 스위핑

출처 : USACO 2013J B2번
*/

int paint[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("paint.in", "r");
        fo = fopen("paint.out", "w");
    }
    int n, lx = 0, x = 0, u, coat = 0, r = 0;
    char dr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &u, &dr);
        if (dr == 'L') x -= u;
        else x += u;
        paint[i * 2][0] = lx;
        paint[i * 2 + 1][0] = x;
        if (lx < x) paint[i * 2 + 1][1] = 1;
        else paint[i * 2][1] = 1;
        lx = x;
    }
    qsort(paint, n * 2, sizeof(int) * 2, cmp1);

    for (int i = 0; i < n * 2; i++) {
        if (paint[i][1]) {
            coat--;
            if (coat == 1) r += paint[i][0] - lx;
        }
        else {
            coat++;
            if (coat == 2) lx = paint[i][0];
        }
    }
    printf("%d", r);
    return 0;
}