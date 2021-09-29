#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 15)마리의 소들이 있고, 이 소들은 3 가지 품종 가운데 하나이다. 이 소들 사이 같은 품종인지 여부로
조건들이 주어질 때, 소들의 품종으로 될 수 있는 경우의 수를 구한다.

해결 방법 : 백트래킹을 통해 각 소들의 품종을 하나씩 확인하며 현재까지의 조건에 맞는지 구한다.
소들의 품종이 될 수 있는지를 미리 정렬을 통한 전처리를 통해 좀 더 빠르게 구하는 것이 필요하다.

주요 알고리즘 : 백트래킹

출처 : USACO 2013M B3번
*/

int breed[16], rel[64][3];
int r = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    return big(ai, aj) > big(bi, bj) ? 1 : big(ai, aj) == big(bi, bj) ? 0 : -1;
}

void track(int n, int x, int k) {
    for (int i = 0; i < k; i++) {
        if (rel[i][0] > x || rel[i][1] > x) break;
        if (rel[i][2] != (breed[rel[i][0]] != breed[rel[i][1]])) return;
    }
    if (n == x) {
        r++;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        breed[x + 1] = i;
        track(n, x + 1, k);
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("assign.in", "r");
        fo = fopen("assign.out", "w");
    }
    int n, k;
    char c;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf(" %c %d %d", &c, &rel[i][0], &rel[i][1]);
        if (c == 'D') rel[i][2] = 1;
    }
    qsort(rel, k, sizeof(int) * 3, cmp1);

    track(n, 0, k);
    printf("%d", r);
    return 0;
}