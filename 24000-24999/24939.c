#include <stdio.h>

/*
문제 : N * M(N, M <= 10^9) 크기의 공간에서 보물이 한 곳에 있다. Q(Q <= 100000)개의 질문 결과
보물이 있을 수 있는 후보 지역의 개수를 구한다. 각 질문은 보물의 방향을 묻는 것이고,
방향은 9개로 나뉜다. 대답은 항상 일관적이다.

해결 방법 : 처음에는 가능한 좌표의 범위를 전체 구역으로 하고,
각 방향에 따라서 가능한 좌표의 범위를 좁혀가면 된다. 경우의 수가 많으므로 유의한다.

주요 알고리즘 : 기하학, 케이스 워크

출처 : 설곽 2022Q C번
*/

int main(void) {
    int n, m, q, x, y, d;
    long long xl, yl, xh, yh;
    scanf("%d %d", &n, &m);
    scanf("%d", &q);
    xl = 1, yl = 1, xh = n, yh = m;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &x, &y, &d);
        if (d == 2 || d == 6 || d == 8) {
            if (xh >= x) xh = x - 1;
        }
        else if (d == 1 || d == 5 || d == 7) {
            if (xl <= x) xl = x + 1;
        }
        else {
            if (xl < x) xl = x;
            if (xh > x) xh = x;
        }
        if (d == 3 || d == 7 || d == 8) {
            if (yh >= y) yh = y - 1;
        }
        else if (d == 4 || d == 5 || d == 6) {
            if (yl <= y) yl = y + 1;
        }
        else {
            if (yl < y) yl = y;
            if (yh > y) yh = y;
        }
    }

    printf("%lld", (xh - xl + 1) * (yh - yl + 1));
    return 0;
}