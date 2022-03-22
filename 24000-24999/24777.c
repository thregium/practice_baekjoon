#include <stdio.h>

/*
문제 : 12장의 카드에 대해 짝을 이룰 수 있는 3장씩을 오름차순으로 모두 출력한다.
그러한 짝이 하나도 없다면 "no sets"를 출력한다. 짝을 이루기 위해서는 4가지 속성에 대해
각 카드가 모두 같거나 모두 달라야 한다.

해결 방법 : 카드의 장 수가 적기 때문에 모든 경우를 직접 시도해보면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : VTH 2015 C번
*/

char card[16][8];

int validtrio(int a, int b, int c) {
    for (int i = 0; i < 4; i++) {
        if (card[a][i] == card[b][i] && card[a][i] == card[c][i]) continue;
        else if (card[a][i] != card[b][i] && card[a][i] != card[c][i] && card[b][i] != card[c][i]) continue;
        else return 0;
    }
    return 1;
}

int main(void) {
    int cnt = 0;
    for (int i = 1; i <= 12; i++) {
        scanf("%s", card[i]);
    }
    for (int i = 1; i <= 12; i++) {
        for (int j = i + 1; j <= 12; j++) {
            for (int k = j + 1; k <= 12; k++) {
                if (validtrio(i, j, k)) {
                    printf("%d %d %d\n", i, j, k);
                    cnt++;
                }
            }
        }
    }
    if (cnt == 0) printf("no sets");
    return 0;
}
