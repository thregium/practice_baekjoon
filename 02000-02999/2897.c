#include <stdio.h>

/*
문제 : R * C(R, C <= 50) 크기의 주차장 지도가 있을 때, 2 * 2 크기의 건물이 없는 장소 중 차가 0대, 1대, 2대, 3대, 4대인
곳의 개수를 각각 구한다. 건물은 '#', 차는 'X', 빈 칸은 '.'로 주어진다.

해결 방법 : 모든 2 * 2 칸에 대해 각각의 경우를 확인하면 된다.

주요 알고리즘 : 브루트 포스

출처 : COCI 09/10#5 2번
*/

char car[64][64];
int cnt[5];

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", car[i]);
    }
    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < c - 1; j++) {
            if (car[i][j] != '#' && car[i][j + 1] != '#' && car[i + 1][j] != '#' && car[i + 1][j + 1] != '#') {
                cnt[(car[i][j] == 'X') + (car[i][j + 1] == 'X') + (car[i + 1][j] == 'X') + (car[i + 1][j + 1] == 'X')]++;
            }
        }
    }
    for (int i = 0; i <= 4; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}