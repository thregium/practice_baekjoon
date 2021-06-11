#include <stdio.h>

/*
문제 : 두 주자가 한 바퀴를 도는데 걸리는 시간 X, Y(X < Y // X, Y <= 10000)가 주어질 때, X가 Y를 몇 번째 바퀴에서 추월하는지 구한다.
단, 바퀴는 X 기준이다.

해결 방법 : 2번째 바퀴부터 계속 돌려보며 X가 Y를 추월하는(X * i가 Y * (i - 1)보다 작아지는) 시점이 언제인지 확인한다.

주요 알고리즘 : 브루트 포스

출처 : Brazil 2014 A번
*/

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 2;; i++) {
        if (x * i <= y * (i - 1)) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}