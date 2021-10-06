#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 1부터 N(N <= 10^9)까지의 수가 순서대로 있다. 이때, K(K <= 1000)개의 쌍은 서로 같은 구간에 있을 수 없다면
모든 수를 나누는 구간의 개수 최솟값을 구한다.

해결 방법 : 각 쌍들을 작은 수를 기준으로 정렬한다. 그 다음, 각 쌍들을 확인하며 같이 있을 수 없는 가장 작은 수를 찾는다.
만약 쌍의 작은 수가 같이 있을 수 없는 구간에 있다면 그곳부터 새로운 구간을 시작하고 다시 가장 작은 수를 갱신해 나가면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2013O B3번
*/

int unfr[1024][2];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("photo.in", "r");
        fo = fopen("photo.out", "w");
    }
    int n, k, high = INF, r = 1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &unfr[i][0], &unfr[i][1]);
        if (unfr[i][0] > unfr[i][1]) swap(&unfr[i][0], &unfr[i][1]);
    }
    unfr[k][0] = n;
    qsort(unfr, k, sizeof(int) * 2, cmp1);
    for (int i = 0; i <= k; i++) {
        if (unfr[i][0] >= high) {
            r++;
            high = INF;
        }
        if (unfr[i][1] < high) high = unfr[i][1];
    }
    printf("%d", r);
    return 0;
}