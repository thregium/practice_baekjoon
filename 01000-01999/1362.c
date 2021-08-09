#include <stdio.h>

/*
문제 : 펫의 처음 체중과 적정 체중에서 펫에게 먹이를 주거나 운동을 시킨 기록이 주어진다. 먹이를 주면 준 양 만큼 체중이 늘고
운동을 시키면 그만큼 체중이 준다. 마지막에 체중이 적정 체중의 1 / 2보다 크고 2배보다 작다면 펫은 행복한 상태이고,
그 외에는 슬픈 상태라고 한다. 또한, 중간에 펫의 체중이 0 이하가 되면 펫은 죽는다. 마지막에 펫의 상태를 구한다.

해결 방법 : 펫의 체중을 따라가며 체중을 줄이거나 늘린다. 중간에 체중이 0 이하가 되면 죽은 상태로 바꾼다.
마지막에 죽은 상태가 아니라면 체중을 확인해서 행복한 상태인지 확인하면 된다. 이때, 1 / 2 처리에 주의한다.

주요 알고리즘 : 구현

출처 : NZPC 2006 D번
*/

int main(void) {
    int o, w, x, dead;
    char c;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &o, &w);
        if (o == 0) break;
        dead = 0;
        while (1) {
            scanf(" %c %d", &c, &x);
            if (c == 'E') w -= x;
            else if (c == 'F') w += x;
            else break;
            if (w <= 0) dead = 1;
        }
        if (dead) printf("%d RIP\n", tt);
        else if (w * 2 <= o || w >= o * 2) printf("%d :-(\n", tt);
        else printf("%d :-)\n", tt);
    }
    return 0;
}