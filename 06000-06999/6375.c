#include <stdio.h>

/*
문제 : 모양, 색, 무늬, 모양의 개수가 각각 3가지씩 존재하는 카드들을 12장씩 받는다. 이때, 3장의 카드들의 모양, 색, 무늬, 개수가
2장은 같고 1장만 다른 경우가 없다면 짝을 지을 수 있다고 한다. 이때, 각 카드들로 지을 수 있는 짝들을 모두 구한다.

해결 방법 : 카드의 수가 적기 때문에 모든 카드들에 대해 짝을 지을 수 있는지 확인해보면 된다.

주요 알고리즘 : 브루트 포스

출처 : GNY 2001 I번
*/

char cards[12][8];

int main(void) {
    int end = 0, t, cnt;
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2001\\i\\set.in", "r", stdin);
    while (1) {
        for (int i = 0; i < 12; i++) {
            if (scanf("%s", cards[i]) == EOF) {
                end = 1;
            }
            if (end) break;
        }
        if (end) break;
        printf("CARDS:  ");
        for (int i = 0; i < 12; i++) printf("%s ", cards[i]);
        printf("\nSETS:");

        cnt = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = i + 1; j < 12; j++) {
                for (int k = j + 1; k < 12; k++) {
                    t = 1;
                    for (int p = 0; p < 4; p++) {
                        if (cards[i][p] == cards[j][p] && cards[i][p] == cards[k][p]) continue;
                        if (cards[i][p] != cards[j][p] && cards[i][p] != cards[k][p] && cards[j][p] != cards[k][p]) continue;
                        t = 0;
                        break;
                    }
                    if (t) {
                        if (cnt == 0) printf("   ");
                        else printf("        ");
                        printf("%d.  %s %s %s\n", ++cnt, cards[i], cards[j], cards[k]);
                    }
                }
            }
        }

        if (cnt == 0) printf("   *** None Found ***\n");
        printf("\n");
    }
    return 0;
}