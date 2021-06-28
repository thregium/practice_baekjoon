#include <stdio.h>

/*
문제 : 개 2마리가 있는데, 이들은 각각 A분동안 사납다가 B분동안 얌전하고, C분동안 사납다가 D분동안 얌전하다고 한다.
3명의 배달부가 집에 방문하는 시각이 주어질 때, 사나운 상태인 개의 수를 각각 출력한다.

해결 방법 : 방문 시각을 (A + B)로 나눈 나머지에 따라 사나운지 여부를 개마다 확인한 후 그 개수를 각각 세면 된다.

주요 알고리즘 : 수학

출처 : COCI 07/08#4 1번
*/

int main(void) {
    int a, b, c, d, p, m, n, x, y, pn = -1, mn = -1, nn = -1;
    scanf("%d %d %d %d%d %d %d", &a, &b, &c, &d, &p, &m, &n);
    for (int i = 1; i < 1000; i++) {
        if ((i - 1) % (a + b) < a) x = 1;
        else x = 0;
        if ((i - 1) % (c + d) < c) y = 1;
        else y = 0;
        if (i == p) pn = x + y;
        if (i == m) mn = x + y;
        if (i == n) nn = x + y;
    }
    printf("%d\n%d\n%d", pn, mn, nn);
    return 0;
}