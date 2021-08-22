#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)명의 LTH 대회 결과와 추가 점수가 주어질 때, 각 참가자의 득점을 구한다. 순위는 ICPC 방식이고,
순위에 따른 배점은 미리 정해져있다. 만약 동점자가 나오는 경우 배점의 평균을 올림하여 결과를 구한다.

해결 방법 : 각 참가자의 대회 결과를 정렬하여 순위를 정한다. 그 다음, 1위부터 배점에 따른 점수를 각각 배정한다.
이 과정에서 동점에 대한 처리도 해준다. 추가 점수에 이 점수를 더한 값들을 각자 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : LTH 2017 I번
*/

int conts[1024][4], r[1024];
int scores[30] = { 100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

int cmp1(const void* a, const void* b) {
    int as = *(int*)a;
    int bs = *(int*)b;
    if (as != bs) return as < bs ? 1 : -1;
    int ap = *((int*)a + 1);
    int bp = *((int*)b + 1);
    if (ap != bp) return ap > bp ? 1 : -1;
    int af = *((int*)a + 2);
    int bf = *((int*)b + 2);
    return af > bf ? 1 : af == bf ? 0 : -1;
}

int main(void) {
    int n, x, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &conts[i][0], &conts[i][1], &conts[i][2], &x);
        if (x) r[i] = 1;
        conts[i][3] = i;
    }
    conts[n][0] = -1;
    qsort(conts, n, sizeof(int) * 4, cmp1);
    for (int i = 0; i < 30 && i < n; i++) {
        x = i, s = 0;
        while (conts[x][0] == conts[i][0] && conts[x][1] == conts[i][1] && conts[x][2] == conts[i][2]) {
            if (x < 30) s += scores[x];
            x++;
        }
        x--;
        s = (s + (x - i)) / (x - i + 1);
        for (int j = i; j <= x; j++) {
            r[conts[j][3]] += s;
        }
        i = x;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", r[i]);
    }
    return 0;
}