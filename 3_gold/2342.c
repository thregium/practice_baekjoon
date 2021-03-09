#include <stdio.h>
#define INF 1234567890

/*
문제 : DDR에서 각 타일들을 밟아야 할 위치가 주어질 때 최소한으로 드는 에너지의 양을 구한다. 같은 타일을 연속으로 밟으면 1, 중앙에서 바깥 타일로 발을 이동하면 2,
인접한 바깥 타일끼리 이동하면 3, 반대 타일로 이동하면 4만큼의 에너지를 소모한다.

해결 방법 : 양발의 위치별로 밟은 타일의 갯수당 최소 에너지를 저장한다. 밟아야 할 타일의 위치가 주어지면 이전 타일까지 발의 위치에서 현재 타일로 옮기는데 드는 에너지를
비교해가며 현재 타일까지 밟았을 때의 최소 에너지 가운데 최솟값을 저장한다. 끝까지 완료하면 마지막 타일까지 밟았을 때의 모든 발의 위치 가운데 최소 에너지를 출력한다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int move[103000], mem[5][5][103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int nrg(int a, int b) {
    if (a == b) return 1;
    if (a == 0 || b == 0) return 2;
    if (a - b == 2 || b - a == 2) return 4;
    return 3;
}

int main(void) {
    int n = 1, res = INF;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 102400; k++) mem[i][j][k] = INF;
        }
    }
    mem[0][0][0] = 0;
    while (1) {
        scanf("%d", &move[n]);

        if (move[n] == 0) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    res = small(res, mem[i][j][n - 1]);
                }
            }
            break;
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                mem[i][move[n]][n] = small(mem[i][move[n]][n], mem[i][j][n - 1] + nrg(j, move[n]));
                mem[move[n]][j][n] = small(mem[move[n]][j][n], mem[i][j][n - 1] + nrg(i, move[n]));
            }
        }
        n++;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            res = small(res, mem[i][j][n - 1]);
        }
    }
    printf("%d", res);
    return 0;
}