#include <stdio.h>
#include <string.h>
#define MOD 10000

/*
문제 : 길이 500 이하의 문자열이 주어질 때, 이 문자열의 일부 문자들을 지워(또는 지우지 않고)
만들 수 있는 "welcome to code jam" 문자열의 가짓수를 구한다.

해결 방법 : 주어진 문자열과 "welcome to code jam" 문자열의 각 지점마다 해당 문자에서 주어진 문자열의
마지막 지점이 되는 경우의 수를 매번 구해나간다. 만약 문자가 일치하지 않는다면 답은 0이고,
일치하는 경우 답은 주어진 문자열의 앞 모든 문자에 대해 welcome... 문자열의 바로 앞 글자인 경우의 수의
합과 같다. welcome... 문자열의 마지막 m에 대한 경우의 수를 모두 더한 것이 답이 된다.

주요 알고리즘 : DP, 문자열

출처 : GCJ 2009Q C2번
*/

char s[512];
int mem[512][24];
char* wtcj = "welcome to code jam";

int main(void) {
    int t, res;
    scanf("%d\n", &t);
    for (int tt = 1; tt <= t; tt++) {
        fgets(s, 503, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (s[0] == 'w') mem[0][1] = 1;
        mem[0][0] = 1;
        res = 0;
        for (int i = 1; s[i]; i++) {
            for (int j = 1; j <= 19; j++) {
                if (s[i] != wtcj[j - 1]) continue;
                for (int k = 0; k < i; k++) {
                    mem[i][j] = (mem[i][j] + mem[k][j - 1]) % MOD;
                }
            }
            res = (res + mem[i][19]) % MOD;
        }
        printf("Case #%d: %04d\n", tt, res);

        for (int i = 0; i < 512; i++) {
            for (int j = 0; j < 24; j++) mem[i][j] = 0;
        }
    }
    return 0;
}