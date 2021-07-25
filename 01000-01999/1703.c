#include <stdio.h>

/*
문제 : 나무의 가지 단계와 각 단계마다 가지 끝에서 뻗어나가는 가지의 수, 해당 단계에서 가지치기한 가지의 수가 주어질 때,
마지막 단계의 가지 수를 구한다.

해결 방법 : 각 단계의 가지 수는 이전 단계의 가지 수 * 가지 끝에서 뻗어나가는 가지의 수 - 가지치기한 가지 수이다.

주요 알고리즘 : 수학, 사칙연산

출처 : NZPC 2006 G번
*/

int main(void) {
    int a, sf, del;
    long long r;
    while (1) {
        scanf("%d", &a);
        if (a == 0) break;
        r = 1;
        for (int i = 0; i < a; i++) {
            scanf("%d %d", &sf, &del);
            r = r * sf - del;
        }
        printf("%lld\n", r);
    }
    return 0;
}