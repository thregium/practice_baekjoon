#include <stdio.h>
#define INF 987654321

/*
문제 : 외판원 순회 문제의 해를 구한다. (N <= 16)

해결 방법 : 비트마스킹과 다이나믹 프로그래밍을 통해 한 지점을 출발점으로 설정하고 모든 경우에 대해 이전에 가지 않은 경로의 비용과 현재의 비용을 비교해 더 비용이 낮은 경로를 선택한다.
모든 기록이 끝나면 출발점으로 돌아왔을 때 모든 지점을 돈 경우의 비용을 출력한다.

주요 알고리즘 : 다이나믹 프로그래밍, 비트마스킹
*/

int w[20][20], mem[20][65536];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, res = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
            if (!w[i][j]) w[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            mem[i][j] = INF;
        }
    }
    mem[0][0] = 0;
    for (int k = 0; k < (1 << n); k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
                if ((k >> j) % 2) {
                    mem[j][k] = small(mem[j][k], mem[i][k - (1 << j)] + w[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        res = small(res, mem[i][(1 << n) - 1]);
    }
    printf("%d", mem[0][(1 << n) - 1]);
    return 0;
}