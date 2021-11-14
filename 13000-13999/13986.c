#include <stdio.h>

/*
문제 : R(R <= 64) * C(C <= 64) 크기의 배열에 '.', '#', 'a'가 주어질 때, 'a'를 중력에 맞게 '#'의 위로 떨어뜨린
형태를 출력한다. 'a'는 차례로 쌓여나간다.

해결 방법 : 'a'를 지우고 밑에서부터 채워나간다. 매번 'a'가 놓일 수 있는 가장 아래 위치에 놓는다.
'a'가 놓이면 그 위치를 한칸 위로 옮기고, '#'이 나오면 그 위치를 '#' 위로 옮긴다.

주요 알고리즘 : 구현, 투 포인터

출처 : PacNW 2016 S번
*/

char orig[64][64], res[64][64];

int main(void) {
    int r, c, last;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", orig[i]);
        for (int j = 0; j < c; j++) {
            if (orig[i][j] == '#') res[i][j] = '#';
            else res[i][j] = '.';
        }
    }
    for (int i = 0; i < c; i++) {
        last = r - 1;
        for (int j = r - 1; j >= 0; j--) {
            if (orig[j][i] == '#') last = j - 1;
            else if (orig[j][i] == 'o') res[last--][i] = 'o';
        }
    }
    for (int i = 0; i < r; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}