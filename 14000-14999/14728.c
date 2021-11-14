#include <stdio.h>

/*
문제 : N(N <= 100)개의 과목이 있고, 각 과목의 배점과 공부 시간이 주어진다. 각 과목을 일부만 공부할 수는 없다면
시간 T(T <= 10000) 이내로 공부하여 얻을 수 있는 최고 점수를 구한다.

해결 방법 : 냅색 문제의 일종이므로 그러한 DP를 하면 된다.

주요 알고리즘 : DP, 냅색

출처 : 중앙대 2017P C번
*/

int chap[128][2], mem[128][10240];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, t, score = 0;
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &chap[i][0], &chap[i][1]);
        for (int j = 0; j <= t; j++) {
            mem[i][j] = big(mem[i - 1][j], j < chap[i][0] ? -1 : mem[i - 1][j - chap[i][0]] + chap[i][1]);
        }
    }
    for (int i = 0; i <= t; i++) {
        score = big(score, mem[n][i]);
    }
    printf("%d", score);
    return 0;
}