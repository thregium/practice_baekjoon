#include <stdio.h>

/*
문제 : N과 M이 주어질 때, N * M 크기의 체스판 모양을 출력한다.

해결 방법 : 문제에서 설명한대로 구현한다.

주요 알고리즘 : 구현

출처 : AIPO 2016F 1번
*/

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%c", ((i + j) & 1) ? '.' : '*'); //행 + 열 번호가 짝수인 경우 *, 홀수인 경우 .
        printf("\n");
    }
    return 0;
}