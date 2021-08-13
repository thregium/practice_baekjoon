#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 지점 사이를 움직이려고 한다. 길들은 격자 형태에 오른쪽 위로 향하는 대각선이 결합된 형태일 때,
모든 지점 사이로 순서대로 이동하기 위해 움직여야 하는 길의 최소 개수를 구한다.

해결 방법 : 만약 오른쪽 위 또는 왼쪽 아래 방향으로 향할 수 있다면 가로 또는 세로 거리가 움직여야 하는 길의 최소 개수이다.
(대각선을 탈 수 있기 때문). 하지만 왼쪽 위 또는 오른쪽 아래 방향이라면 가로 + 세로 거리를 전부 움직여야 한다.
따라서 매번 어느 경우인지 확인해본 다음 두 경우 중 하나의 거리를 추가해 나가면 된다.
어느 방향인지는 마지막 위치와의 좌표 관계를 통해 찾을 수 있다. 첫 번째에는 거리를 찾지 않음에 유의한다.

주요 알고리즘 : 수학, 케이스 워크

출처 : JOI 2014예 3번
*/

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int w, h, n, x, y, lx = 1, ly = 1, r = 0;
    scanf("%d %d %d", &w, &h, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (i > 0) {
            if ((x >= lx && y >= ly) || (x <= lx && y <= ly)) r += big(abs(lx - x), abs(ly - y));
            else r += abs(lx - x) + abs(ly - y);
        }
        lx = x, ly = y;
    }
    printf("%d", r);
    return 0;
}