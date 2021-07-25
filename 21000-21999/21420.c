#include <stdio.h>

/*
문제 : N(N <= 100)개의 동전이 있다. 모든 동전을 같은 면을 보도록 하려면 뒤집어야 하는 횟수의 최솟값을 구한다.

해결 방법 : 같은 방향을 보는 동전을 전부 뒤집으면 된다. 앞면과 뒷면 중 더 적게 뒤집는 것을 고른다.

주요 알고리즘 : 그리디 알고리즘

출처 : ROI 2006H B번
*/

int main(void) {
    int n, x, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        c += x;
    }
    printf("%d", c > n - c ? n - c : c);
    return 0;
}