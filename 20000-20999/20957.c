#include <stdio.h>
#define MOD 1000000007

/*
문제 : N(N <= 10000)자리 수 가운데 각 자릿수의 합과 곱이 모두 7의 배수인 수의 개수를 구한다.
단, 각 수는 0으로 시작할 수 없다.

해결 방법 : 각 자릿수의 곱이 7의 배수가 되기 위해서는 자릿수 가운데 0이나 7이 존재해야 한다.
또한, 합이 7의 배수인 경우의 수는 현재까지 자릿수의 합을 7로 나눈 나머지를 기준으로 하는 다이나믹 프로그래밍으로 찾을 수 있다.
따라서, 다이나믹 프로그래밍을 통해 0이나 7이 존재하는지 여부와 현재까지 자릿수의 합을 7로 나눈 나머지를 기준으로 하면 답을 찾을 수 있다.
이때, 첫 수가 0인 경우는 포함하지 않기 위해 넘어가야 한다.

주요 알고리즘 : 다이나믹 프로그래밍, 정수론

출처 : 강원대 제1회 E번
*/

int mem[10240][7][2]; //N, 자릿수의 합 % 7, 0이나 7의 등장 여부

int main(void) {
    int t, n;
    scanf("%d", &t);
    mem[0][0][0] = 1; //초기 상태
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < 10; j++) {
            //각 자릿수
            if (i == 1 && j == 0) continue;
            for (int k = 0; k < 7; k++) {
                if (j == 0 || j == 7) {
                    mem[i][k][1] = (mem[i][k][1] + mem[i - 1][k][0]) % MOD; //0이나 7이 나온 경우에는 나오지 않은 경우에서 합칠 수 있다.
                    mem[i][k][1] = (mem[i][k][1] + mem[i - 1][k][1]) % MOD;
                }
                else {
                    mem[i][k][0] += mem[i - 1][(k + 14 - j) % 7][0]; //k - j를 7로 나눈 나머지가 이전 단계이다.
                    mem[i][k][1] += mem[i - 1][(k + 14 - j) % 7][1]; 
                }
                mem[i][k][0] %= MOD;
                mem[i][k][1] %= MOD;
            }
        }
    }
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        printf("%d\n", mem[n][0][1]);
    }
    return 0;
}