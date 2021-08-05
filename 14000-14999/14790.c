#include <stdio.h>

/*
문제 : N(N <= 1000) 이하의 수 가운데 가장 큰 자릿수가 단조 증가하는 수를 구한다.

해결 방법 : N부터 시작해서 수를 줄여가며 조건에 맞는 수가 나오면 그 수를 출력하고 탐색을 종료한다.
N이 4자리인 경우에는 그러한 수가 없고, 3자리인 경우에는 십의 자리 수가 백의 자리 수 이상이며 일의 자리 수가 십의 자리 수 이상인
경우이며, 2자리인 경우에는 일의 자리 수가 십의 자리 수 이상이면 된다. 1자리인 경우에는 항상 조건을 만족한다.

주요 알고리즘 : 수학, 브루트 포스

출처 : GCJ 2017Q B1번
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = n; i > 0; i--) {
            if (i >= 100) {
                if (i / 100 != 0 && i / 100 <= i / 10 % 10 && i / 10 % 10 <= i % 10) {
                    printf("Case #%d: %d\n", tt, i);
                    break;
                }
            }
            else if (i >= 10) {
                if (i / 10 != 0 && i / 10 <= i % 10) {
                    printf("Case #%d: %d\n", tt, i);
                    break;
                }
            }
            else {
                printf("Case #%d: %d\n", tt, i);
                break;
            }
        }
    }
    return 0;
}