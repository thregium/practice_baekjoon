#include <stdio.h>

/*
문제 : 68개의 좌석을 가진 비행기가 있을 때, 이 비행기에 승객이 예매, 취소한 기록이 주어지면 마지막에
예매된 좌석의 수를 구한다. 이때, 예매나 취소시 좌석 수가 맞지 않는다면 해당 기록은 무시한다.

해결 방법 : 예매시에는 예매 후 예매된 좌석의 수가 68이 넘는지 확인하고 넘는다면 무시하고, 넘지 않으면 적용한다.
취소시에는 남은 좌석의 수가 충분한지 확인하고 충분하다면 적용, 그렇지 않다면 무시하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : NZPC 2008 D번
*/

char flight[16];

int main(void) {
    int seat, x;
    char c;
    while (1) {
        scanf("%s %d", flight, &seat);
        if (flight[0] == '#') break;
        while (1) {
            scanf(" %c %d", &c, &x);
            if (c == 'X') break;
            else if (c == 'B') {
                if (seat + x <= 68) seat += x;
            }
            else if (c == 'C') {
                if (seat >= x) seat -= x;
            }
            else return 1;
        }
        printf("%s %d\n", flight, seat);
    }
    return 0;
}