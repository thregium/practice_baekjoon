#include <stdio.h>

/*
문제 : N(N <= 100)개의 팀이 참가하는 대회가 있고, 이 대회에 M(M <= 100)개의 학교에서
각각 T_i(T_i <= 100)개의 팀들이 신청했다. 각 학교에서 1명씩 순서대로 늘려가며 신청을 받을 때,
최종적으로 각 학교에서 참가하는 팀의 수를 구한다.

해결 방법 : 사람 수를 1부터 늘려가면서 참가할 수 있는 사람이 없어질 때 까지 각 학교의 신청을
받아나가면 된다. 더이상 참가할 수 있는 사람이 없다면 각 학교의 팀 수를 각각 출력한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : SCUSA 2021D2 L번 // MidC 2021 J번
*/

int t[128], r[128];

int main(void) {
    int n, m, end;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 1;; i++) {
        end = 1;
        for (int j = 0; j < m; j++) {
            if (t[j] < i) continue;
            r[j] = i;
            n--;
            end = 0;
            if (n == 0) {
                end = 1;
                break;
            }
        }
        if (end) break;
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", r[i]);
    }
    return 0;
}