#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 두 평행선 사이를 N(N <= 100000)개의 선으로 이었다. 각 선들의 양 끝의 위치가 주어질 때, 교차하지 않는 선의 개수를 구한다.
각 선의 양 끝 좌표는 +- 10^6 이하의 자연수이며, 같은 점에서 시작하거나 끝나는 선은 없다.

해결 방법 : 선의 왼쪽 부분의 좌표를 기준으로 선들을 정렬한 다음, 순서대로 선들을 확인한다.
만약 지금까지 나왔던 오른쪽 좌표의 끝보다 오른쪽에서 끝나는 선이라면 스택에 해당 선을 추가한다.
아닌 경우에는 스택에서 해당 선의 오른쪽 끝 이후에 끝나는 모든 선들을 지운다.
이를 반복하여 모든 선을 확인한 다음, 스택에 남은 선의 개수가 답이 된다.

주요 알고리즘 : 자료구조, 스택

출처 : USACO 2013F B3번
*/

int cross[103000][2], stack[103000];
int sz = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("crossings.in", "r");
        fo = fopen("crossings.out", "w");
    }
    int n, last = -INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cross[i][0], &cross[i][1]);
    }
    qsort(cross, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if ((sz <= 0 || cross[i][1] > stack[sz - 1]) && cross[i][1] > last) {
            stack[sz++] = cross[i][1];
            last = cross[i][1];
        }
        else {
            while (sz > 0 && stack[sz - 1] >= cross[i][1]) sz--;
        }
    }
    printf("%d", sz);
    return 0;
}