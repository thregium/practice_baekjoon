#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)마리의 소들이 수직선상에 있다. 같은 위치에 있는 소들은 없고 소들의 종류는 2 종류가 있다.
이때, 사진에 찍힌 소들의 마릿수가 같도록 사진을 찍으려고 한다면(한 종류만 있거나 두 종류가 같거나),
그렇게 찍는 방법 중 사진의 가장 큰 너비를 구한다. 사진의 너비는 찍은 사진에서 가장 왼쪽에 있는 소와
가장 오른쪽에 있는 소의 좌표 차이이다. 각 소들의 위치는 0 이상 10^9 이하의 정수이다.

해결 방법 : 사진을 찍는 방법은 두 가지가 있다. 두 종류의 소를 찍는 방법과 한 종류의 소를 찍는 방법이다.
한 종류의 소는 소들의 위치를 정렬하면 간단히 구현 가능하다.
두 종류의 소를 찍는 방법은 한 가지 품종의 소를 +1, 다른 품종의 소를 -1로 놓은 다음, 누적 합을 이용하는 것이다.
누적 합으로 각 누적 합별로 가장 먼저 나오는 소와 가장 늦게 나오는 소의 위치를 각각 구한 다음, 
가장 두 값의 차이가 큰 것을 고르면 된다.

두 가지 방법의 최댓값을 각각 구한 다음, 더 큰 것을 고르면 답이 된다.

주요 알고리즘 : 누적 합

출처 : USACO 2014O B2번
*/

int cow[103000][2], lowest[103000 * 2], highest[103000 * 2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("fairphoto.in", "r");
        fo = fopen("fairphoto.out", "w");
    }
    int n, x, s = 103000, r = 0, last = -1, r2 = 0;
    char b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &cow[i][0], &b);
        if (b == 'G') cow[i][1] = 1;
        else cow[i][1] = -1;
    }
    qsort(cow, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < 206000; i++) lowest[i] = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0) last = cow[i][0];
        else if (cow[i][1] != cow[i - 1][1]) {
            if (cow[i - 1][0] - last > r2) r2 = cow[i - 1][0] - last;
            last = cow[i][0];
        }

        if (lowest[s] < 0) lowest[s] = cow[i][0];
        s += cow[i][1];
        if (cow[i][0] > highest[s]) highest[s] = cow[i][0];
    }
    if (cow[n - 1][0] - last > r2) r2 = cow[n - 1][0] - last;
    for (int i = 0; i < 206000; i++) {
        if (lowest[i] < 0) continue;
        if (highest[i] - lowest[i] > r) r = highest[i] - lowest[i];
    }
    printf("%d", r > r2 ? r : r2);
    return 0;
}