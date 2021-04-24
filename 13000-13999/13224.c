#include <stdio.h>
#include <string.h>

/*
문제 : 3개의 컵 중 하나에 공이 있을 때, 각 컵들을 바꾼 순서가 주어진다면 마지막에 공이 있는 위치를 출력한다.

해결 방법 : 컵의 위치 변화를 시뮬레이션 한다. 컵 대신 공의 위치 변화를 시뮬레이션 하는 것이 더 쉬울 수도 있다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : AIPO 2015P 4번
*/

char c[64];

int main(void) {
    int l, p = 1;
    scanf("%s", c);
    l = strlen(c);
    for (int i = 0; i < l; i++) {
        if (c[i] == 'A') {
            if (p == 1) p = 2;
            else if (p == 2) p = 1;
        }
        if (c[i] == 'B') {
            if (p == 2) p = 3;
            else if (p == 3) p = 2;
        }
        if (c[i] == 'C') {
            if (p == 1) p = 3;
            else if (p == 3) p = 1;
        }
    }
    printf("%d", p);
    return 0;
}