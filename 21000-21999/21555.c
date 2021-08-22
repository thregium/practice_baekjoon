#include <stdio.h>

/*
문제 : N(N <= 200000)개의 수로 이루어진 두 수열이 있다. 두 수열의 수들 중 하나씩을 골라 N개의 수의 합 + (K * 바꾼 횟수)를
최소로 만들었을 때의 값을 고른다.

해결 방법 : 다이나믹 프로그래밍을 통해 해결할 수 있다. 마지막으로 고른 수열마다 그때의 최솟값을 저장해두면 된다.

주요 알고리즘 : DP

출처 : 폴리매스 2D2 C번
*/

int a[204800], b[204800];
long long mem[204800][2];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    mem[0][0] = a[0], mem[0][1] = b[0];
    for (int i = 1; i < n; i++) {
        mem[i][0] = small(mem[i - 1][0], mem[i - 1][1] + k) + a[i];
        mem[i][1] = small(mem[i - 1][1], mem[i - 1][0] + k) + b[i];
    }
    printf("%lld", small(mem[n - 1][0], mem[n - 1][1]));
    return 0;
}