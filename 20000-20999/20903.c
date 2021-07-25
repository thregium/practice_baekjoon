#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기 보드에서 600턴 내로 말 2개를 움직여 상대 말을 잡는다.
각 말들은 상하좌우로 움직이거나 움직이지 않을 수 있고, 상대 말도 같은 방식으로 이동한다. 각 말들은 겹칠 수 있으며,
상대 말과 겹치면 상대 말을 잡은 것이다.

해결 방법 : 한 말은 X좌표를 기준으로 상대 말과 가까워지는 방향으로 이동하고
다른 한 말은 Y좌표를 기준으로 상대 말과 가까워지면 상대 말은 구석으로 몰리게 되므로 상대 말을 항상 N턴 내로 잡을 수 있다.

주요 알고리즘 : 구성적, 게임 이론

출처 : GCPC 2020 C번
*/

int main(void) {
    int n, px1, py1, px2, py2, ox, oy;
    scanf("%d", &n);
    scanf("%d %d %d %d", &px1, &py1, &px2, &py2);
    while (1) {
        scanf("%d %d", &ox, &oy);
        if (ox == 0 && oy == 0) return 0;
        if (px1 < ox) px1++;
        else if (px1 > ox) px1--;
        else if (py1 < oy) py1++;
        else if (py1 > oy) py1--;

        if (py2 < oy) py2++;
        else if (py2 > oy) py2--;
        else if (px2 < ox) px2++;
        else if (px2 > ox) px2--;

        printf("%d %d %d %d\n", px1, py1, px2, py2);
        fflush(stdout);
    }
    return 0;
}