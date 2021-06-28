#include <stdio.h>

/*
문제 : N * N 크기의 색종이를 접어 접힌 곳 위에 접은 두 수의 합을 적는 것을 반복해 수가 하나만 남을 때의 수를 구한다.

해결 방법 : 약간 생각해보면 모든 칸은 한번씩만 접히기 때문에 하나만 남을 때의 수는 모든 수의 합과 같음을 알 수 있다.

주요 알고리즘 : 구현?

출처 : 충남대 2회 B번
*/

int main(void) {
    int n, x;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &x);
        r += x;
    }
    printf("%lld", r);
    return 0;
}