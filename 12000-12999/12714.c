#include <stdio.h>
#include <string.h>

/*
문제 : 40자 이하의 숫자들이 주어질 때, 이 숫자 사이에 + 또는 - 부호를 끼워넣어
2, 3, 5, 7 가운데 하나 이상으로 나누어 떨어지는 수의 개수를 구한다.
부호가 없는 부분은 숫자들을 이어서 수를 만든 것으로 생각한다.

해결 방법 : 주어진 숫자들의 각 구간마다 2, 3, 5, 7로 나눈 나머지를 각각 구해둔다.
그 다음, 각 위치를 마지막 지점으로 하고 2, 3, 5, 7로 나눈 각 나머지가 상태로 있는 공간에
그러한 횟수를 각각 계산해 나간다.
최종적으로 마지막 위치에서 2, 3, 5, 7 가운데 하나라도 0인 것의 합을 구하면 답이 된다.

주요 알고리즘 : DP, 정수론

출처 : GCJ 2008C B2번
*/

const int div[4] = { 2, 3, 5, 7 };
int mod[4][64][64];
long long mem[64][2][3][5][7];
char n[64];

int main(void) {
    int t, l;
    long long r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", n + 1);
        l = strlen(n + 1);

        for (int m = 0; m < 4; m++) {
            for (int i = 1; i <= l; i++) {
                mod[m][i][i] = (n[i] - '0') % div[m];
                for (int j = i + 1; j <= l; j++) {
                    mod[m][i][j] = ((mod[m][i][j - 1] * 10) + (n[j] - '0')) % div[m];
                }
            }
        }

        mem[0][0][0][0][0] = 1;
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= i; j++) {
                for (int d1 = 0; d1 < 2; d1++) {
                    for (int d2 = 0; d2 < 3; d2++) {
                        for (int d3 = 0; d3 < 5; d3++) {
                            for (int d4 = 0; d4 < 7; d4++) {
                                mem[i][(d1 + mod[0][j][i]) % 2][(d2 + mod[1][j][i]) % 3]
                                    [(d3 + mod[2][j][i]) % 5][(d4 + mod[3][j][i]) % 7]
                                    += mem[j - 1][d1][d2][d3][d4];
                                if (j > 1) mem[i][d1][d2][d3][d4] +=
                                    mem[j - 1][(d1 + mod[0][j][i]) % 2][(d2 + mod[1][j][i]) % 3]
                                    [(d3 + mod[2][j][i]) % 5][(d4 + mod[3][j][i]) % 7];
                            }
                        }
                    }
                }
            }
        }

        r = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 5; k++) {
                    for (int ii = 0; ii < 7; ii++) {
                        if (i && j && k && ii) continue;
                        r += mem[l][i][j][k][ii];
                    }
                }
            }
        }

        printf("Case #%d: %lld\n", tt, r);

        memset(mem, 0, sizeof(mem));
    }
    return 0;
}