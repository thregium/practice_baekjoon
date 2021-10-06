#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 4000)개의 벽이 있다. 벽 사이 거리가 벽의 크기보다 작다면 그 벽을 부술 수 있고, 이는 계속 반복할 수 있다.
이때, 벽들을 탈출할 수 없는 구간의 길이를 구한다. 벽의 위치는 0 이상 10^9 이하의 정수이다.

해결 방법 : 모든 벽의 쌍에 대해 부술 수 있는 벽인지 확인한다. 부술 수 없다면 사이의 모든 구간을 기록한다.
각 지점에 대해 부술 수 있는 가장 넓은 쌍만 확인해야 시간 내에 도는 것이 가능하다.
기록한 구간들의 너비를 전부 더한 것이 답이 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : USACO 2015O B3번
*/

int hay[4096][2], itv[4096];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("trapped.in", "r");
        fo = fopen("trapped.out", "w");
    }
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &hay[i][1], &hay[i][0]);
    }
    qsort(hay, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (hay[i][1] >= (hay[j][0] - hay[i][0]) && hay[j][1] >= (hay[j][0] - hay[i][0])) {
                for (int k = i; k < j; k++) {
                    itv[k] = 1;
                }
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (itv[i]) r += (hay[i + 1][0] - hay[i][0]);
    }
    printf("%d", r);
    return 0;
}