#include <stdio.h>

/*
문제 : 길이가 100 이하인 세 문자열이 주어질 때, 세 문자열의 LCS를 구한다.

해결 방법 : 일반적인 LCS를 구할 때와 비슷하지만 3차원으로 저장한다.

주요 알고리즘 : DP, 문자열, LCS
*/

int mem[128][128][128];
char s[3][128];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    scanf("%s%s%s", s[0] + 1, s[1] + 1, s[2] + 1);
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                if (s[0][i] == s[1][j] && s[0][i] == s[2][k] && s[0][i]) mem[i][j][k] = mem[i - 1][j - 1][k - 1] + 1;
                else mem[i][j][k] = big(big(mem[i - 1][j][k], mem[i][j - 1][k]), mem[i][j][k - 1]);
            }
        }
    }
    printf("%d", mem[100][100][100]);
    return 0;
}