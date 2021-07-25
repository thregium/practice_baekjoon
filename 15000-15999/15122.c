#include <stdio.h>

/*
문제 : 999999 이하의 0이 없는 수 N이 주어질 때, 0이 없는 다음 수를 구한다.

해결 방법 : N + 1부터 차례로 자릿수 중 0이 있는 수가 없는지 확인하다 0이 없는 수가 나오면 그 수를 출력하고 프로그램을 종료한다.
어떤 N에서든 최대 111112번(999999 -> 1111111)만 돌려보면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : PacNW 2017 Z번
*/

int main(void) {
    int n, t;
    scanf("%d", &n);
    for (int i = n  + 1;; i++) {
        t = 1;
        for (int x = i; x; x /= 10) {
            if (x % 10 == 0) {
                t = 0;
                break;
            }
        }
        if (!t) continue;
        printf("%d", i);
        break;
    }
    return 0;
}