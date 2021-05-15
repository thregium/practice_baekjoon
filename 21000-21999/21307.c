#include <stdio.h>
#include <stdlib.h>

/*
문제 : NT(NT <= 100)개의 팀이 NP(NP <= 20)개의 문제에 대한 NS(NS <= 10000)개의 제출 기록이 있을 때, 순위 기준에 맞춰 순위를 매기고 순위표를 출력한다.
순위 기준은 다음과 같다. 1. 푼 문제 수가 많은 팀이 더 순위가 높다. 2. 푼 문제 수가 같다면 페널티가 적은 팀이 더 순위가 높다.
3. 페널티도 같다면 마지막으로 맞은 문제의 제출 시각이 빠른 팀이 더 순위가 높다. 4. 위 3가지 기준이 전부 같다면 동순위로 처리한다. 표시할 때에는 팀 번호 순으로 표시한다.
페널티는 다음과 같이 구한다. 각 문제마다 문제를 처음 맞기까지 걸린 시간(분) + 처음 맞기 전까지 틀린 횟수 * 20

해결 방법 : 문제에서 설명한 규칙대로 각 팀이 맞은 문제와 틀린 횟수를 기록하며 처음으로 맞은 경우 각 팀의 페널티를 업데이트한다.
기록이 끝나면 정렬을 통해 각 팀의 순위를 얻는다. 그 다음 정렬한 결과를 바탕으로 순위표를 출력하면 된다. 이때 동석차에 주의해야 한다.

주요 알고리즘 : 구현, 시뮬레이션, 정렬

출처 : GNY 2020 H번
*/

int teams[128][4], submits[128][32];

int cmp1(const void* a, const void* b) {
    //문제수 -> 페널티 -> 최종 제출 -> 팀 번호 순으로 정렬
    int ap = *((int*)a + 1);
    int bp = *((int*)b + 1);
    if (ap != bp) return ap < bp ? 1 : -1;
    int am = *((int*)a + 2);
    int bm = *((int*)b + 2);
    if (am != bm) return am > bm ? 1 : -1;
    int al = *((int*)a + 3);
    int bl = *((int*)b + 3);
    if (al != bl) return al > bl ? 1 : -1;
    int at = *(int*)a;
    int bt = *(int*)b;
    return at > bt ? 1 : at == bt ? 0 : -1;
}

int main(void) {
    int nt, np, ns, nr, t, p, m, d, x;
    teams[0][1] = -1;
    scanf("%d %d %d %d", &nt, &np, &ns, &nr);
    for (int i = 1; i <= nt; i++) {
        teams[i][0] = i;
    }
    for (int i = 0; i < ns; i++) {
        scanf("%d %d %d %d", &t, &p, &m, &d);
        if (m >= 300) break;
        if (submits[t][p] >= 0) {
            if (d) {
                teams[t][1]++; //맞은 문제수 업데이트
                teams[t][2] += m + submits[t][p] * 20; //페널티 업데이트
                teams[t][3] = m; //최종 제출 업데이트
                submits[t][p] = -submits[t][p] - 1;
            }
            else submits[t][p]++; //틀린 횟수 추가
        }
    }
    qsort(teams + 1, nt, sizeof(int) * 4, cmp1);
    for (int i = 1; i <= nt; i++) {
        x = i;
        while (teams[x][1] == teams[i][1] && teams[x][2] == teams[i][2] && teams[x][3] == teams[i][3]) x--; //문제수, 페널티, 최종 제출 시각이 전부 같다면 동석차 처리
        if (x >= nr) break;
        printf("%-3d %-3d %3d %4d\n", x + 1, teams[i][0], teams[i][1], teams[i][2]);
    }
    return 0;
}