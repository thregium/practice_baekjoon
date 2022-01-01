#include <stdio.h>
#define INF 1012345678

/*
문제 : N * N(N <= 200) 크기의 체스판에 같은 행으로만 움직일 수 있는 말이 있다. 각 칸에는 점수(-10^6 <= 점수 <= 10^6, 정수)
이 말을 서로 공격받지 않게 놓으면서 이 말들이 놓인 칸의 점수 합을 최대로 하려고 할 때, 그때의 점수 합을 구한다.

해결 방법 : 각 줄마다 가장 점수가 높은 칸의 값을 구하여 더하면 된다. 단, 점수가 음수만 있는 경우 말을 놓지 않고
0점으로 만드는 것이 더 낫다.

주요 알고리즘 : 그리디 알고리즘

출처 : ILOCAMP 2010B 4-4번
*/

int main(void) {
    int n, r = 0, x, best;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        best = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (x > best) best = x;
        }
        r += best;
    }
    printf("%d", r);
    return 0;
}