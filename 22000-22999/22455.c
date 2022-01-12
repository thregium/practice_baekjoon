#include <stdio.h>
#include <stdlib.h>

/*
문제 : T(T <= 50)개의 팀과 P(P <= 10)개의 문제, R(R <= 500)개의 문제 제출 로그가 주어질 때,
각 팀의 순위표를 작성해 출력한다. 제출 로그의 시간은 초 단위로 주어지며, 시간 순으로 주어지고,
같은 시각의 제출은 주어지지 않는다. 제출 로그의 결과는 정답/오답의 2가지로 한정된다. 또한, 규칙은 ICPC 룰을 따르고
순위표는 팀 번호, 해결 문제 수, 페널티 순으로 출력한다. 문제 수와 페널티가 같다면 번호가 빠른 순으로 출력한다.

해결 방법 : 각 팀이 해결한 문제수와 페널티를 배열로 저장하며, 각 팀의 각 문제에 대한 오답수와,
정답 여부를 또 배열에 저장한다. 오답인 제출이 들어오면 이전에 정답을 내지 않은 경우 오답수를 늘리고,
정답인 제출이 들어오면 오답수와 현재까지 소요 시간을 확인해 페널티를 추가하고 해결한 문제수를 1 늘린다.
모든 로그가 끝나면 각 팀의 순위를 ICPC 룰대로 정렬한 다음 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 정렬

출처 : JAG 2012D B번
*/

int team[64][3], pen[64][16], ac[64][16];
char buff[16];

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
    int t, p, r, ti, pi, tm;
    while (1) {
        scanf("%d %d %d", &t, &p, &r);
        if (t == 0) break;

        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= p; j++) {
                pen[i][j] = 0;
                ac[i][j] = 0;
            }
            team[i][0] = i;
            team[i][1] = 0, team[i][2] = 0;
        }

        for (int i = 0; i < r; i++) {
            scanf("%d %d %d %s", &ti, &pi, &tm, buff);
            if (ac[ti][pi]) continue;
            if (buff[0] == 'C') {
                team[ti][1]++;
                team[ti][2] += pen[ti][pi] * 1200 + tm;
                ac[ti][pi] = 1;
            }
            else {
                pen[ti][pi]++;
            }
        }
        qsort(team + 1, t, sizeof(int) * 3, cmp1);

        for (int i = 1; i <= t; i++) {
            printf("%d %d %d\n", team[i][0], team[i][1], team[i][2]);
        }
    }
    return 0;
}