#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 40)개의 풍선이 있고, 각 풍선은 t_i(t_i <= 50000)에 p_i(0 < p_i <= 100)에 떨어진다.
지점 0에는 창고가 있고, 한 번에 3개까지 풍선을 나를 수 있는 로봇이 있다.
이때, 로봇은 (갖고 있는 풍선 수 + 1)의 시간마다 1씩 이동 가능하다면, 모든 풍선을 전부 창고에
보관할 수 있는 지 구하고, 가능하다면 가장 이동 횟수가 적은 이동 횟수를 출력한다.
불가능하다면 잡을 수 없는 첫 풍선을 출력한다.

해결 방법 : 각 번째의 풍선마다 풍선의 개수에 대해 이동이 불가능하다면 무한대를,
이동이 가능하다면 최소 이동 횟수를 저장하는 다이나믹 프로그래밍을 한다.
로봇이 각 번째에 움직이는 방법은 두 가지로, 모든 풍선을 창고에 넣고 풍선으로 돌아오는 방법과,
현재 상태에서 풍선을 받는 방법이 있다. 두 가지 경우에 대해 이동 시간이 풍선이 떨어지는 간격 이하인 경우
이동이 가능하며, 그 때의 상태를 갱신해둔다.

이를 반복한 다음, 모든 풍선 개수에 대해 무한대가 저장된 줄이 나오면 그 풍선을 잡을 수 없는 경우로,
불가능한 경우이다. 마지막 줄까지 가능하다면 마지막 줄 가운데 가장 작은 값을 출력하면 된다.

주요 알고리즘 : DP

출처 : Tokyo 2010 B번
*/

int bal[64][2], mem[64][64];

int main(void) {
    int n, best;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &bal[i][0], &bal[i][1]);
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) mem[i][j] = INF;
        }

        mem[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                if (abs(bal[i][0] - bal[i - 1][0]) * j <= (bal[i][1] - bal[i - 1][1])) {
                    mem[i][j] = mem[i - 1][j - 1] + abs(bal[i][0] - bal[i - 1][0]);
                }
                if (bal[i - 1][0] * (j + 1) + bal[i][0] <= bal[i][1] - bal[i - 1][1]
                    && mem[i - 1][j] + bal[i - 1][0] + bal[i][0] < mem[i][1]) {
                    mem[i][1] = mem[i - 1][j] + bal[i - 1][0] + bal[i][0];
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            best = INF;
            for (int j = 1; j <= i; j++) {
                if (mem[i][j] < best) best = mem[i][j];
            }
            if (best == INF) {
                printf("NG %d\n", i);
                break;
            }
            if (i == n) {
                printf("OK %d\n", best + bal[n][0]);
            }
        }
    }
    return 0;
}