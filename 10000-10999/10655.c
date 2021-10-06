#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)개의 점들을 차례로 이동하되, 중간에 있는 한 점(첫 점과 마지막 점은 제외)은 건너뛰려고 한다.
거리 기준이 맨해튼 거리라면 이동하는데 걸리는 최단거리를 구한다. 모든 점의 좌표는 +- 1000 이하의 정수이다.

해결 방법 : 이 거리는 모든 점을 이동하는데 걸리는 거리에서 한 점을 빼고 이동하여 절약되는 거리을 뺀 값과 같다.
따라서, 모든 점을 이동하는데 걸리는 거리를 구한 다음, 가운데 있는 모든 점에 대해 한 점을 빼고 이동하여
절약되는 거리들 가운데 가장 큰 것을 구하고 첫 번째 값에서 두 번째 값을 빼면 된다.

주요 알고리즘 : 브루트 포스, 기하학

출처 : USACO 2014D B1번
*/

int pos[103000][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("marathon.in", "r");
        fo = fopen("marathon.out", "w");
    }
    int n, sum = 0, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        if (i > 0) sum += abs(pos[i][0] - pos[i - 1][0]) + abs(pos[i][1] - pos[i - 1][1]);
    }
    for (int i = 1; i + 1 < n; i++) {
        best = big(best, (abs(pos[i + 1][0] - pos[i][0]) + abs(pos[i + 1][1] - pos[i][1]))
            + (abs(pos[i - 1][0] - pos[i][0]) + abs(pos[i - 1][1] - pos[i][1]))
            - (abs(pos[i + 1][0] - pos[i - 1][0]) + abs(pos[i + 1][1] - pos[i - 1][1])));
    }
    printf("%d", sum - best);
    return 0;
}