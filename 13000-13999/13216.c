#include <stdio.h>

/*
문제 : 두 명이 배드민턴을 한 기록이 주어질 때, 결과를 구한다. 3판 2선승제이고, 각 판은 21점을 먼저 따면 이긴다.
듀스는 고려하지 않아도 된다. 또한, 유효한 기록만 주어진다.

해결 방법 : 기록의 시작부터 확인하며 각 사람의 점수를 체크해 나간다. 21점이 되는 사람이 있으면 1승을 추가하고
점수를 리셋한다. 2승을 하는 사람이 나올 때 까지 이를 반복한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : MCO 2015 A번
*/

char s[1024];
int game[16][2];

int main(void) {
    int ar = 0, br = 0, g = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A') game[g][0]++;
        else if (s[i] == 'B') game[g][1]++;
        else return 1;
        if (game[g][0] == 21) {
            ar++;
            g++;
        }
        if (game[g][1] == 21) {
            br++;
            g++;
        }
    }
    if (ar > 2 || br > 2 || (ar == 2 && br == 2) || (ar < 2 && br < 2) || g > 3 || g < 2) return 2;
    for (int i = 0; i < g; i++) {
        printf("%d-%d\n", game[i][0], game[i][1]);
    }
    printf("%c", ar > br ? 'A' : 'B');
    return 0;
}