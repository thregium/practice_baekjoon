#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 16)개의 전구가 원형으로 있고, 처음의 상태가 주어진다. B(B <= 10^15)번의 동작이 끝나면 각 전구가
어떤 상태인지 구한다. 각 동작마다 직전의 상태에서 왼쪽의 전구가 켜진 상태였다면 직전 상태와 반대 상태로 전구를 바꾼다.
꺼진 상태였다면 직전 상태 그대로 간다.

해결 방법 : 전구의 상태로 가능한 가짓수는 많아야 65536(= 2^16)가지 뿐이다. 또한, 각 전구들은 켜짐과 꺼짐 두 가지
상태 뿐이므로 전구들의 상태를 수로 표현하는 것이 가능하다. 이를 이용해 전구들의 상태가 반복되는 지점을 찾아
그 때의 반복 주기와 반복하는 시점을 구하고, 그를 통해 각 전구들의 상태를 계산해내면 된다.

주요 알고리즘 : 구현, 비트마스킹

출처 : USACO 2013O B2번
*/

int mem[81920][16], last[65536];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("blink.in", "r");
        fo = fopen("blink.out", "w");
    }
    int n, x, sz, t = 0, f;
    long long b;
    scanf("%d %lld", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        mem[0][i] = x;
        t += (x << i);
    }
    for (int i = 0; i < (1 << n); i++) last[i] = -1;
    last[t] = 0;
    for (sz = 1;; sz++) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (mem[sz - 1][(j + n - 1) % n]) mem[sz][j] = !mem[sz - 1][j];
            else mem[sz][j] = mem[sz - 1][j];
            t += (mem[sz][j] << j);
        }
        if (last[t] >= 0) break;
        last[t] = sz;
    }
    f = sz - last[t];

    if (b < last[t]) {
        for (int i = 0; i < n; i++) {
            printf("%d\n", mem[b][i]);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            printf("%d\n", mem[(b - last[t]) % f + last[t]][i]);
        }
    }
    return 0;
}