#include <stdio.h>

/*
문제 : 구성하는 숫자 중 L이 없는 N(N <= 10^6)번째 자연수를 찾는다.

해결 방법 : 1부터 차례로 올라가며 각 수들에 L이 있는지 확인하고 없다면 그러한 것이 N개째가 되었을 때의 값을 출력하면 된다.

주요 알고리즘 : 브루트 포스, 수학
*/

int main(void) {
    int n, l, r = 0, t;
    scanf("%d %d", &n, &l);
    for (int i = 1;; i++) {
        t = 1;
        for (int j = i; j; j /= 10) {
            if (j % 10 == l) t = 0;
        }
        if (t) {
            r++;
            if (r == n) {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}