#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 16)개의 발전소가 있다. 각 발전소들은 켜져있거나 꺼져있다. 꺼져있는 발전소를 키기 위해서는
켜져있는 발전소를 통해 간접적으로 켜야 하며, 그때 필요한 비용은 N * N 크기의 배열로 주어진다.
이때, P개 이상의 발전소를 키기 위해 필요한 최소 비용을 구한다. 킬 수 없다면 -1을 출력한다.

해결 방법 : 비트마스킹 DP를 사용해 풀 수 있다. 우선 모든 경우의 최소 비용을 무한대로 초기화한다.
그리고 현재 상태의 비용을 0으로 바꾼다.(현재 상태보다 적게 켜진 경우는 생각할 필요가 없기 때문에)
그 다음 모든 상태에 대해 해당 상태로 들어올 수 있는 모든 경우를 찾아가며 각 경우의 최솟값을 구한다.
다시 모든 상태를 살펴보면서 P개 이상의 발전기가 켜진 경우 가운데 가장 비용이 작은 것을 찾아나가면 된다.
간접적으로 발전소를 키는 방법이 항상 존재하므로 -1을 출력할 일은 없다.

주요 알고리즘 : DP, 비트DP

출처 : SRM 364 D1B / D2C
*/

int mem[65536], cost[32][32], bit[32];
char s[32];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, stt = 0, res = INF, p, cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    for (int i = 0; i < (1 << n); i++) mem[i] = INF;
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        stt += (s[i] == 'Y') * (1 << i);
    }
    mem[stt] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) bit[j] = ((i >> j) & 1);
        for (int j = 0; j < n; j++) {
            if (bit[j]) {
                for (int k = 0; k < n; k++) {
                    if (j != k && bit[k]) {
                        mem[i] = small(mem[i], mem[i - (1 << j)] + cost[k][j]);
                    }
                }
            }
        }
    }
    scanf("%d", &p);
    for (int i = 0; i < (1 << n); i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) cnt += ((i >> j) & 1);
        if (cnt >= p) res = small(res, mem[i]);
    }
    printf("%d", res == INF ? -1 : res);
    return 0;
}