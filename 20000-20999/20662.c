#include <stdio.h>
#include <stdlib.h>

/*
문제 : 독서실 방문자들이 오는 시각마다 앉는 자리의 규칙이 주어지고, 모든 방문자들의 입실과 퇴실 시각이 주어질 때,
주어지는 자리가 비어있는 시간이 얼마나 되는지 구한다.

해결 방법 : 모든 방문자들을 입실 시각에 따라 정렬한 다음, 순서대로 사용 좌석을 찾은 다음 이용 시간동안 해당 좌석을 점유한다.
이를 반복해 놓고 모든 시각에 대해 주어지는 자리가 비어있는 시각의 수를 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : shake! 2020 A번
*/

int lbr[768][128];
int tm[512][2];

int timecvt(int a) {
    return (a - 900) / 100 * 60 + a % 100;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int ac = *((int*)a + 1);
    int bc = *((int*)b + 1);
    if (ai > bi) {
        return 1;
    }
    else if (ai < bi) {
        return -1;
    }
    else if (timecvt(ac) - timecvt(ai) > timecvt(bc) - timecvt(bi)) {
        return 1;
    }
    else if (timecvt(ac) - timecvt(ai) < timecvt(bc) - timecvt(bi)) {
        return -1;
    }
    else {
        return 0;
    }
}

int find_seat(int n, int s) {
    int a, x, mdist = 0, mdistp = 0;
    a = 1;
    for (int i = 1; i <= n; i++) {
        if (lbr[s][i]) a = 0;
    }
    if (a) return 1;
    for (int i = 1; i <= n; i++) {
        if (lbr[s][i]) continue;
        for (x = 1;; x++) {
            if (i - x >= 1 && lbr[s][i - x]) break;
            if (i + x <= n && lbr[s][i + x]) break;
        }
        if (x > mdist) {
            mdist = x;
            mdistp = i;
        }
    }
    return mdistp;
}

int main(void) {
    int n, t, p, stime, etime, seat, r = 0;
    scanf("%d %d %d", &n, &t, &p);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &tm[i][0], &tm[i][1]);
    }
    qsort(tm, t, sizeof(int) * 2, cmp1);
    for (int i = 0; i < t; i++) {
        stime = (tm[i][0] - 900) / 100 * 60 + tm[i][0] % 100;
        etime = (tm[i][1] - 900) / 100 * 60 + tm[i][1] % 100;
        seat = find_seat(n, stime);
        for (int j = stime; j < etime; j++) {
            lbr[j][seat] = i + 1;
        }
    }
    for (int i = 0; i < 720; i++) {
        if (!lbr[i][p]) r++;
    }
    /*
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 720; j += 10) {
            printf("%c", lbr[j][i] ? lbr[j][i] + 'A' - 1 : '.');
        }
        printf("\n");
    }
    */
    printf("%d", r);

    return 0;
}