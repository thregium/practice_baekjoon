#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
문제 : 공간 상에 N(N <= 100)개의 구가 있다. 이때, 모든 구들을 연결하기 위해 필요한 최소 거리를 구한다.
각 구들을 연결하는 선들은 중간에 만나더라도 만나는 것으로 계산하지 않는다. 또한, 구의 일부가 겹치는 경우
연결하지 않아도 연결된 것으로 생각한다.

해결 방법 : 우선 각 구들을 잇는 거리들을 전부 구한다. 이는 피타고라스 정리를 통해 거리를 구한 다음,
두 구의 반지름을 빼면 된다. 그 다음 거리들을 오름차순으로 정렬하고 MST를 구하면 된다.
이때, 비용이 음수인 경우 비용에 더하지 않음에 유의한다.

주요 알고리즘 : 그래프 이론, MST, 기하학

출처 : JDC 2003 D번
*/

double cell[128][4], corr[5120][3];
int g[128];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double getdist(int a, int b) {
    return sqrt(pow(cell[a][0] - cell[b][0], 2) + pow(cell[a][1] - cell[b][1], 2) +
        pow(cell[a][2] - cell[b][2], 2));
}

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, cp;
    double r;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2003\\D2.txt", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf %lf %lf", &cell[i][0], &cell[i][1], &cell[i][2], &cell[i][3]);
        }
        cp = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                corr[cp][0] = getdist(i, j) - cell[i][3] - cell[j][3];
                corr[cp][1] = i;
                corr[cp++][2] = j;
            }
        }
        qsort(corr, cp, sizeof(double) * 3, cmp1);
        r = 0.0;
        for (int i = 0; i < cp; i++) {
            if (find(corr[i][1]) != find(corr[i][2])) {
                uni(corr[i][1], corr[i][2]);
                if (corr[i][0] > 0) r += corr[i][0];
            }
        }
        printf("%.3f\n", r);
        for (int i = 1; i <= n; i++) g[i] = 0;
    }
    return 0;
}