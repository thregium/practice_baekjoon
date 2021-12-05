#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define INF 1012345678
#define SZ 131072
using namespace std;

/*
문제 : 수직선상에 N(N <= 100000)개의 정수(|| <= 10^8) 위치의 점이 주어진다. 이때, 각 점에 대해 화면을 최소 몇 회 움직여야
해당 점을 중심으로 보이게 할 수 있는지 구한다. 처음에 화면은 [-1, 1] 범위를 보여준다.
화면에는 우선순위 순으로 상위 K(1 <= K <= 4)개의 점을 보여준다.
화면을 움직일 때에는 범위를 2배로 하거나, 절반으로 하거나, 현재 화면에 보이는 점을 중심으로 움직이는 행동이 가능하다.

해결 방법 : 화면 크기의 범위가 많지 않기 때문에 BFS를 통해 해결 가능하다. 각 중심으로 둔 점과 범위를 변수로 두면 된다.
이때, 화면에 보이는 점을 보이는 것이 문제인데, 이것은 세그먼트 트리를 통해 해결 가능하다.
미리 좌표 압축을 해준 후, 세그먼트 트리에 각 점 범위에 대해 우선순위 순으로 상위 4개의 점을 저장한다.
화면의 점을 찾을 때에는 이분 탐색을 통해 들어있는 점의 범위를 구하고, 이를 세그먼트 트리에서 확인하여
상위 K개의 점을 찾으면 된다.

각 점이 중심에 있을 뿐 만 아니라 보여야 함에 유의한다.

주요 알고리즘 : 그래프 이론, BFS, 세그먼트 트리 등

출처 : SEUSA 2020 O번 // MidC 2020 I번 // PacNW 2020 I번 // MidAtl 2020 H번 // SCUSA 2020 O번
*/

typedef struct stree {
    int s;
    int e;
    int lrg[4];
    struct stree* l;
    struct stree* r;
} stree;

typedef struct best4 {
    int a[4];
} best4;

char vis[103000][32];
int dist[103000][32], pts[103000][2], best[103000], seg[SZ * 2][4], rng[32];
long long cnode = 0, calc = 0;
queue<pair<int, int>> q;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}
int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return pts[ai][1] < pts[bi][1] ? 1 : pts[ai][1] == pts[bi][1] ? 0 : -1;
}

int lb(int n, int x) {
    int l = 0, h = n, m;
    while (l < h) {
        m = (l + h) >> 1;
        if (pts[m][0] >= x) h = m;
        else l = m + 1;
    }
    return l;
}
int ub(int n, int x) {
    int l = 0, h = n, m;
    while (l < h) {
        m = (l + h + 1) >> 1;
        if (pts[m][0] <= x) l = m;
        else h = m - 1;
    }
    return l;
}

void seg_init(void) {
    int tmp[8];
    for (int i = SZ - 1; i >= 1; i--) {
        for (int j = 0; j < 4; j++) tmp[j] = seg[i << 1][j];
        for (int j = 0; j < 4; j++) tmp[j + 4] = seg[(i << 1) + 1][j];
        qsort(tmp, 8, sizeof(int), cmp2);
        for (int j = 0; j < 4; j++) seg[i][j] = tmp[j];
    }
    calc += 32;
}

best4 find_lrg(int s, int e, int p, int ss, int se) {
    calc += 4;
    best4 res;
    int tmp[8];
    for (int i = 0; i < 4; i++) res.a[i] = 101234;
    if (s <= ss && se <= e) {
        for (int i = 0; i < 4; i++) res.a[i] = seg[p][i];
        return res;
    }
    else if (s > se || e < ss) {
        return res;
    }
    else {
        best4 a = find_lrg(s, e, p << 1, ss, (ss + se) >> 1);
        best4 b = find_lrg(s, e, (p << 1) + 1, ((ss + se) >> 1) + 1, se);
        for (int i = 0; i < 4; i++) tmp[i] = a.a[i];
        for (int i = 0; i < 4; i++) tmp[i + 4] = b.a[i];
        qsort(tmp, 8, sizeof(int), cmp2);
        for (int i = 0; i < 4; i++) res.a[i] = tmp[i];
        calc += 32;
        return res;
    }
}

void bfs(int n, int k, int x, int y) {
    int rn = rng[y];
    best4 lrg;
    vis[x][y] = 1;
    q.push(pair<int, int>(x, y));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        rn = rng[y];
        q.pop();

        if (y > 0 && !vis[x][y - 1]) {
            q.push(pair<int, int>(x, y - 1));
            vis[x][y - 1] = 1;
            dist[x][y - 1] = dist[x][y] + 1;
        }
        if (y < 30 && !vis[x][y + 1]) {
            q.push(pair<int, int>(x, y + 1));
            vis[x][y + 1] = 1;
            dist[x][y + 1] = dist[x][y] + 1;
        }

        lrg = find_lrg(lb(n, pts[x][0] - rn), ub(n, pts[x][0] + rn), 1, 0, SZ - 1);
        for (int i = 0; i < k; i++) {
            if (lrg.a[i] > 100000) break;
            if (lrg.a[i] == x && dist[x][y] < best[pts[x][1]]) best[pts[x][1]] = dist[x][y];
            if (!vis[lrg.a[i]][y]) {
                q.push(pair<int, int>(lrg.a[i], y));
                vis[lrg.a[i]][y] = 1;
                dist[lrg.a[i]][y] = dist[x][y] + 1;
            }
        }
        calc += 16;
    }
}

int main(void) {
    int n, k;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2020\\triptik\\data\\secret\\2000.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2020\\triptik\\data\\secret\\2000_t.out", "w", stdout);
    //stree* root = (stree*)calloc(1, sizeof(stree));
    //root->s = -INF, root->e = INF;
    rng[0] = 0, rng[1] = 1;
    for (int i = 2; i <= 30; i++) rng[i] = rng[i - 1] * 2;
    for (int i = 0; i < SZ * 2; i++) {
        for (int j = 0; j < 4; j++) seg[i][j] = 101234;
    }
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pts[i][0]);
        pts[i][1] = i;
        best[i] = INF;
    }
    qsort(pts, n + 1, sizeof(int) * 2, cmp1);
    for (int i = 0; i <= n; i++) {
        seg[SZ + i][0] = i;
    }
    seg_init();
    for (int i = 0; i <= n; i++) {
        if (pts[i][0] == 0) bfs(n, k, i, 1);
    }
    //printf("%d, %lld\n", ccc, calc);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", best[i] == INF ? -1 : best[i]);
    }
    return 0;
}