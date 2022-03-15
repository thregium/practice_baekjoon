#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 300)개의 블록이 쌓여있다. 각 블록의 무게는 1 이상 1000 이하의 자연수이다.
이때, 상하로 인접한 2개의 블록 무게 차가 1 이하인 경우 두 블록을 제거할 수 있다.
두 블록을 제거하면 그 위아래에 있는 블록들끼리 서로 붙게 된다. 이를 반복할 때,
제거할 수 있는 블록의 최대 개수를 구한다.

해결 방법 : 각 구간별로 해당 구간의 모든 블록을 제거할 수 있는 지 여부를 다이나믹 프로그래밍을 통해 구한다.
구간을 넓혀가며 확인하고, 각 구간에서는 맨 앞 또는 맨 뒤 블록과 함께 제거할 블록의 경우를 시도해 보며,
두 블록을 같이 제거 가능하며 남은 두 구간의 블록도 완전히 제거 가능한 지 확인하면 된다.

이 과정이 끝나면 다시 다이나믹 프로그래밍을 통해 구간의 제거 가능한 블록 수를 구하면 된다.

주요 알고리즘 : DP

출처 : JDC 2016 D번
*/

int w[384], able[384][384], mem[384][384];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i > j) able[i][j] = 1;
                else able[i][j] = 0;
            }
        }

        for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < n - i; j++) {
                for (int k = j + 1; k <= j + i; k += 2) {
                    if (abs(w[j] - w[k]) <= 1 && able[j + 1][k - 1] && able[k + 1][i + j]) {
                        able[j][i + j] = 1;
                    }
                }
                for (int k = i + j - 1; k >= j; k -= 2) {
                    if (abs(w[i + j] - w[k]) <= 1 && able[k + 1][i + j] && able[j][k - 1]) {
                        able[j][i + j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                mem[j][i + j] = 0;
                if (able[j][i + j]) {
                    mem[j][i + j] = i + 1;
                    continue;
                }
                for (int k = j + 1; k <= j + i; k++) {
                    if (mem[j][k - 1] + mem[k][i + j] > mem[j][i + j]) {
                        mem[j][i + j] = mem[j][k - 1] + mem[k][i + j];
                    }
                }
            }
        }
        printf("%d\n", mem[0][n - 1]);
    }
    return 0;
}