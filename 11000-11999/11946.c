#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)명의 참가자와 M(M <= 15)개의 문제가 있다. Q(Q <= 10000)개의 제출 기록이 주어질 때,
이 기록들로 만들어지는 순위표를 출력한다. 동순위의 경우 번호 순으로 출력한다.

해결 방법 : 제출 기록이 주어지면 AC가 뜨기 전까지는 해당 문제의 페널티를 높인다.
AC가 뜨면 해당 문제의 페널티를 확인해 확정한다. 그 이후로 그 문제의 제출이 들어오면 무시한다.
모든 기록이 끝나면 모든 팀의 모든 문제에 대해 확인하여 푼 문제 수와 페널티를 구한다.
그 다음, 이를 순서대로 정렬한다.

주요 알고리즘 : 구현, 정렬

출처 : 고려대 2016 E번
*/

char buff[8];
int prob[128][16], res[128][3];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 2);
    bi = *((int*)b + 2);
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *(int*)a;
    bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, q;
    int time, team, num;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %s", &time, &team, &num, buff);
        if (prob[team][num] > 0) continue;
        if (!strcmp(buff, "AC")) {
            prob[team][num] = prob[team][num] * -20 + time;
            if (prob[team][num] == 0) prob[team][num] = 1012345678;
        }
        else {
            prob[team][num]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        res[i][0] = i;
        for (int j = 1; j <= m; j++) {
            if (prob[i][j] > 0) {
                res[i][1]++;
                if (prob[i][j] == 1012345678) continue;
                else res[i][2] += prob[i][j];
            }
        }
    }
    qsort(res + 1, n, sizeof(int) * 3, cmp1);
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
    }
    return 0;
}