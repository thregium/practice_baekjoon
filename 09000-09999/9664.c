#include <stdio.h>

/*
문제 : x - x / N(N <= 15)이 O(O <= 100)가 되는 x의 범위를 구한다.

해결 방법 : O의 범위가 작기 때문에 200 이상까지 모두 값을 확인해서 O가 되는 x를 전부 확인하면 된다.

주요 알고리즘 : 브루트 포스

출처 : COCI 13/14#4 1번
*/

int main(void) {
    int n, o, l = 1000, h = 0;
    scanf("%d %d", &n, &o);
    for (int i = 1; i <= 300; i++) {
        if (i - i / n != o) continue;
        if (i > h) h = i;
        if (i < l) l = i;
    }
    printf("%d %d", l, h);
    return 0;
}