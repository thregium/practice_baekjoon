#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : 벽장 문의 개수와 두 열려있는 벽장 문의 번호가 주어진다. 사용할 벽장들이 순서대로 주어지면
해당 순서로 벽장들을 사용하며 이동하는 문의 거리의 최솟값을 구한다.

해결 방법 : 비트마스킹을 통해 2^M(벽장 사용 수)가지 경우를 확인해본다. 각 비트가 1인 경우는 오른쪽 문을 움직이고,
0인 경우는 왼쪽 문을 움직인다. 움직인 거리는 현재 위치에서 사용할 위치까지의 거리와 같다.
이를 더한 값이 가장 작은 것을 찾아 그 값을 출력하면 된다.

주요 알고리즘 : 브루트 포스, 비트마스킹

출처 : 정올 1997 고3번
*/

int user[32];

int main(void) {
    int n, a, b, m, r = INF, t = 0, x, y;
    scanf("%d%d %d%d", &n, &a, &b, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &user[i]);
    }
    for (int i = 0; i < (1 << m); i++) {
        x = a, y = b, t = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                t += abs(y - user[j]);
                y = user[j];
            }
            else {
                t += abs(x - user[j]);
                x = user[j];
            }
        }
        if (t < r) r = t;
    }
    printf("%d", r);
    return 0;
}