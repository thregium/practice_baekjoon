#include <stdio.h>

/*
문제 : N(N <= 20)개의 변수와 M(M <= 100)개의 절로 이루어진 2-SAT 문제의 해가 존재하는 지 확인하고,
존재하는 경우 그 해 중 하나를 출력한다.

해결 방법 : 변수와 절의 개수가 적기 때문에 모든 경우를 시도해보면서 해가 존재하는 지 확인하고
해가 있다면 그때의 해를 출력하면 된다.

주요 알고리즘 : 브루트 포스, 비트마스킹
*/

int x[32], c[128][2], res[32];

int main(void) {
    int n, m, r = 0, t, c1, c2;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &c[i][0], &c[i][1]);
    }
    for (int i = 0; i < (1 << n); i++) {
        t = 1;
        for (int j = 0; j < m; j++) {
            if (c[j][0] < 0) c1 = (!((i >> (-c[j][0] - 1)) & 1));
            else c1 = ((i >> (c[j][0] - 1)) & 1);
            if (c[j][1] < 0) c2 = (!((i >> (-c[j][1] - 1)) & 1));
            else c2 = ((i >> (c[j][1] - 1)) & 1);
            if (!(c1 || c2)) {
                t = 0;
                break;
            }
        }
        if (t) {
            r = 1;
            for (int j = 0; j < n; j++) res[j] = ((i >> j) & 1);
            break;
        }
    }
    if (!r) printf("0");
    else {
        printf("1\n");
        for (int i = 0; i < n; i++) printf("%d ", res[i]);
    }
    return 0;
}