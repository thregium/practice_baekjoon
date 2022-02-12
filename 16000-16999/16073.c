#include <stdio.h>

/*
문제 : H * W(H, W <= 100) 크기의 칸과 주변 1개의 줄에 대해 주위 3 * 3 범위의 칸에서 칠해야 하는 칸이
각각 주어진다. 이때, 조건에 맞게 칠하는 방법이 있는 지 구하고, 있다면 그러한 방법을 출력한다.
없다면 impossible을 출력한다.

해결 방법 : 왼쪽 위 칸부터 오른쪽 아래로 칠해나가면 칠하는 방법이 유일함을 알 수 있다.
그렇게 칠한 다음 모든 칸들이 조건에 맞는 지 확인한다. 조건에 맞다면 그렇게 칠하는 방법이 답이므로
그대로 출력하고, 맞지 않는다면 impossible을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 구현

출처 : GCPC 2018 L번
*/

int clue[128][128], res[128][128];
int dxy[9][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {0, 0} };

int main(void) {
    int h, w, c, r = 1;
    scanf("%d %d", &h, &w);
    for (int i = 1; i <= h + 2; i++) {
        for (int j = 1; j <= w + 2; j++) {
            scanf("%d", &clue[i][j]);
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            c = 0;
            for (int k = 0; k < 9; k++) c += res[i + dxy[k][0]][j + dxy[k][1]];
            if (c != clue[i][j]) res[i + 1][j + 1] = 1;
        }
    }
    for (int i = 1; i <= h + 2; i++) {
        for (int j = 1; j <= w + 2; j++) {
            c = 0;
            for (int k = 0; k < 9; k++) c += res[i + dxy[k][0]][j + dxy[k][1]];
            if (c != clue[i][j]) r = 0;
        }
    }
    if (!r) {
        printf("impossible");
        return 0;
    }
    for (int i = 2; i <= h + 1; i++) {
        for (int j = 2; j <= w + 1; j++) printf("%c", res[i][j] ? 'X' : '.');
        printf("\n");
    }
    return 0;
}