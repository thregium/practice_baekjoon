#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
#define SZ 131072

/*
문제 : 길이 N(N <= 100000)의 1부터 N까지의 자연수로 이루어진 순열이 주어질 때,
이 순열에서 길이 K(K <= 10)의 증가하는 부분 수열의 개수를 구한다.

해결 방법 : 길이 x의 i에서 종료하는 증가하는 부분 수열의 개수를 변수로 두고
다이나믹 프로그래밍을 진행하면 된다. 각 값은 이전 길이에서의 개수 가운데 현재 수보다 작은 수에서 끝나는
부분 수열의 개수 합과 같다. 이는 세그먼트 트리를 이용해 처리한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, DP?

출처 : ?
*/

int a[103000], mem[16][103000], seg[SZ * 2];

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return (getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1)) % MOD;
}

void upd(int a, int b) {
    seg[a + SZ] = (seg[a + SZ] + b) % MOD;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = (seg[i << 1] + seg[(i << 1) + 1]) % MOD;
    }
}

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        //a[i] = rand() % 100;
        scanf("%d", &a[i]);
        mem[1][i] = 1;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < SZ * 2; j++) seg[j] = 0;
        for (int j = 1; j <= n; j++) {
            mem[i][j] = getsum(0, a[j] - 1, 0, SZ - 1, 1);
            upd(a[j], mem[i - 1][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        r = (r + mem[k][i]) % MOD;
    }
    printf("%d", r);
    return 0;
}