#include <stdio.h>

/*
문제 : 2^16보다 작은 두 음이 아닌 정수 X, Y가 주어질 때, 두 정수를 이진수로 교대로 만든 다음 다시 읽은 수를 십진수로 출력한다.

해결 방법 : 두 정수를 이진수로 만든 다음, 교대로 만들어 읽은 수를 계산한다.

주요 알고리즘 : 수학

출처 : NOIS 2006 P1번
*/

int sx[16], sy[16];

int main(void) {
    int x, y;
    long long r = 0;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < 16; i++) {
        sx[i] = (x >> i) & 1;
        sy[i] = (y >> i) & 1;
    }
    for (int i = 15; i >= 0; i--) {
        r <<= 1;
        r += sx[i];
        r <<= 1;
        r += sy[i];
    }
    printf("%lld", r);
    return 0;
}