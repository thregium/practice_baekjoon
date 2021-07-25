#include <stdio.h>
#include <string.h>

/*
문제 : 최대 100장의 카드가 아래부터 차례로 주어질 때, K(K <= 100)회 섞은 후 카드의 순서를 구한다.

해결 방법 : 카드를 섞는 방법을 직접 구현한 후 K회 반복하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 문자열

출처 : ROI 2007H I번
*/

char cards[128], carda[128], cardb[128];
int len;

void shuffle(void) {
    for (int i = 0; i < len; i++) {
        if (i & 1) cardb[i >> 1] = cards[len - i - 1];
        else carda[i >> 1] = cards[len - i - 1];
    }
    strcpy(cards, cardb);
    strcat(cards, carda);
}

int main(void) {
    int k;
    scanf("%s", cards);
    len = strlen(cards);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        shuffle();
    }
    printf("%s", cards);
    return 0;
}