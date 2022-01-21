#include <stdio.h>

/*
문제 : 52장의 카드들을 4명에게 13장씩 분배했다. 각 사람은 동서남북으로 앉아있고,
동서, 남북의 사람은 각각 같은 팀이다. 13 라운드의 게임 이후 더 많이 이긴 팀이 (이긴 횟수) - 6 만큼
점수를 얻는다. 모든 라운드에는 트럼프라 불리는 으뜸패가 존재한다.
각 라운드마다 선공부터 차례로 카드를 낸다. 으뜸패를 낸 사람이 있다면 으뜸패 가운데 최고 수를,
없다면 선공과 같은 것(선공 포함) 중 최고 수를 낸 사람(과 팀)이 그 라운드를 이긴다.
각 라운드를 이긴 사람이 다음 라운드의 선공이 된다. 첫 라운드의 선공이 북쪽에 앉은 사람이고,
각 라운드에 사람마다 낸 카드가 주어질 때, 이기는 팀과 그 팀이 얻는 점수를 구한다.

해결 방법 : 각 라운드마다 카드의 점수를 계산하고 가장 높은 점수를 가진 사람을 이기게 한다.
카드의 점수는 으뜸패를 가장 높게, 선공과 같은 것을 그다음 높게, 마지막으로 수에 따른 점수를 반영하면 된다.
이긴 사람을 다음 선공으로 하여 이를 반복한 다음, 남-북과 동-서팀의 점수를 확인해 결과를 출력한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JAG 2009P A번
*/

char card[4][16][4];

int getscore(char* c, char t, char l) {
    int r = 0;
    if (c[0] == 'A') r += 14;
    else if (c[0] == 'K') r += 13;
    else if (c[0] == 'Q') r += 12;
    else if (c[0] == 'J') r += 11;
    else if (c[0] == 'T') r += 10;
    else r += c[0] - '0';
    if (c[1] == t) r += 200;
    else if (c[1] == l) r += 100;
    return r;
}

int main(void) {
    int ew, ns, lead, best, bd, bcnt;
    char t;
    while (1) {
        scanf(" %c", &t);
        if (t == '#') break;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                scanf("%s", card[i][j]);
            }
        }
        ew = 0, ns = 0, bd = 0;
        for (int i = 0; i < 13; i++) {
            lead = bd;
            best = 0, bd = -1, bcnt = 1;
            for (int j = 0; j < 4; j++) {
                if (getscore(card[j][i], t, card[lead][i][1]) > best) {
                    best = getscore(card[j][i], t, card[lead][i][1]);
                    bd = j;
                    bcnt = 1;
                }
                else if (getscore(card[j][i], t, card[lead][i][1]) == best) bcnt++;
            }
            if (bcnt > 1 || bd < 0) return 1;
            if (bd & 1) ew++;
            else ns++;
        }

        if (ns > ew) printf("NS %d\n", ns - 6);
        else printf("EW %d\n", ew - 6);
    }
    return 0;
}