#include <stdio.h>

/*
문제 : N(N <= 100)개의 장난감 또는 부품과, M(M <= 100)개의 장난감 사이 조립 관계(X를 만들기 위해
Y가 K개 필요함)가 주어진다. 이때, 조립 관계가 일관되고 모두 최종 장난감을 만들기 위해 필요하다면,
장난감에 각 기초 부품이 몇 개 필요한 지 구한다. 각 부품은 많아야 2^31 - 1개 필요하다.

해결 방법 : 각 부품마다 필요한 부품 개수를 위상 정렬을 통해 구해 나가면 된다.
기초 부품은 각각 1개씩 필요하고, 이후로는 K * 필요한 부품에 필요한 각 부품 수를 더해나간다.
최종 장난감에 대해 각 부품 수를 알면 기초 부품의 부품 수를 각각 확인해 출력한다.

주요 알고리즘 : 그래프 이론, 위상 정렬

출처 : 정올 2000 중1번
*/

int ed[128][128][2], ecnt[128], ins[128], vis[128], part[128][128], base[128];

int main(void) {
    int n, m, x, y, k, ee = -1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &k);
        ed[y][ecnt[y]][0] = x;
        ed[y][ecnt[y]++][1] = k;
        ins[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (ins[i] == 0) {
            part[i][i] = 1;
            base[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 1; j <= n; j++) {
            if (ins[j] == 0 && !vis[j]) {
                x = j;
                break;
            }
        }
        if (x < 0) return 1;
        for (int j = 0; j < ecnt[x]; j++) {
            for (int k = 1; k <= n; k++) {
                part[ed[x][j][0]][k] += part[x][k] * ed[x][j][1];
            }
            ins[ed[x][j][0]]--;
        }
        vis[x] = 1;
        if (i == n - 1) ee = x;
    }
    for (int i = 1; i <= n; i++) {
        if (base[i]) printf("%d %d\n", i, part[ee][i]);
    }
    return 0;
}