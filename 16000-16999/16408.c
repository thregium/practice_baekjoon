#include <stdio.h>

/*
문제 : 플레잉 카드 5장의 정보가 주어지면 같은 수가 최대 몇개 있는지 구한다.

해결 방법 : 각 수의 개수를 센 다음 가장 많은 것을 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : PacNW 2018 Q번 // MidC 2018 D번
*/

char cards[5][4];
int cnt[16];

int main(void) {
    int best = 0;
    scanf("%s %s %s %s %s", cards[0], cards[1], cards[2], cards[3], cards[4]);
    for (int i = 0; i < 5; i++) {
        if (cards[i][0] == 'A') cnt[1]++;
        else if (cards[i][0] == 'T') cnt[10]++;
        else if (cards[i][0] == 'J') cnt[11]++;
        else if (cards[i][0] == 'Q') cnt[12]++;
        else if (cards[i][0] == 'K') cnt[13]++;
        else cnt[cards[i][0] - '0']++;
    }
    for (int i = 0; i <= 13; i++) {
        if (cnt[i] > best) best = cnt[i];
    }
    printf("%d", best);
    return 0;
}