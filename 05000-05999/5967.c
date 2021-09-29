#include <stdio.h>
#define INF 1012345678

/*
문제 : H * W(H, W <= 25) 크기의 격자에 10^6 이하인 서로 다른 자연수들이 쓰여있다. 이 격자에서 줄 단위로 순서를 바꾸어가며
가능한 최대로 정렬한 결과를 출력한다. 가장 높은 수부터 낮은 수까지 차례로 찾아가며 더 높은 수들을 건드리지 않고
바꿀 수 있는 가장 높은 자리와 바꾸는 식이다.

해결 방법 : 문제에 주어진대로 구현한다. 모든 값이 서로 다르기 때문에 가장 높은 수부터 차례로 확인하며
앞의 줄 가운데 가장 앞쪽의 아직 고정되지 않은 줄을 찾아 바꾸는 것을 반복하면 된다. 한번 쓰인 수가 있는 줄은 고정해두고
앞으로 더 움직이지 못하도록 한다. 또한, 움직이지 않는 경우가 움직이는 것 보다 더 좋은 경우도 있음에 유의한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2011F B2번
*/

int merit[32][32], visr[32], visc[32];

int main(void) {
    int h, w, prev = INF, best, bx, by, br, bc, t;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &merit[i][j]);
        }
    }

    for (int i = 0; i < h * w; i++) {
        best = 0;
        bx = -1;
        by = -1;
        //현재까지의 값들 가운데 최고인 칸을 찾는다.
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                if (merit[x][y] < prev && merit[x][y] > best) {
                    best = merit[x][y];
                    bx = x;
                    by = y;
                }
            }
        }
        if (bx < 0) return 1;

        prev = best;
        br = bx;
        bc = by;
        //아직 탐색하지 않은 가장 앞쪽 줄을 찾는다. 해당 줄 이전의 모든 줄을 탐색했다면 해당 줄 그대로 간다.
        for (int x = bx - 1; x >= 0; x--) {
            if (!visr[x]) br = x;
        }
        for (int y = by - 1; y >= 0; y--) {
            if (!visc[y]) bc = y;
        }

        //찾은 줄들을 바꾼다.
        if (br != bx) {
            for (int j = 0; j < w; j++) {
                t = merit[bx][j];
                merit[bx][j] = merit[br][j];
                merit[br][j] = t;
            }
        }
        if (bc != by) {
            for (int j = 0; j < h; j++) {
                t = merit[j][by];
                merit[j][by] = merit[j][bc];
                merit[j][bc] = t;
            }
        }
        visr[br] = 1;
        visc[bc] = 1;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", merit[i][j]);
        }
        printf("\n");
    }
    return 0;
}