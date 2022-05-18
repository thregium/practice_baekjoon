#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 4개의 카드가 주어질 때, 다음 조건 중 하나 이상을 만족하는 지 구한다.
1. 세 카드의 알파벳이 같고 수가 연속하는 경우
2. 세 카드가 서로 같은 경우
3. 같은 카드의 쌍이 2개 있는 경우

해결 방법 : 각 카드들을 정렬한 다음, 각 조건을 확인한다. 3개 연속 조건에 유의해야 한다.

주요 알고리즘 : 구현, 정렬

출처 : 서강대 2022H C번
*/

char card[4][4];

int isgood(void) {
    if (!strcmp(card[0], card[1]) && !strcmp(card[2], card[3])) return 1;
    if (!strcmp(card[1], card[2]) && (!strcmp(card[0], card[1]) || !strcmp(card[2], card[3]))) return 2;
    if (card[0][1] == card[1][1] && card[1][1] == card[2][1] && card[0][0] + 1 == card[1][0] && card[1][0] + 1 == card[2][0]) return 10;
    if (card[0][1] == card[1][1] && card[1][1] == card[3][1] && card[0][0] + 1 == card[1][0] && card[1][0] + 1 == card[3][0]) return 11;
    if (card[0][1] == card[2][1] && card[2][1] == card[3][1] && card[0][0] + 1 == card[2][0] && card[2][0] + 1 == card[3][0]) return 12;
    if (card[1][1] == card[2][1] && card[2][1] == card[3][1] && card[1][0] + 1 == card[2][0] && card[2][0] + 1 == card[3][0]) return 13;
    return 0;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 4; i++) {
            scanf("%s", card[i]);
        }
        qsort(card, 4, sizeof(char) * 4, strcmp);
        printf("%s\n", isgood() ? ":)" : ":(");
    }
    return 0;
}