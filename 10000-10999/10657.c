#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 직선상에 N(N <= 100000)개의 같은 방향으로 움직이는 점들이 있다. 각 점들이 서로를 추월할 수 없다면
충분히 시간이 지난 후 점들이 몇 개의 그룹이 되는지 구한다.

해결 방법 : 만약 어떠한 점 이후로 더 느린 점이 나타나면 그 점은 더 느린 점의 그룹에 합쳐지게 된다.
하지만 앞에 있는 점이 그 속도 이상이라면 합쳐지지 않는다. 이를 스택을 통해 구현하면 더 느린 점이 나올 때(또는 스택이 빌 때)
까지 스택을 비우고, 그 값을 스택에 추가하는 것을 반복한 후, 마지막 점까지 구했을 때의 스택의 크기가 답이 된다.

주요 알고리즘 : 자료구조, 스택

출처 : USACO 2014D B3번
*/

int run[103000][2], stack[103000];
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
        fi = fopen("cowjog.in", "r");
        fo = fopen("cowjog.out", "w");
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &run[i][0], &run[i][1]);
    }
    qsort(run, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        while (sz > 0 && stack[sz - 1] > run[i][1]) sz--;
        stack[sz++] = run[i][1];
    }
    printf("%d", sz);
    return 0;
}