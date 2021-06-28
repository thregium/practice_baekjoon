#include <stdio.h>

/*
문제 : 두 카드가 매 턴마다 서로 공격을 주고받는다. 생명력이 0(또는 그 이하)이 된 카드는 사라진다고 할 때, 남게 되는 카드를 구한다.
두 카드의 생명력과 공격력은 10만 이하의 양수이다.

해결 방법 : 생명력과 공격력의 한도가 크지 않으므로 매 턴마다 두 카드의 상태를 시뮬레이션으로 확인한다.
두 카드 중 하나라도 생명력이 0 이하가 되면 시뮬레이션을 종료하고 생명력이 양수인 카드를 승자로 한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 전북대 2016 B번
*/

int main(void) {
    int aa, al, ba, bl;
    scanf("%d %d%d %d", &aa, &al, &ba, &bl);
    while (al > 0 && bl > 0) {
        al -= ba;
        bl -= aa;
    }
    if (al <= 0 && bl <= 0) printf("DRAW");
    else if (al <= 0) printf("PLAYER B");
    else printf("PLAYER A");
    return 0;
}