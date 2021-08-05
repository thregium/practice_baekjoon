#include <stdio.h>

/*
문제 : N(N <= 1000)명이 퐁당퐁당 게임을 할 때, T(T <= 10^7)번째에 들어야 할 팔의 수를 구한다. (규칙 생략)

해결 방법 : T가 크지 않으므로 규칙에 맞게 팔의 수를 매번 확인한 다음 T번째의 팔의 수를 찾으면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 한양대 6회 BD번
*/

int main(void) {
    int n, t, m = 0, a = 1;
    scanf("%d %d", &n, &t);
    for (int i = 1; i < t; i++) {
        if (m) a--;
        else a++;
        if (a == 1) m = 0;
        else if (a == n * 2) m = 1;
    }
    printf("%d", a);
    return 0;
}