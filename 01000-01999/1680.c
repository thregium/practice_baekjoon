#include <stdio.h>

/*
문제 : N(N <= 1000)개의 쓰레기 더미와 용량, 쓰레기 차의 용량이 주어질 때, 문제에 주어진 방식의 쓰레기 수거 과정에서
쓰레기차가 움직이는 거리를 구한다.

해결 방법 : 문제에 주어진대로 시뮬레이션한다. 순서에 유의한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Alberta 2012 G번
*/

int garb[1024][2];

int main(void) {
    int t, w, n, p, u, r;
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\_Alberta\\2012\\data\\G.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &w, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &garb[i][0], &garb[i][1]);
        }
        p = 0, u = 0, r = 0;
        while (p < n) {
            if (u + garb[p][1] > w) {
                u = 0;
                r += garb[p][0] * 2;
            }
            u += garb[p][1];
            if (u == w || p == n - 1) {
                u = 0;
                r += garb[p][0] * 2;
            }
            p++;
        }
        printf("%d\n", r);
    }
    return 0;
}