#include <stdio.h>
#define MOD 1000000007

/*
문제 : N * M(N, M <= 300) 크기의 체스판에 A부터 L(L <= 26)번째 알파벳까지 알파벳 대문자들이 쓰여 있다.
50자 이하의 대문자로 이루어진 문자열이 주어질 때, 유니콘을 움직여 해당 단어를 만드는 방법을 구한다.
유니콘은 한쪽 방향으로 2칸 이상, 다른쪽 방향으로 3칸 이상 떨어진 칸으로 움직일 수 있는 말이다.

해결 방법 : 우선 첫 번째 문자가 일치하는 곳의 값을 1, 일치하지 않는 곳을 0으로 만든 후 다이나믹 프로그래밍을 진행한다.
매번 일치하는 곳은 이전 단계에서 올 수 있는 곳의 값의 합으로 두고, 일치하지 않는 곳은 0으로 둔다.

여기서 속도를 높이기 위해 누적 합을 시행해야 한다. 행과 열 단위로 각각 누적합을 진행하면
전체 값 - 인접한 행 3개와 열 3개의 값 + 인접한 3 * 3 크기의 값 - 행과 열이 모두 2개씩 떨어진 칸의 값을 통해
답을 구할 수 있다. 이때 범위를 벗어나지 않도록 유의해야 한다.
이를 반복하여 마지막 단계에 나온 전체 합이 답이 된다.

주요 알고리즘 : DP, 누적 합

출처 : TCO 2009R1 3번
*/

char chess[384][384], s[64];
int mem[384][384], nmem[384][384], hsum[384][384], vsum[384][384];

int main(void) {
    int n, m, l, tot = 0;
    scanf("%d %d %d", &n, &m, &l);
    scanf("%s", s);
    for (int i = 1; i <= n; i++) {
        scanf("%s", chess[i] + 1);
        for (int j = 1; j <= m; j++) {
            //기저 사례
            if (chess[i][j] == s[0]) mem[i][j] = 1;
            else mem[i][j] = 0;
            tot += mem[i][j];
            hsum[i][j] = hsum[i][j - 1] + mem[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) vsum[j][i] = vsum[j - 1][i] + mem[j][i];
    }
    
    for (int i = 1; s[i]; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (chess[j][k] != s[i]) {
                    //다른 문자인 경우 0으로 처리
                    nmem[j][k] = 0;
                    continue;
                }
                nmem[j][k] = tot; //전체

                nmem[j][k] = (nmem[j][k] + MOD - vsum[n][k]) % MOD; //열
                if (k > 1) nmem[j][k] = (nmem[j][k] + MOD - vsum[n][k - 1]) % MOD;
                if (k < m) nmem[j][k] = (nmem[j][k] + MOD - vsum[n][k + 1]) % MOD;
                nmem[j][k] = (nmem[j][k] + MOD - hsum[j][m]) % MOD; //행
                if (j > 1) nmem[j][k] = (nmem[j][k] + MOD - hsum[j - 1][m]) % MOD;
                if (j < n) nmem[j][k] = (nmem[j][k] + MOD - hsum[j + 1][m]) % MOD;

                for (int l = 0; l < 9; l++) {
                    if (j + (l % 3 - 1) >= 1 && j + (l % 3 - 1) <= n && k + (l / 3 - 1) >= 1 && k + (l / 3 - 1) <= m) {
                        nmem[j][k] = (nmem[j][k] + mem[j + (l % 3 - 1)][k + (l / 3 - 1)]) % MOD; //주변 칸 처리
                    }
                }
                if (j > 2 && k > 2) nmem[j][k] = (nmem[j][k] + MOD - mem[j - 2][k - 2]) % MOD; //2, 2 칸 처리
                if (j > 2 && k < m - 1) nmem[j][k] = (nmem[j][k] + MOD - mem[j - 2][k + 2]) % MOD;
                if (j < n - 1 && k > 2) nmem[j][k] = (nmem[j][k] + MOD - mem[j + 2][k - 2]) % MOD;
                if (j < n - 1 && k < m - 1) nmem[j][k] = (nmem[j][k] + MOD - mem[j + 2][k + 2]) % MOD;

            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) hsum[j][k] = (hsum[j][k - 1] + nmem[j][k]) % MOD; //행 누적합
        }

        tot = 0;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                mem[k][j] = nmem[k][j];
                tot = (tot + mem[k][j]) % MOD; //전쳇값
                vsum[k][j] = (vsum[k - 1][j] + mem[k][j]) % MOD; //열 누적합
            }
        }
    }
    printf("%d", tot);
    return 0;
}