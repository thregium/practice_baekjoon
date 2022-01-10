#include <stdio.h>

/*
문제 : N(N <= 50)명이 돌 P(P <= 50)개를 갖고 다음 게임을 플레이한다. 게임에서 이기는 사람을 구한다.
각 사람들에게 0번부터 N - 1번까지 번호를 붙이고 원형으로 앉는다. 그리고 그릇에 P개의 돌을 넣는다.
0번 사람부터 시작하여 자신의 차례에 그릇에 돌이 있다면 그릇에서 1개를 가져오고, 없다면 갖고 있는 모든 돌을 넣는다.
자신의 차례에 P개의 돌을 모두 갖게 되면 그 사람이 게임에서 이긴다.
모든 게임은 10^6개의 턴 내에 끝나는 것이 보장된다.

해결 방법 : 모든 게임이 길지 않은 시간 내에 끝나므로
게임 규칙을 그대로 구현하고 이기는 사람이 나올 때 까지 시뮬레이션하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JDC 2009 A번
*/

int peb[64];

int main(void) {
    int n, p, bowl, cand;
    while (1) {
        scanf("%d %d", &n, &p);
        if (n == 0) break;
        bowl = p, cand = 0;
        while (1) {
            if (bowl) {
                peb[cand]++;
                bowl--;
                if (peb[cand] == p) {
                    peb[cand] = 0;
                    printf("%d\n", cand);
                    break;
                }
            }
            else {
                bowl += peb[cand];
                peb[cand] = 0;
            }
            cand = (cand + 1) % n;
        }
    }
    return 0;
}