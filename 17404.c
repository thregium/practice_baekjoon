#include <stdio.h>
#define INF 1234567890

/*
문제 : 원형으로 된 거리에 n개의 집이 있고, 이 집들 각각을 빨간색, 초록색, 파란색 가운데 하나로 칠해야 한다. 이때 서로 이웃한 집은 같은 색으로 칠할 수 없다면
각각의 집을 색상별로 칠하는 비용이 주어질 때 집을 칠하는 방법 가운데 가장 비용에 적게 드는 방법을 구한다.

해결 방법 : 원형으로 칠하는 집을 선형으로 분리한 뒤 첫 번째 집을 칠한 색에 따라서 다르게 저장한다. 이후 마지막 집의 비용까지 계산한 후 첫 번째 집과 마지막 집의
색상이 같은 경우는 비용을 무한대로 바꾸고, 마지막 집의 비용 가운데 가장 낮은 것을 출력한다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int mem[1024][3][3];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, r, g, b, res = INF;
    scanf("%d", &n);
    scanf("%d %d %d", &r, &g, &b);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                if (i == 0) mem[1][i][j] = r;
                if (i == 1) mem[1][i][j] = g;
                if (i == 2) mem[1][i][j] = b;
            }
            else mem[1][i][j] = INF;
        }
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d %d %d", &r, &g, &b);
        for (int j = 0; j < 3; j++) {
            mem[i][j][0] = small(mem[i - 1][j][1], mem[i - 1][j][2]) + r;
            mem[i][j][1] = small(mem[i - 1][j][0], mem[i - 1][j][2]) + g;
            mem[i][j][2] = small(mem[i - 1][j][0], mem[i - 1][j][1]) + b;
        }
    }
    //scanf("%d %d %d", &r, &g, &b);
    for (int i = 0; i < 3; i++) {
        mem[n][i][i] = INF;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) res = small(res, mem[n][i][j]);
    }

    printf("%d", res);
    return 0;
}