#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)마리의 소들에게서 우유를 짜야 한다. 각 소에게서 우유를 짜는 시간이 s부터 t(s, t <= 1000)까지로 정해져 있고,
각 소에게서 우유를 짜는데 필요한 양동이의 양이 B(B <= 10)개로 정해져 있다고 한다면, 우유를 짜는데 필요한 양동이의 최소 양을 구한다.
물론, 동시에 한 양동이로 여러 소들에게서 우유를 짤 수는 없다.

해결 방법 : s가 빠른 순서대로 일정을 정렬한 다음, 현재 사용할 수 있는 양동이를 번호가 낮은 것 부터 찾는다.
찾은 양동이는 t까지 사용할 수 없는 상태로 기록해놓는다. 일정을 끝까지 확인한 다음 가장 큰 번호의 양동이가 쓰였을 때의 번호가 답이 된다.

주요 알고리즘 : 구현, 시뮬레이션, 그리디 알고리즘

출처 : USACO 2018D B2번
*/

int list[128][3], bucket[1024][1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("blist.in", "r");
        fo = fopen("blist.out", "w");
    }
    int n, p, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &list[i][0], &list[i][1], &list[i][2]);
    }
    qsort(list, n, sizeof(int) * 3, cmp1);

    for (int i = 0; i < n; i++) {
        p = 0;
        for (int j = 0; j < list[i][2]; j++) {
            while (bucket[p][list[i][0]]) p++;
            for (int k = list[i][0]; k <= list[i][1]; k++) {
                bucket[p][k] = i + 1;
            }
            if (p > mx) mx = p;
        }
    }
    printf("%d", mx + 1);
    return 0;
}