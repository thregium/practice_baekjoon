#include <stdio.h>

/*
문제 : B(B <= 21)개의 수들 가운데 일부 개수의 수들을 더해서 합이 C(C <= 35000) 이하의 가장 큰 수가 되도록 할 때, 그때의 합을 구한다.

해결 방법 : 매번 수들을 확인할 때 마다 현재까지의 수들 중 나올 수 있는 수들을 저장하며 냅색을 진행한다.
마지막 수까지 확인했을 때의 수들 가운데 C 이하에서 가장 큰 수를 찾으면 된다.

주요 알고리즘 : DP, 냅색

출처 : USACO 2006D B2번
*/

char mem[32][40960];

int main(void) {
    int c, b, x;
    scanf("%d %d", &c, &b);
    mem[0][0] = 1;
    for (int i = 1; i <= b; i++) {
        scanf("%d", &x);
        for (int j = 0; j < x; j++) mem[i][j] = mem[i - 1][j];
        for (int j = x; j <= c; j++) mem[i][j] = (mem[i - 1][j] | mem[i - 1][j - x]);
    }
    for (int i = c; i >= 0; i--) {
        if (mem[b][i]) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}