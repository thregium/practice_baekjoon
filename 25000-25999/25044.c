#include <stdio.h>

/*
문제 : 15시, 18시, 21시에 켜지고 세 번째 켜질 때 마다 K(K < 60)분동안 지연되는 에어컨이 있다.
N(N <= 1000)일째의 켜지는 시각을 모두 출력한다.

해결 방법 : 시간의 흐름을 시뮬레이션하면서 범위 안에 에어컨이 켜진 횟수를 세서 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : DGIST 2022 A번
*/

int res[16];

int inrange(int tm, int n) {
    if (tm < n * 1440 || (n + 1) * 1440 <= tm) return 0;
    else return 1;
}

int main(void) {
    int n, k, tm = 0, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; tm < (n + 1) * 1440; i++) {
        if (i == 0) tm += 15 * 60;
        else tm += 18 * 60 + k;
        if (inrange(tm, n)) res[r++] = tm % 1440;
        tm += 3 * 60;
        if (inrange(tm, n)) res[r++] = tm % 1440;
        tm += 3 * 60;
        if (inrange(tm, n)) res[r++] = tm % 1440;
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%02d:%02d\n", res[i] / 60, res[i] % 60);
    }
    return 0;
}