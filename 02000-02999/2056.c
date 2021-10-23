#include <stdio.h>

/*
문제 : N(N <= 10000)개의 작업들과 각 작업 별 선행 작업들, 각 작업에 걸리는 시간이 주어질 때,
모든 작업을 완료하기 위해 걸리는 최소 시간을 출력한다. 단, 선행 작업은 후행 작업보다 작업 번호가 작다.

해결 방법 : 작업 번호 순으로 해당 작업의 이전 작업 가운데 가장 오래 걸리는 것을 고르고,
해당 작업에 걸리는 시간을 더하면 해당 작업까지 걸리는 시간을 얻을 수 있다. 번호 순으로 이를 시행하면
모든 선행 작업의 시간을 미리 계산해 둘 수 있으므로 다이나믹 프로그래밍을 통해 작업 시간을 구할 수 있다.

주요 알고리즘 : 다이나믹 프로그래밍, 그래프 이론, 트리 DP
*/

int tm[10240], v[10240][128], mem[10240]; //tm : 해당 작업에 걸리는 시간, v : 해당 작업의 선행 작업(0은 선행 작업의 갯수), mem : 해당 작업까지 걸리는 시간

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &tm[i], &v[i][0]);
        for (int j = 1; j <= v[i][0]; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v[i][0]; j++) {
            if (mem[v[i][j]] > mem[i]) mem[i] = mem[v[i][j]];
        }
        mem[i] += tm[i];
        if (mem[i] > r) r = mem[i];
    }
    printf("%d", r);
    return 0;
}