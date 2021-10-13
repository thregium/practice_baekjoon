#include <stdio.h>

/*
문제 : 15개 이하의 자연수가 주어진다. 이 자연수 가운데 자신의 2배인 수가 있는 자연수의 개수를 구한다. 자연수는 100 이하다.
자연수의 끝은 0으로 주어지고, 전체의 끝은 -1로 주어진다.

해결 방법 : 0 또는 음수가 나올 때 까지 수를 입력받는다. 0이 나올 때 까지 나온 수들을 확인하며 각 수에 대해
다른 수들 가운데 자신의 2배인 수가 있는 자연수의 개수를 센다. 음수가 나온 경우 프로그램을 종료한다.

주요 알고리즘 : 브루트 포스, 구현

출처 : MidC 2003 F번
*/

int lst[32];

int main(void) {
    int n, p = 0, r, t;
    while (1) {
        while (1) {
            scanf("%d", &n);
            if (n < 0) return 0;
            else if (n == 0) break;
            else lst[p++] = n;
        }
        r = 0;
        for (int i = 0; i < p; i++) {
            t = 0;
            for (int j = 0; j < p; j++) {
                if (lst[j] == lst[i] * 2) t = 1;
            }
            r += t;
        }
        printf("%d\n", r);
        p = 0;
    }
    return 0;
}