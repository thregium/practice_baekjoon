#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 16)개의 스테이지로 이루어진 게임이 있다. 각 스테이지는 아무 순서로나 깰 수 있으며,
모든 스테이지를 깨면 게임을 클리어할 수 있다. 각 스테이지를 깨면 아이템을 주고, 각 스테이지에는
아이템을 한 가지 들고 들어갈 수 있으며, 들고 가면 좀더 빨리 깰 수도 있다.
이때, 각 스테이지의 들고 간 아이템별 클리어 시간이 주어지면
전체 게임을 클리어하는데 드는 최소 시간을 구한다.

해결 방법 : 비트필드를 이용한 DP로 해결 가능하다. 해결한 스테이지의 목록을 비트마스킹의 형태로
저장하여 다이나믹 프로그래밍을 한다. 각 단계마다 아직 깨지 않은 스테이지를 현재 갖고 있는
아이템 가운데 가장 빠르게 깰 수 있는 것으로 깨고 그때의 시간으로 갱신해둔다.
이를 반복하며 모든 스테이지를 깼을 때의 최소 시간을 확인하면 답이 된다.

주요 알고리즘 : DP, 비트DP

출처 : JAG 2011D C번
*/

int t[32][32], bit[16], mem[65536];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                scanf("%d", &t[i][j]);
            }
        }
        for (int i = 1; i < (1 << n); i++) mem[i] = INF;
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) bit[j] = ((i >> j) & 1);
            for (int j = 0; j < n; j++) {
                if (bit[j]) continue;
                mem[i + (1 << j)] = small(mem[i + (1 << j)], mem[i] + t[j][0]);
                for (int k = 1; k <= n; k++) {
                    if(bit[k - 1]) mem[i + (1 << j)] = small(mem[i + (1 << j)], mem[i] + t[j][k]);
                }
            }
        }
        printf("%d\n", mem[(1 << n) - 1]);
    }
    return 0;
}