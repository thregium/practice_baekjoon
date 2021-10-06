#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 1000)마리의 소들의 위치(<= 10^6)와 전염병에 걸렸는지 여부가 주어진다. 특정한 거리 R 이내에
전염병에 걸린 소가 있다면 전염된다고 할 때, 처음 전염병에 걸린 소가 최소 몇 마리인지 구한다.

해결 방법 : 특정한 거리 R이 넓을 수록 전염병에 처음 걸린 소가 적게 나올 것임을 알 수 있다.
R이 될 수 있는 가장 큰 값은 전염병에 걸린 소와 걸리지 않은 소의 가장 가까운 거리 - 1이다.
R을 알 수 있다면 앞쪽으로 R 거리 내에 전염병에 걸린 소가 있는 경우는 넘어가며 전염병에 걸린 소의 마릿수를 세면
최초로 전염병에 걸린 소의 마릿수를 알 수 있다.

주요 알고리즘 : 구현, 정렬

출처 : USACO 2020O B2번
*/

int cow[1024][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("socdist2.in", "r");
        fo = fopen("socdist2.out", "w");
    }
    int n, r = 0, rng = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cow[i][0], &cow[i][1]);
    }
    qsort(cow, n, sizeof(int) * 2, cmp1);
    for (int i = 1; i < n; i++) {
        if (cow[i][1] + cow[i - 1][1] == 1 && cow[i][0] - cow[i - 1][0] < rng) {
            rng = cow[i][0] - cow[i - 1][0];
        }
    }
    for (int i = 0; i < n; i++) {
        if (cow[i][1] == 0) continue;
        if (i > 0 && cow[i][0] - cow[i - 1][0] < rng) continue;
        r++;
    }
    printf("%d", r);
    return 0;
}