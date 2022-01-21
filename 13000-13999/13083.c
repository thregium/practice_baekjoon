#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 10자 이하의 숫자로 이루어진 암호가 주어진다. 이때, 각 숫자를 2번 이상 사용하지 않고 만들 수 있는
원래와 가장 먼 원래와 같은 길이의 암호를 구한다. 두 암호 사이 거리는 두 암호를 수로 보았을 때의
차의 절댓값 또는 10^길이 - 차의 절댓값 중 더 작은 값이다. 가장 먼 것이 여럿인 경우 더 작은 것을 고른다.

해결 방법 : 10!이 그렇게 크지 않기 때문에 각 숫자들을 1번만 사용하는 모든 경우에 대해
거리를 구해서 가장 먼 것을 찾으면 된다. 암호는 문자열로 받은 다음 strtoll() 함수를 통해 수로 바꿀 수 있다.
int 범위를 넘어갈 수 있음과 0으로 시작할 수 있음에 유의한다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : JAG 2015P B번
*/

char buff[16], chk[16];
long long before, after = -1, b10 = 1;

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long diff(long long x) {
    if (x < 0) return -1;
    return small(llabs(before - x), b10 - llabs(before - x));
}

void track(int c, long long n) {
    if (c == 0) {
        if (diff(n) > diff(after)) after = n;
        else if (diff(n) == diff(after) && n < after) n = after;
    }
    for (int i = 0; i < 10; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        track(c - 1, n * 10 + i);
        chk[i] = 0;
    }
}

int main(void) {
    scanf("%s", buff);
    before = strtoll(buff, NULL, 10);
    for (int i = strlen(buff); i > 0; i--) {
        buff[i - 1] = '0';
        b10 *= 10;
    }
    track(strlen(buff), 0);
    while (after < 0);
    for (int i = strlen(buff) - 1; i >= 0 && after > 0; i--, after /= 10) buff[i] = after % 10 + '0';
    printf("%s\n", buff);
    return 0;
}