#include <stdio.h>
#include <stdlib.h>

int g[103000], rd[1048576][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int a) {
    if (g[a] == 0) return a;
    else return g[a] = find(g[a]);
}

void uni(int a, int b) {
    if (find(a) == find(b)) return;
    else g[find(a)] = find(b);
}

int main(void) {
    int n, m, r = 0, l = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &rd[i][1], &rd[i][2], &rd[i][0]);
    }
    qsort(rd, m, sizeof(int) * 3, cmp1);
    for (int i = 0; i < m; i++) {
        if (find(rd[i][1]) != find(rd[i][2])) {
            r += rd[i][0];
            l = rd[i][0];
            uni(rd[i][1], rd[i][2]);
        }
    }
    printf("%d", r - l);
    return 0;
}