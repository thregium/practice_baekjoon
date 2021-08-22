#include <stdio.h>

/*
문제 : 길이 N(N <= 50)의 '('와 ')'로 이루어진 문자열 가운데 괄호가 완전하지 않은 K(K <= 2^N - 1)번째 문자열이 있는지 확인하고
있다면 그러한 문자열을 출력한다.

해결 방법 : 왼쪽에 (가 미리 있다고 가정하고 오른쪽에 남은 구간을 통해 만들 수 있는 괄호 문자열의 수를 미리 계산해 둔다.
i(i는 앞에 있는 '('의 수)가 0인 경우에는 괄호 문자열이 일반적인 괄호 문자열과 같고, 1 이상인 경우에는
괄호를 남은 칸들에 한번씩 넣어보며 왼쪽(i = i - 1)과 오른쪽(i = 0)의 괄호 문자열의 곱의 합으로 알아낼 수 있다.
이들을 전부 알아낸 후에는 i = 0일 때의 값과 비교해 K번째 문자열이 있는지를 확인한다.
만약 있는 경우에는 왼쪽에서부터 한칸씩 문자들을 알아내면 된다.

이는 '('로 시작하는 괄호ㄴㄴ 문자열이 앞에서 괄호가 깨졌다면 2^i(i는 남은 문자의 수)가지 경우가 있고,
깨지지 않았다면 2^i - (남은 문자의 수와 앞에 있는 '('의 수로 미리 계산해둔 괄호 문자열의 개수)가지 경우가 있으므로
만약 남은 K가 이 이상이라면 ')'로 시작하고, 미만이라면 '('로 시작하면 된다. 이때, ')'로 시작하는 경우는
해당하는 가짓수 만큼을 K에서 빼줘야 한다. 또한, 이로 인해 앞의 '('의 수가 음수가 된 경우에는 괄호가 깨진 것이므로
이후로는 괄호가 깨진 경우로 계산해야 한다.

주요 알고리즘 : DP, 조합론
*/

long long mem[64][64];
char res[64];

int main(void) {
    int n, par = 0, vld = 1;
    long long k;
    scanf("%d %lld", &n, &k);
    mem[0][0] = 1;
    for (int i = 2; i <= n; i += 2) {
        for (int j = 0, k = i - 2; j < i; j += 2, k -= 2) mem[0][i] += mem[0][j] * mem[0][k];
        //앞의 '('가 0개일 때의 괄호 문자열을 카탈란 수를 통해 구함
    }
    for (int lp = 1; lp <= n; lp++) {
        for (int i = 0; i <= n - lp; i++) {
            for (int rp = 0; rp < i; rp++) {
                mem[lp][i] += mem[lp - 1][rp] * mem[0][i - rp - 1];
                //lp : 왼쪽의 '(' 개수, i : 문자의 개수, rp : 오른쪽 ')'의 위치
            }
        }
    }
    if (k >= (1LL << n) - mem[0][n]) {
        //K번째 괄호ㄴㄴ 문자열을 만들 수 없는 경우
        printf("-1");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (vld) {
            //괄호가 깨지지 않은 경우
            if (k >= (1LL << (n - i - 1)) - mem[par + 1][n - i - 1]) {
                res[i] = ')';
                k -= (1LL << (n - i - 1)) - mem[par + 1][n - i - 1];
                par--;
                if (par < 0) vld = 0; //이번 ')'로 인해 괄호가 깨진 경우
            }
            else {
                res[i] = '(';
                par++;
            }
        }
        else {
            //이미 괄호가 깨진 경우
            if (k >= (1LL << (n - i - 1))) {
                res[i] = ')';
                k -= (1LL << (n - i - 1));
            }
            else res[i] = '(';
        }
    }
    printf("%s", res);
    return 0;
}