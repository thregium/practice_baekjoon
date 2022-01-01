#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 체스판에서 직사각형을 뒤집는 연산을 최소로 사용하여 모든 칸의 색을 같도록 하는 방법을 구한다.

해결 방법 : 짝수 번째 행과, 짝수 번째 열을 뒤집으면 된다.

주요 알고리즘 : 애드 혹, 구성적

출처 : NEERC 2014 A번
*/

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", (n >> 1) + (m >> 1));
    for (int i = 2; i <= n; i += 2) {
        printf("%d %d %d %d\n", i, 1, i, m);
    }
    for (int i = 2; i <= m; i += 2) {
        printf("%d %d %d %d\n", 1, i, n, i);
    }
    return 0;
}