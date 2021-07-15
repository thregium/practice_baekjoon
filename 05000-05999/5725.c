#include <stdio.h>

/*
문제 : 카레이스에서 각 자동차들의 현재 순위와 순위 변화가 주어질 때, 이전 순위를 만드는 것이 가능한지 구하고
가능하다면 이전 순위표를 출력한다.

해결 방법 : 각 자동차의 이전 순위는 현재 순위에서 순위 변화량을 뺀 것과 같다. 이 값이 순위 범위를 벗어나거나
이미 해당 순위에 다른 차가 있다면 만드는 것이 불가능하고 벗어나지 않는다면 가능하다.

주요 알고리즘 : 구현

출처 : Latin 2008 G번
*/

int rank[1024];

int main(void) {
    int n, c, p, r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2008\\testset_2008\\pole.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2008\\testset_2008\\pole.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 1;
        for (int i = 0; i < n; i++) rank[i] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &c, &p);
            if (i + p >= n || i + p < 0 || rank[i + p]) {
                r = 0;
                continue;
            }
            rank[i + p] = c;
        }
        if (!r) {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", rank[i]);
        }
        printf("\n");
    }
    return 0;
}