#include <stdio.h>

/*
문제 : N * N(N <= 7) 크기의 격자로 카드들을 늘어놓았다. 카드의 왼쪽 아래에서 오른쪽 위로 위쪽 또는 오른쪽으로 이동하며
얻을 수 있는 문양의 개수 합을 구한다.

해결 방법 : 카드의 무늬는 중요하지 않고 문양 개수만 필요하기 때문에 카드에서 문양 개수 정보만을 빼온다.
그 다음, 왼쪽 아래에서 시작하는 DP를 통해 오른쪽 위에서의 답을 구하면 된다.

주요 알고리즘 : DP

출처 : USACO 2007O B1번
*/

int cards[8][8], mem[8][8];
char buff[8];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= n; j++) {
            scanf("%s", buff);
            if (buff[0] == 'K') cards[i][j] = 13;
            else if (buff[0] == 'Q') cards[i][j] = 12;
            else if (buff[0] == 'J') cards[i][j] = 11;
            else if (buff[0] == 'T') cards[i][j] = 10;
            else if (buff[0] == 'A') cards[i][j] = 1;
            else cards[i][j] = buff[0] - '0';
            if (cards[i][j] <= 0 || cards[i][j] > 13) return 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mem[i][j] = big(mem[i - 1][j], mem[i][j - 1]) + cards[i][j];
        }
    }
    printf("%d", mem[n][n]);
    return 0;
}