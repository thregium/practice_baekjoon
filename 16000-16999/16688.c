#include <stdio.h>
#include <stdlib.h>
#define MOD 998244353

/*
문제 : N(N <= 1000)개의 자연수들 중 같은 수를 고르지 않고 K개를 뽑는 방법의 가짓수를 구한다.

해결 방법 : 먼저 자연수들이 각자 떨어져 있으므로 좌표 압축을 통해 자연수들을 붙여준다.
그 다음으로 붙은 자연수들을 각자 몇 개씩 있는지 세준다. 이제 각자 K개를 뽑는 방법을 다이나믹 프로그래밍을 통해 구해본다.
배열의 각 칸은 j번째 수까지 보았을 때, i개의 수를 세는 방법이 된다. 먼저 맨 윗줄은 개수의 누적합과 같다.
아랫줄로 가면 i번째 줄에서 i번부터 출발해서 mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1] * cnt[j]라는 점화식을 통해
값을 구하면 된다. 이제 K번째 줄의 마지막 번호를 보면 K개를 모든 수에서 뽑는 방법의 가짓수이므로 이 값을 출력하면 된다.

주요 알고리즘 : DP, 조합론, 좌표압축

출처 : PacNW C/P번
*/

int a[1024][2], cnt[1024], mem[1024][1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, l;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    a[0][1] = 1;
    cnt[1]++;
    for (int i = 1; i < n; i++) {
        if (a[i][0] == a[i - 1][0]) a[i][1] = a[i - 1][1];
        else a[i][1] = a[i - 1][1] + 1;
        cnt[a[i][1]]++; //좌표 압축
    }
    l = a[n - 1][1];
    for (int i = 1; i <= l; i++) mem[1][i] = (mem[1][i - 1] + cnt[i]) % MOD;
    for (int i = 2; i <= l; i++) {
        for (int j = i; j <= l; j++) {
            mem[i][j] = (mem[i][j - 1] + ((long long)mem[i - 1][j - 1] * cnt[j])) % MOD; //점화식
        }
    }
    printf("%d", mem[k][l]);
    return 0;
}