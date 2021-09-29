#include <stdio.h>

/*
문제 : 무게가 M(M <= 1000)이고 출력이 F(F <= 10^6)인 자동차가 있다. 이 자동차에 부품 N(N <= 20)개를 달 수 있다.
각 부품은 무게 M_i(M_i <= 1000)를 추가하고 출력 F_i(F_i <= 10^6)를 추가한다. 이때, 무게 대비 최대 출력을 내기 위해
달아야 하는 부품을 오름차순으로 모두 출력한다. 달지 않는 것이 가장 빠르다면 "NONE"을 출력한다.

해결 방법 : 2^N가지 방법을 비트마스킹을 통해 전부 해보면서 가장 F의 합 / M의 합이 가장 높은 조합을 찾는다.
그 조합의 번호를 비트마스킹한 값을 저장한 다음, 1번부터 차례로 비트 연산을 하면서 출력하면
해당 조합을 오름차순으로 출력할 수 있다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2010M B1번
*/

int parts[32][2];

int main(void) {
    int f, m, ft, mt, n, bestcomb = 0;
    double best;
    scanf("%d %d %d", &f, &m, &n);
    best = (double)f / m;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &parts[i][0], &parts[i][1]);
    }
    for (int i = 0; i < (1 << n); i++) {
        ft = f, mt = m;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ft += parts[j][0];
                mt += parts[j][1];
            }
        }
        if ((double)ft / mt > best) {
            best = (double)ft / mt;
            bestcomb = i;
        }
    }
    if (bestcomb == 0) printf("NONE");
    else {
        for (int i = 0; i < n; i++) {
            if (bestcomb & (1 << i)) printf("%d\n", i + 1);
        }
    }
    return 0;
}