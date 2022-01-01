#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)개의 음이 아닌 정수(<= 10^9)가 주어질 때, 가장 작은 수들 중 가장 앞의 위치를 구한다.

해결 방법 : 최솟값을 구하면서 최솟값이 바뀔 때 마다 위치를 저장해둔 다음, 저장된 위치를 출력하면 된다.

주요 알고리즘 : 구현

출처 : Bergen 2018 L번
*/

int main(void) {
    int n, x, day = -1, best = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x < best) {
            best = x;
            day = i;
        }
    }
    if (day < 0) return 1;
    printf("%d", day);
    return 0;
}