#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 L(L <= 32768)mm인 줄에 C(C <= 512)개의 보석이 매달려 있다. 각 보석은 P_i 위치에 매달려 있고,
S_i(S_i <= 25)만큼의 길이인 실 끝에 매달려있다. 줄을 위치 N에 매달았을 때,
각 보석이 매단 위치에서 얼마나 밑에 있는지 각각 구한다.

해결 방법 : 각 실이 매달린 위치는 N과 P_i의 거리의 절댓값이다. 따라서, 보석이 매달린 위치는 그 값에 S_i를 더하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : USACO 2011M B1번
*/

int main(void) {
    int l, c, n, s, p;
    scanf("%d %d %d", &l, &c, &n);
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &s, &p);
        printf("%d\n", abs(p - n) + s);
    }
    return 0;
}