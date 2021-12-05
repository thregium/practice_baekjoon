#include <stdio.h>

/*
문제 : 달팽이가 우물 바닥에서 높이가 H인 우물로 올라가려 한다. 하루에 U * (100 - F * 날 수) / 100씩 올라가고,
D씩 내려온다면 우물로 올라가거나 도로 우물 바닥으로 내려오는 날을 구한다.
단, 우물의 맨 위보다 더 위 또는 바닥보다 더 아래로 내려와야 도착한 것이고, 아무리 적게 올라가도 음수만큼 올라가지는 않는다.

해결 방법 : 매일 올라가는 양과 현 위치, 날짜를 저장해가며 우물의 꼭대기 또는 바닥에 도착하는 날까지 계속 확인해나가면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : MidC 1997 B번
*/

int main(void) {
    int h, u, d, f, day;
    double updist, pos;
    while (1) {
        scanf("%d %d %d %d", &h, &u, &d, &f);
        if (h == 0) break;
        pos = 0;
        day = 1;
        updist = u;
        while (1) {
            pos += updist;
            if (pos > h) {
                printf("success on day %d\n", day);
                break;
            }
            pos -= d;
            if (pos < 0) {
                printf("failure on day %d\n", day);
                break;
            }
            day++;
            updist -= (double)u * f / 100.0;
            if (updist < 0) updist = 0;
        }
    }
    return 0;
}