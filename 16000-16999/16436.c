#include <stdio.h>

/*
문제 : W * H(W, H <= 2500) 크기의 직사각형에서 K(K <= 100000)번의 다음 쿼리들에 응답한 후 결과를 구한다.
먼저 S가 주어진다. S가 1인 경우 px, py, qx, qy가 주어지고, px - qx, py - qy 범위의 직사각형의 비트를 뒤집는다.
S가 2인 경우 px, qx, r이 주어지고, (px, qx)에서 r칸 이내로 떨어진 칸들의 비트를 뒤집는다.

해결 방법 : 2차원 누적 합을 이용해 각 쿼리를 누적한 결과를 구할 수 있다.
1번 쿼리의 경우 직사각형의 왼쪽 위, (오른쪽 아래 + (1, 1))의 값에 1, (오른쪽 위 + (1, 0)), (왼쪽 아래 + (0, 1))의 값에 -1을 더하고,
2번 쿼리의 경우에는 마름모꼴의 위쪽과 (아래쪽 + (0, 2))의 값에 1, 양 옆의 칸에서 한칸 뒤에 -1을 더한다.
이때 더할 위치가 범위를 벗어나지 않도록 주의한다.
그리고 꼭지점에 속해있지 않은 점들의 값을 업데이트 하기 위해 위쪽 + (0, 1), 아래쪽 + (0, 1)에 1과 양 옆의 칸 + (1, 0)에 -1을 더한다.
그 다음으로 2차원 누적합을 한 다음 결과를 출력하면 된다.

주요 알고리즘 : 누적 합

출처 : 경북대 2018 말번
*/

char sums[2560][2560], sumd[2560][2560], cnts[2560][2560], cntd[2560][2560], res[2560][2560];
//char 형태로 저장하더라도 패리티만 보면 되므로 캐시 히트율을 높여 속도와 메모리 효율을 높일 수 있다.

int main(void) {
    int w, h, k, s, px, py, qx, qy, r;
    scanf("%d %d %d", &w, &h, &k);
    for (int kk = 0; kk < k; kk++) {
        scanf("%d", &s);
        if (s == 1) {
            scanf("%d %d %d %d", &px, &py, &qx, &qy);
            cnts[py][px]++; //왼쪽 위
            cnts[qy + 1][qx + 1]++; //오른쪽 아래
            cnts[py][qx + 1]--; //오른쪽 위
            cnts[qy + 1][px]--; //왼쪽 아래
        }
        else {
            scanf("%d %d %d", &px, &py, &r);
            cntd[py - r][px]++; //위쪽
            cntd[py + r + 2][px]++; //아래쪽
            cntd[py + 1][px + r + 1]--; //오른쪽
            if (px > r) cntd[py + 1][px - r - 1]--; //왼쪽 끝이 0이 아닌 경우
            else cntd[py + 1][2559]--; //왼쪽 끝이 0인 경우
            cntd[py - r + 1][px]++; //위쪽(안쪽)
            cntd[py + r + 1][px]++; //아래쪽(안쪽)
            cntd[py + 1][px - r]--; //왼쪽(안쪽)
            cntd[py + 1][px + r]--; //오른쪽(안쪽)
        }
    }

    for (int y = 0; y < h; y++) {
        sums[y][0] = cnts[y][0];
        for (int x = 1; x < w; x++) {
            sums[y][x] = sums[y][x - 1] + cnts[y][x]; //가로의 누적합을 구한다.
        }
    }
    for (int x = 0; x < w; x++) {
        for (int y = 1; y < h; y++) {
            sums[y][x] += sums[y - 1][x]; //세로의 누적합을 구한다.
        }
    }
    for (int y = 0; y < h; y++) {
        if (y == 0) sumd[y][0] = cntd[y][0];
        else sumd[y][0] = cntd[y][0] + cntd[y - 1][2559]; //-1번 칸에 대한 처리
        for (int x = 1; x + y < h; x++) {
            sumd[y + x][x] = sumd[y + x - 1][x - 1] + cntd[y + x][x]; //오른쪽 아래 대각선에 대한 누적합을 구한다. (왼쪽 출발)
        }
    }
    for (int x = 1; x < w; x++) {
        sumd[0][x] = cntd[0][x];
        for (int y = 1; x + y < w; y++) {
            sumd[y][y + x] = sumd[y - 1][y + x - 1] + cntd[y][y + x]; //오른쪽 아래 대각선에 대한 누적합을 구한다. (위쪽 출발)
        }
    }
    for (int y = 0; y < w + h; y++) {
        for (int x = w - 1; x >= 0; x--) {
            if (y < x + 1 || y - x > h) continue;
            sumd[y - x][x] += sumd[y - x - 1][x + 1]; //왼쪽 아래 대각선에 대한 누적합을 구한다.
        }
    }
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((sums[y][x] + sumd[y][x]) & 1) res[y][x] = '#'; //구한 누적합을 바탕으로 비트의 상태를 구한다.
            else res[y][x] = '.';
        }
    }
    for (int y = 0; y < h; y++) {
        printf("%s\n", res[y]);
    }
    return 0;
}