#include <stdio.h>

/*
문제 : N(N <= 500)명의 순위가 주어지고 순위가 바뀐 M(M <= 25000)개의 쌍이 주어진다. 이때, 바뀐 순위를 구할 수 있는지
확인하고, 가능하다면 바뀐 순위를 구한다.

해결 방법 : 모든 순위가 다른 쌍에 대해 순위가 높은 쪽에서 낮은 쪽으로 간선을 긋는다. 정점에 비해 간선이 많고 쌍들끼리 직접
바꾸는 일이 생기기 때문에 인접 행렬을 이용한다. 순위가 바뀐 쌍은 간선의 방향을 바꾸면 된다.
이제 위상 정렬을 통해 나온 결과가 바뀐 순위이다. 중간에 사이클이 생긴 경우에는 순위를 구할 수 없는 것이다.

주요 알고리즘 : 그래프 이론, 위상 정렬

출처 : NWERC 2010 E번
*/

int comp[512][512], orank[512], nrank[512], ins[512];

int main(void) {
    int t, n, m, a, b, sel, r;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2010\\testdata\\E.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2010\\testdata\\E_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &orank[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                comp[orank[i]][orank[j]] = 1;
                ins[orank[j]]++;
            }
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if (comp[a][b]) {
                comp[a][b] = 0;
                comp[b][a] = 1;
                ins[a]++, ins[b]--;
            }
            else {
                comp[a][b] = 1;
                comp[b][a] = 0;
                ins[a]--, ins[b]++;
            }
        }

        r = 1;
        for (int i = 1; i <= n; i++) {
            sel = 0;
            for (int j = 1; j <= n; j++) {
                if (ins[j] == 0) {
                    sel = j;
                    break;
                }
            }
            if (!sel) {
                printf("IMPOSSIBLE\n");
                r = 0;
                break;
            }
            ins[sel]--;
            nrank[i] = sel;
            for (int j = 1; j <= n; j++) ins[j] -= comp[sel][j];
        }
        if (r) {
            for (int i = 1; i <= n; i++) printf("%d ", nrank[i]);
            printf("\n");
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) comp[i][j] = 0;
            ins[i] = 0;
        }
    }
    return 0;
}
