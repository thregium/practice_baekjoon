#include <stdio.h>
#define INF 1012345678

/*
문제 : M(M <= 100)명의 상인에게 C(C <= 100)개의 컴퓨터를 팔려고 한다. 각 상인들은 순서대로 오며,
파는 컴퓨터의 개수마다 파는 가격(<= 100000, 자연수)이 주어진다. 이때, 컴퓨터를 팔아서 얻을 수 있는
최대 수익을 구한다. 모든 컴퓨터를 팔지 않아도 된다.

해결 방법 : 각 번째의 상인까지 팔았을 때 남은 컴퓨터의 수를 상태로 하고 그때의 최대 수익을
변수로 하여 DP를 진행하면 된다.

주요 알고리즘 : DP, 냅색

출처 : GCPC 2016 J번
*/

int merch[128][128], mem[128][128];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int c, m, r = -INF;
    scanf("%d %d", &c, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &merch[i][j]);
            mem[i][j] = -INF;
            mem[0][j - 1] = -INF;
        }
        mem[i][0] = -INF;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= c; j++) {
            for (int k = j; k <= c; k++) {
                mem[i][j] = big(mem[i][j], mem[i - 1][k] + merch[i][k - j]);
            }
        }
    }
    for (int i = 0; i <= c; i++) {
        r = big(r, mem[m][i]);
    }
    printf("%d", r);
    return 0;
}