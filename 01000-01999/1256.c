#include <stdio.h>

/*
문제 : a가 N개, z가 M(N, M <= 100)개 있는 문자열 가운데 사전순으로 K(K <= 10^9)번째 문자열을 찾는다.

해결 방법 : 맨 앞 글자가 z가 되기 위해서는 K가 맨 앞 글자가 a개인 문자열의 수보다 커야 한다.
그 수의 개수는 a가 N - 1개, z가 M개인 문자열의 수와 같을 것이다. a가 N개, z가 M개인 문자열의 수는 (a + z)Ca와 같다.
이후로는 앞의 글자를 하나씩 지워가며 문자열을 찾으면 된다. 이때, 맨 앞 글자로 쓰이는 글자의 수를 1씩 줄여야 하고,
맨 앞 글자가 z가 되는 경우에는 K에서 (a + z)Ca만큼을 빼야 한다.

주요 알고리즘 : 수학, 조합론, DP
*/

int mem[256][256];

int main(void) {
    mem[0][0] = 1;
    for (int i = 1; i <= 200; i++) {
        mem[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (mem[i - 1][j] < 0 || mem[i - 1][j - 1] < 0) mem[i][j] = -1;
            else mem[i][j] = mem[i - 1][j] + mem[i - 1][j - 1];
            if (mem[i][j] > 1000000000) mem[i][j] = -1;
        }
    }
    int n, m, k, l;
    scanf("%d %d %d", &n, &m, &k);
    l = n + m;
    if (k > mem[l][m] && mem[l][m] >= 0) {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < l; i++) {
        if (k <= mem[n + m - 1][m] || mem[n + m - 1][m] < 0) {
            printf("a");
            n--;
        }
        else {
            printf("z");
            k -= mem[n + m - 1][m];
            m--;
        }
    }
    return 0;
}