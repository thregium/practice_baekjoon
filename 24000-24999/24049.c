#include <stdio.h>

/*
문제 : N * M(N, M <= 1000) 크기의 칸에 꽃들을 심는다. 바깥쪽 맨 왼쪽과 맨 위쪽에 심은 꽃들의 색이 주어지면
가장 오른쪽 아래에 심는 꽃의 색을 구한다. 각 꽃의 왼쪽과 위쪽 색이 같다면 노란색, 다르다면 빨간색
꽃을 심어나간다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : pjshwa
*/

int flower[1024][1024];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &flower[i][0]);
    }
    for (int j = 1; j <= m; j++) {
        scanf("%d", &flower[0][j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            flower[i][j] = (flower[i - 1][j] != flower[i][j - 1]);
        }
    }
    printf("%d", flower[n][m]);
    return 0;
}