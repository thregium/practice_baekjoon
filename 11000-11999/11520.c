#include <stdio.h>

/*
문제 : 파이의 Q번째 자리는 D(D <= 9)이고, R번째 자리는 5라고 한다.
N(N <= 10000)개의 줄에 P(P <= 10^6)와 D가 주어질 때, 각 줄마다 Q번째 자리와 R번째 자리를 구한다.

해결 방법 : D와 5를 각 줄마다 출력하면 된다. &_&

주요 알고리즘 : 구현

출처 : SCUSA 2015 H번
*/

int main(void) {
    int t, p, d;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &p, &d);
        printf("%d 5\n", d);
    }
    return 0;
}