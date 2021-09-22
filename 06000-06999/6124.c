#include <stdio.h>

/*
문제 : NR * NC(NR, NC <= 100) 크기의 격자에서 3 * 3 크기 영역의 합이 가장 큰 곳 가운데 행 -> 열 번호가 가장 작은 곳을 구한다.
해당하는 합과 왼쪽 위 칸의 행, 열 번호를 출력한다.

해결 방법 : 각 값들을 입력받은 다음, 모든 3 * 3 크기의 영역을 살핀다. 행 -> 열이 증가하는 순으로 탐색하고,
최댓값보다 합이 큰 곳을 발견하면 해당하는 행, 열 번호를 갱신하고, 최댓값도 갱신해준다. 마지막의 최댓값, 행, 열 번호를 출력한다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2009O B3번
*/

int grass[128][128];

int main(void) {
    int nr, nc, s, best = 0, bx = -1, by = -1;
    scanf("%d %d", &nr, &nc);
    for (int i = 1; i <= nr; i++) {
        for (int j = 1; j <= nc; j++) {
            scanf("%d", &grass[i][j]);
        }
    }
    for (int i = 1; i < nr - 1; i++) {
        for (int j = 1; j < nc - 1; j++) {
            s = 0;
            for (int ii = 0; ii < 3; ii++) {
                for (int jj = 0; jj < 3; jj++) s += grass[i + ii][j + jj];
            }
            if (s > best) {
                best = s;
                bx = i;
                by = j;
            }
        }
    }
    if (bx < 0) return 1;
    printf("%d\n%d %d", best, bx, by);
    return 0;
}