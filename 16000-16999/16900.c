#include <stdio.h>
#define INF 1012345678

/*
문제 : R * C(R, C <= 500) 크기의 격자에 서로 다른 자연수들이 적혀 있다. 각 칸에서 주위의 칸에 쓰인 수들 가운데
가장 작은 칸이 쓰인 칸으로 이동 가능하다. 단, 해당 칸보다 수가 작아야 한다. 이때 각 칸에 도착하게 되는 지점의 수를 구한다.

해결 방법 : 각 칸들을 위상 정렬을 통해 진입 차수가 없는 칸부터 차례로 각 지점으로 이동한다.
이때, 칸의 수가 많기 때문에 다음 칸을 빠르게 찾기 위해 큐를 이용한다. 또한, 다음 칸을 찾을 때에도 진입 차수가 0이 아니라면
큐에 넣지 않아야 한다.

주요 알고리즘 : 그래프 이론, 위상 정렬
*/

int nums[512][512], moves[512][512][2], ins[512][512], res[512][512], q[524288][2];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
int qf = 0, qr = 0;

int main(void) {
    int r, c, x, y;
    scanf("%d %d", &r, &c);
    for (int i = 0; i <= r + 1; i++) {
        for (int j = 0; j <= c + 1; j++) {
            nums[i][j] = INF;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &nums[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            for (int d = 0; d < 8; d++) {
                if (nums[i + dxy[d][0]][j + dxy[d][1]] < nums[moves[i][j][0]][moves[i][j][1]] && nums[i + dxy[d][0]][j + dxy[d][1]] < nums[i][j]) {
                    //d 방향으로의 이동이 현재 칸의 값과 최고 방향의 칸으로의 이동 칸보다 값이 작을 때
                    moves[i][j][0] = i + dxy[d][0];
                    moves[i][j][1] = j + dxy[d][1];
                }
            }
            ins[moves[i][j][0]][moves[i][j][1]]++; //해당 방향의 진입 차수 + 1
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (ins[i][j] == 0) {
                //진입 차수가 없는 모든 칸을 큐에 집어넣음
                q[qr][0] = i;
                q[qr++][1] = j;
            }
            res[i][j] = 1; //모든 칸의 결괏값을 미리 1로 초기화
        }
    }
    while (qr > qf) {
        x = q[qf][0];
        y = q[qf++][1];
        if (moves[x][y][0] == 0) continue; //도착점인 경우, 이미 옮긴 경우
        else {
            if (ins[x][y]) continue; //진입 차수가 1이 아닌 경우
            res[moves[x][y][0]][moves[x][y][1]] += res[x][y]; //현 위치의 공을 전부 다음 위치로 옮김
            res[x][y] = 0;
            ins[moves[x][y][0]][moves[x][y][1]]--;
            if (ins[moves[x][y][0]][moves[x][y][1]]) continue; //진입 차수가 남은 칸은 큐에 넣지 않음
            q[qr][0] = moves[x][y][0];
            q[qr++][1] = moves[x][y][1];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}