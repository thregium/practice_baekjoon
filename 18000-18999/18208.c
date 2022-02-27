#include <stdio.h>
#define MOD 1000000007

/*
문제 : N(N <= 5000) 비트의 부울 값이 있다. 이때, M(M <= 10^6)개의 규칙을 모두 지키는 가짓수를 구한다.
각 규칙은 [L, R] 구간이 모두 같거나 다른 것이 있다는 내용으로 이루어져 있다.

해결 방법 : 우선 각 위치에서 같은 오른쪽 끝 위치까지 각각 확인하면서 같은 값들을 그룹으로 묶는다.
그런 다음, 각 위치에서 다른 왼쪽 가장 가까운 위치까지 그룹의 개수를 각각 확인하면서
해당 위치마다 달라야 하는 가장 작은 그룹 개수를 저장한다.
이를 이용해 X번째 값까지 확인했을 때 최근 Y개가 같은 것을 상태로 하여 그 때의 경우의 수를
각각 다이나믹 프로그래밍을 통해 구하면 된다.

주요 알고리즘 : DP, 스위핑?

출처 : MidC 2019 K번
*/

int group[5120], same[5120], diff[5120], gdiff[5120], mem[5120][5120];
char buff[16];

int main(void) {
    int n, m, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        group[i] = i;
        gdiff[i] = 103000;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %s", &a, &b, buff);
        if (buff[0] == 's') {
            if (b > same[a]) same[a] = b;
        }
        else {
            if (a > diff[b]) diff[b] = a;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (group[i] != group[i - 1]) group[i] = group[i - 1] + 1;
        for (int j = i; j <= same[i]; j++) group[j] = group[i];
    }
    for (int i = 1; i <= n; i++) {
        if (group[i] - group[diff[i]] < gdiff[group[i]]) gdiff[group[i]] = group[i] - group[diff[i]];
    }
    mem[0][0] = 2;
    for (int i = 1; i <= group[n]; i++) {
        if (gdiff[i] == 0) mem[i][1] = 0;
        for (int j = 1; j <= gdiff[i]; j++) {
            mem[i][j] = (mem[i - 1][j - 1] + mem[i][j]) % MOD;
            mem[i + 1][1] = (mem[i + 1][1] + mem[i][j]) % MOD;
        }
    }
    for (int i = 1; i <= gdiff[group[n]]; i++) r = (r + mem[group[n]][i]) % MOD;
    printf("%d", r);
    return 0;
}