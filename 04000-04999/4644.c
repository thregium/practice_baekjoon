#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
문제 : N(N <= 20)개의 팀에 대해 팀의 이름(<= 10자)과 각 문제를 푼 여부/ 푼 시간이 주어질 때,
각 팀의 순위표를 출력한다. 순위는 푼 문제 수 -> 푼 시간 합 -> 푼 시간의 기하평균으로 매겨진다.

해결 방법 : 각 팀의 푼 문제 수 합, 푼 시간 합, 기하평균 등을 구조체로 만들고, 각 값들을 입력받으며
그 값들을 계산한다. 그리고 순위 순서대로 정렬한 다음 그 순서대로 출력하면 된다.

주요 알고리즘 : 구현, 수학, 정렬

출처 : MidC 2002 A번
*/

typedef struct team {
    char name[16];
    int svd, sum, aveg;
    int prob[7];
} team;

team tm[32];

int cmp1(const void* a, const void* b) {
    team ai = *(team*)a;
    team bi = *(team*)b;
    if (ai.svd != bi.svd) return ai.svd < bi.svd ? 1 : -1;
    if (ai.sum != bi.sum) return ai.sum > bi.sum ? 1 : -1;
    if (ai.aveg != bi.aveg) return ai.aveg > bi.aveg ? 1 : -1;
    return strcmp(ai.name, bi.name);
}

int main(void) {
    int n, r;
    double gsum;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2002\\rank\\rank.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2002\\rank\\rank_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", tm[i].name);
            gsum = 0.0;
            for (int j = 0; j < 7; j++) {
                scanf("%d", &tm[i].prob[j]);
                tm[i].sum += tm[i].prob[j];
                if (tm[i].prob[j] > 0) {
                    tm[i].svd++;
                    gsum += log(tm[i].prob[j]);
                }
            }
            if (tm[i].svd > 0) {
                gsum /= tm[i].svd;
                tm[i].aveg = exp(gsum) + 0.500000001;
            }
        }
        qsort(tm, n, sizeof(team), cmp1);
        printf("CONTEST %d\n", tt);
        r = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && (tm[i].svd != tm[i - 1].svd || tm[i].sum != tm[i - 1].sum ||
                tm[i].aveg != tm[i - 1].aveg)) r = i + 1;
            printf("%02d %-10s %1d %4d %3d ", r, tm[i].name, tm[i].svd, tm[i].sum, tm[i].aveg);
            for (int j = 0; j < 7; j++) {
                printf("%3d%c", tm[i].prob[j], j == 6 ? '\n' : ' ');
            }
        }
        for (int i = 0; i < n; i++) {
            tm[i].aveg = 0, tm[i].sum = 0, tm[i].svd = 0;
        }
    }
    return 0;
}