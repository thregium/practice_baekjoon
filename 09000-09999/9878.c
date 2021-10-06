#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 1m/s의 속도로 이동하는 점이 있다. 이 점이 일정한 거리를 이동하거나 일정한 시간이 되면 속도가 느려지는
N(N <= 10000)개의 지점이 주어질 때, 1000m를 이동하는 데 걸리는 시간을 구한다. 답은 반올림하여 출력한다.
한 번 느려질 때 마다 속도는 1m/s -> (1/2)m/s -> (1/3)m/s -> (1/4)m/s ... 순으로 줄어든다.

해결 방법 : 각 거리와 위치를 정렬한 다음, 매번 더 일찍 나오는 것까지 이동하여 그곳에서 속도를 줄인다.
일정 거리까지의 소요 시간과 일정 시간까지 이동 거리는 속도를 이용하면 간단히 구할 수 있다.
속도가 줄어들 때의 속도는 1 / (1 / spd + 1)라는 식으로 구할 수 있다.
1000m가 되는 순간이 오면 소요 시간을 구해서 출력한다. 거리 배열에 1000을 집어넣고 정렬하는 것도 좋다.

주요 알고리즘 : 구현, 수학, 정렬

출처 : USACO 2014J B2/S1번
*/

int tm[10300], dt[10300];
int ttp = 0, ddp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("slowdown.in", "r");
        fo = fopen("slowdown.out", "w");
    }
    int n, x, ti = 0, di = 0;
    char c;
    double time = 0.0, dist = 0.0, spd = 1.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &x);
        if (c == 'D') dt[ddp++] = x;
        else if (c == 'T') tm[ttp++] = x;
        else return 1;
    }
    dt[ddp++] = 1000.0;
    qsort(dt, ddp, sizeof(int), cmp1);
    qsort(tm, ttp, sizeof(int), cmp1);

    for (int i = 0; i <= n; i++) {
        if (ti == ttp || (di != ddp && (dt[di] - dist) / spd + time < tm[ti])) {
            time += (dt[di] - dist) / spd;
            dist = dt[di++];
            if (abs(dist - 1000.0) < 0.00001) {
                printf("%.0f", time);
                return 0;
            }
        }
        else {
            dist += (tm[ti] - time) * spd;
            time = tm[ti++];
        }
        spd = 1 / (1 / spd + 1);
    }
    return 1;
}