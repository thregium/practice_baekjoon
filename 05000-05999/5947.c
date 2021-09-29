#include <stdio.h>

/*
문제 : N(N <= 50000)명의 NQ(NQ <= 50)개 문항에 대한 설문조사 결과가 주어질 때, 이후 주어지는 P(P <= 10)개의 조건에
맞는 사람 수를 구한다. 각 조건은 서로 다른 문항 번호와 선택한 번호로 이루어져 있다.

해결 방법 : 각 사람에 대해 모든 조건에 만족하는지 한번씩 살펴보면 된다. 각 문항별로 주어진 답과 같은지 확인하다
맞지 않는 것이 있다면 넘어가고 끝까지 전부 맞다면 결괏값에 추가한다. 마지막의 결괏값이 답이 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : USACO 2010D B3번
*/

int resp[51200][64], crit[16][2];

int main(void) {
    int n, nq, p, r = 0, t;
    scanf("%d %d %d", &n, &nq, &p);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= nq; j++) {
            scanf("%d", &resp[i][j]);
        }
    }
    for (int i = 0; i < p; i++) {
        scanf("%d %d", &crit[i][0], &crit[i][1]);
    }

    for (int i = 1; i <= n; i++) {
        t = 1;
        for (int j = 0; j < p; j++) {
            if (resp[i][crit[j][0]] != crit[j][1]) {
                t = 0;
                break;
            }
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}