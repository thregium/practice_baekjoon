#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 두 명이 서로 달리기를 한다. 두 명은 N(N <= 1000)개와 M(M <= 1000)개의 구간을 각자 달린다.
각 구간에서 각 주자는 주어진 시간동안 주어진 속도로 달린다. 이때, 역전이 몇 회 일어나는지 구한다.
두 명이 끝나는 시각은 항상 같다. 또한, 주어진 사간과 속도는 둘 다 1000 이하의 자연수이다.

해결 방법 : 두 명의 움직임일 시뮬레이션하며 한 명이 더 앞서나갈 때 마다 마지막으로 앞서나간 사람과 다르다면
결괏값에 1을 더한다. 달리기가 끝나면 결괏값을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2013M B1번
*/

int bessie[1024][2], elsie[1024][2];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowrace.in", "r");
        fo = fopen("cowrace.out", "w");
    }
    int n, m, t = 0, bp = 0, ep = 0, bs = 0, es = 0, last = 0, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bessie[i][0], &bessie[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &elsie[i][0], &elsie[i][1]);
    }

    while (bs < n || es < m) {
        if (bessie[bs][1] == 0) bs++;
        bessie[bs][1]--;
        bp += bessie[bs][0];
        if (elsie[es][1] == 0) es++;
        elsie[es][1]--;
        ep += elsie[es][0];

        if (bp > ep) {
            if (last == 2) r++;
            last = 1;
        }
        else {
            if (last == 1) r++;
            last = 2;
        }

        t++;
    }
    printf("%d", r);
    return 0;
}