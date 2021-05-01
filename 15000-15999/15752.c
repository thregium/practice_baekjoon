#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 수직선상에 N(N <= 100)개의 점이 있다. 이때, 각 점에서는 가장 가까운 점(여러 개인 경우 그 중 가장 왼쪽 점)으로 이동 가능하다고 할 때,
모든 점으로 이동하기 위해 필요한 출발점의 최소 개수를 구한다.

해결 방법 : 점들을 정렬한 다음 모든 점에 대해서 이동 가능한 점들을 각각 기록해두고 각 점들에 대해 해당 점으로 도착하게 되는 점들의 수도 기록해둔다.
그러면 모든 점으로 이동하기 위해 필요한 출발점은 다른 점에서 도착할 수 없는 점들과 점 2개가 서로 맞물려 있지만 다른 점들에선 도착할 수 없는 점들을
출발점으로 해야 한다. 앞의 것은 도착점의 수가 0인 점들이고, 뒤의 것은 도착점, 이동한 점의 도착점이 모두 1이고, 2번 이동시 원래 위치로 돌아오는 점들의 수 / 2이다.

주요 알고리즘 : 그래프 이론

출처 : USACO 2018F B2번
*/

int a[128], g[128], in[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hoofball.in", "r");
        fo = fopen("hoofball.out", "w");
    }
    int n, cnt = 0, cnt2 = 0;
    scanf("%d", &n);
    if (n == 1) {
        printf("%d", 1);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i == 0) g[i] = 1;
        else if (i == n - 1) g[i] = n - 2;
        else if (abs(a[i] - a[i - 1]) > abs(a[i] - a[i + 1])) g[i] = i + 1;
        else g[i] = i - 1;
        in[g[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (!in[i]) cnt++;
        else if (in[i] == 1 && in[g[i]] == 1 && g[g[i]] == i) cnt2++;
    }
    if (cnt2 & 1) return 1;
    printf("%d", cnt + (cnt2 >> 1));
    return 0;
}