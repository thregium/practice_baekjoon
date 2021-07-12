#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 점들이 주어지고, 미리 이 점들을 선으로 연결했다고 할 때, 나머지 선들을 연결해
모든 점들이 연결 그래프가 되도록 하는 선의 길이의 최솟값을 구한다.

해결 방법 : 크루스칼을 통해 MST를 만들되, 미리 연결된 선들은 전부 유니온 해 놓는다.
그 이후 유니온되지 않은 점들끼리 연결시켜 나온 MST가 해당 상태에서 얻을 수 있는 선의 길이의 최솟값이 된다.

주요 알고리즘 : 그래프 이론, MST

출처 : USACO 2007D S2번
*/

typedef struct line {
    double len;
    int s;
    int e;
} line;

int pos[1024][2], g[1024];
line lines[1048576];
int lp = 0;

int cmp1(const void* a, const void* b) {
    line al = *(line*)a;
    line bl = *(line*)b;
    return al.len > bl.len ? 1 : al.len == bl.len ? 0 : -1;
}

int find(int x) {
    if (g[x] == 0) return x;
    else return g[x] = find(g[x]);
}

void uni(int a, int b) {
    if (find(a) == find(b)) return;
    g[find(a)] = find(b);
}

double getdist(int a, int b) {
    return sqrt(pow(pos[a][0] - pos[b][0], 2) + pow(pos[a][1] - pos[b][1], 2));
}

int main(void) {
    int n, m, s, e;
    double r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        uni(s, e);
        //r += getdist(s, e);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            lines[lp].len = getdist(i, j);
            lines[lp].s = i;
            lines[lp].e = j;
            lp++;
        }
    }
    qsort(lines, lp, sizeof(line), cmp1);
    for (int i = 0; i < lp; i++) {
        if (find(lines[i].s) == find(lines[i].e)) continue;
        uni(lines[i].s, lines[i].e);
        r += lines[i].len;
    }
    printf("%.2f", r);
    return 0;
}