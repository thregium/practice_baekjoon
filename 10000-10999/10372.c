#include <stdio.h>

/*
문제 : 7-세그먼트 디스플레이로 이루어진 시계에서 N(1 <= N <= 30)개의 세그먼트만 켜진 시각 중 하나를 출력한다.
없는 경우 Impossible을 출력한다.

해결 방법 : 각 가능한 시간과 분에 대해 켜진 세그먼트의 수가 N과 같은지 구한다.
같아지는 시점에 그 때의 시각을 출력하고 프로그램을 종료하고, 그러한 때가 없다면 Impossible을 출력한다.

주요 알고리즘 : 브루트 포스, 구성적

출처 : NEERC 2014N A번
*/

int dig[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++) {
            if (dig[i / 10] + dig[i % 10] + dig[j / 10] + dig[j % 10] == n) {
                printf("%02d:%02d", i, j);
                return 0;
            }
        }
    }
    printf("Impossible");
    return 0;
}