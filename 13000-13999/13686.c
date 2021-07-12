#include <stdio.h>
#include <math.h>

/*
문제 : 2명의 플레이어가 있고, 각 턴마다 두 플레이어는 주사위를 굴린다. 이때 굴린 주사위의 값이 At(At <= 5) 이하인 경우
플레이어 1이 상대의 점수를 D(D <= 10)만큼 가져오고, 넘는 경우 플레이어 2가 상대의 점수를 D만큼 가져온다.
각 플레이어의 시작 점수 Ev1, Ev2(Ev1, Ev2 <= 10)와 D, At가 주어질 때, 플레이어 1이 이길 확률을 구한다.

해결 방법 : 희소 배열을 이용해 각 플레이어가 1번 주사위를 굴렸을 때 모든 지점에서 출발시 각 위치별로 이동할 확률을 구한다.
그 다음으로는 배열의 각 칸마다 (i - 1)번째에서 굴릿 횟수 * 2번 주사위를 굴렸을 때의 각 위치별 이동 확률을 구한다.
이는 다시 모든 칸에 대해 이전 단계와 현재 단계의 이동 확률의 곱을 구하면 된다. 이를 반복할 때 마다 양쪽 끝 중 하나로
이동하는 비율이 증가하게 되고, 충분히 많이 반복하면 양쪽 끝의 합이 1에 수렴한다.

1에 수렴하면 모든 지점에 대해 처음 상태에서 0으로 이동할 확률을 전부 구할 수 있고 이들을 미리 전부 저장해둔다.
그 다음 저장해둔 값을 꺼내 쓰면 된다.

주요 알고리즘 : 수학, 확률론, DP, 희소 배열

출처 : Brasil 2008 J번
*/

double arr[64][32][32]; //cnt, start, end
double mem[32][32][8]; //x, y, at

int main(void) {
    int ev1, ev2, at, d, x, y;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\J.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\J.out", "w", stdout);
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 8; k++) mem[i][j][k] = -1;
        }
    }
    while (1) {
        scanf("%d %d %d %d", &ev1, &ev2, &at, &d);
        if (d == 0) break;
        x = (ev1 + (d - 1)) / d;
        y = (ev2 + (d - 1)) / d;
        if (mem[x][y][at] > -1) {
            printf("%.1f\n", mem[x][y][at]);
            continue;
        }
        for (int k = 0; k < 64; k++) {
            for (int i = 0; i <= x + y; i++) {
                for (int j = 0; j <= x + y; j++) arr[k][i][j] = 0.0;
            }
        }
        for (int i = 1; i < x + y; i++) {
            arr[0][i][i] = 100.0;
            arr[1][i][i - 1] = 100.0 * (6.0 - at) / 6.0;
            arr[1][i][i + 1] = 100.0 * at / 6.0;
        }
        for (int i = 1; i < 63; i++) {
            arr[i][0][0] = 100.0;
            arr[i][x + y][x + y] = 100.0;
            for (int j = 1; j < x + y; j++) {
                for (int k = 0; k <= x + y; k++) {
                    for (int l = 0; l <= x + y; l++) {
                        arr[i + 1][j][l] += arr[i][j][k] * arr[i][k][l] / 100.0;
                    }
                }
            }
        }

        for (int i = 1; i < x + y; i++) {
            mem[i][x + y - i][at] = arr[63][i][x + y];
        }
        printf("%.1f\n", mem[x][y][at]);
    }
    return 0;
}